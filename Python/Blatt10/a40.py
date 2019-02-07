#!user/bin/python

import datetime
from logging.config import listen


class Messreihe():

    def __init__(self, stringfolge = None):
        self.liste = []

        if stringfolge is not None:
            for line in stringfolge:
                m = Messwert(line)
                self.liste.append(m)

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
        line = line.replace('"', "")
        line = line.split(",")
        self.zeitpunkt = line[0]
        self.temperatur = float(line[1])


    def _parseBoth(self, zeitpunkt, temperatur):
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

    print(len(m)) #147873
    print(min(m, key=lambda Messwert: Messwert.temperatur))
    print(max(m, key=lambda Messwert: Messwert.temperatur))

    for ele in m:
        if ele.temperatur > 33.0:
            print(ele.zeitpunkt)


    counter = 0
    for ele in m['2017']:
        print(ele)

        if ele.temperatur > 26.0:
            counter += 1
            print(ele)
    print(counter)
    print(m["2017"])
    
    for i in m.getGenerator():
        print(i)
        

