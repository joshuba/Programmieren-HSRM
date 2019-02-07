#!user/bin/python

import datetime
from logging.config import listen
import re


class Messreihe():

    def __init__(self, stringfolge = None):
        self.liste = []

        if stringfolge is not None:
            i = 0
            for line in stringfolge:
                i+=1
                try:
                    m = Messwert(line)
                    self.liste.append(m)
                except ValueError:
                    print("Datei ist Fehlerhaft, Zeile: "+ str(i) + " " +  line)

    def __len__(self):
        return len(self.liste)

    def add(self, *other):
        for ele in other:
            if ele not in self.liste:
                self.liste.append(ele)

    def __add__(self, other):
        if type(other) == Messreihe:
            for ele in other.liste:
                if ele not in self.liste:
                    self.liste.append(other)

    def __iter__(self):
        return MessreiheIterator(self.liste)

    def __getitem__(self, item):
        if type(item) == slice:
            return self.liste[item.start:item.stop:item.step]


        elif type(item) == int:
            return self.liste[item]

        elif type(item) == str:
            new = Messreihe()
            for ele in self.liste:
                if str(ele.zeitpunkt[:len(item)]) == item:
                    new.add(ele)

            return new
        
    def getGenerator(self):
        return MessreiheGenIter(self.liste)
        
    




class MessreiheIterator():

    def __init__(self, liste):
        self.pos = -1
        self.liste = liste

    def __next__(self):
        self.pos += 1
        if self.pos >= len(self.liste):
            raise StopIteration
        return self.liste[self.pos]


class MessreiheGenIter():
    
    def __init__(self, liste):
        self.pos = -1
        self.liste = liste
        
    def __iter__(self):
        while True:
            self.pos += 1
            yield self.liste[self.pos]



class Messwert(object):


    def __init__(self, line=None, temperatur=None):
        
        if temperatur is not None:
            self._parseBoth(line, temperatur)
        else:
            self._parseLine(line)


    def _parseLine(self, line):
        #"2018-01-10 14:00:01.2586",22.0
        #"2018-01-10 14:15:01.570572",21.4375
        pattern = re.compile(r'\"[1-2][0-9]{3}-([0][1-9]|[1][0-2])-(0[1-9]|[12][0-9]|3[01]) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9]).[0-9]*\",[0-9]{2}.[0-9]+')
        
        if pattern.match(line) is None:
            raise ValueError("EingabeString des Messwerts entspricht nicht dem richtigen Format")
        else:
            line = line.replace('"', "")
            line = line.split(",")
            self.zeitpunkt = line[0]
            self.temperatur = float(line[1])
        


    def _parseBoth(self, zeitpunkt, temperatur):
        pattern = re.compile(r'[1-2][0-9]{3}-([0][1-9]|[1][0-2])-(0[1-9]|[12][0-9]|3[01]) ([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9]).[0-9]*')
        if pattern.match(zeitpunkt) is None:
            raise ValueError("Zeitpunktstring ist fehlerhaft")
        else:
            self.zeitpunkt = zeitpunkt
            self.temperatur = float(temperatur)
        

    def __repr__(self):

        return "('%s', %s)" % (str(self.zeitpunkt), str(self.temperatur))

    def __str__(self):
        return "('%s', %s)" % (str(self.zeitpunkt), str(self.temperatur))

    def __eq__(self, other):
        return self.temperatur == other.temperatur \
                and self.zeitpunkt == other.zeitpunkt

    #<
    def __lt__(self, other):
        d = datetime.datetime.strptime(self.zeitpunkt[:-5], "%Y-%m-%d %H:%M:%S")
        o = datetime.datetime.strptime(other.zeitpunkt[:-5], "%Y-%m-%d %H:%M:%S")

        if d == o and self.temperatur < other.temperatur:
            return True
        else:
            return d < o

    
    def __hash__(self):
        return hash((self.temperatur, self.zeitpunkt))










if __name__ == '__main__':
    m = Messreihe(open("messwerte.csv"))
    #m1 = Messwert('"2018-01-10 14:00:01.2586",22.0')
    
    

