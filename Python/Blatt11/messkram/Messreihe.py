#!user/bin/python

import datetime
from logging.config import listen

def enum(iterable):
    i = -1
    for ele in iterable:
        i+=1
        yield(i, ele)


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
                assert type(ele) == Messwert

                self.liste.append(ele)

    def __add__(self, other):
        assert type(other) == Messreihe

        for ele in other.liste:
            if ele not in self.liste:
                self.liste.append(other)

    def __iter__(self):
        return MessreiheIterator(self.liste)

    def __getitem__(self, item):
        if type(item) == slice:
            self.liste = self.liste[item.start:item.stop:item.step]
            return self


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
    
    def addNew(self, other):
        assert type(other) == Messwert
        copy = self.liste[:] #copy
        
        sorted(copy, key=lambda x :datetime.datetime.strptime(x.zeitpunkt[:-7], "%Y-%m-%d %H:%M:%S"))
        
        if copy[len(copy)-1] < other:
            self.add(other)
            print("hat geklappt")
        else:
            raise MonotonieVerstossError("Wert ist kleiner als " + str((copy[len(copy)-1]).zeitpunkt))
       
        
        

class MonotonieVerstossError(ValueError):
    def __init__(self, message):

        # Call the base class constructor with the parameters it needs
        super(MonotonieVerstossError, self).__init__(message) 


    

class MessreiheIterator(Messreihe):

    def __init__(self, liste):
        self.pos = -1
        self.liste = liste

    def __next__(self):
        self.pos += 1
        if self.pos >= len(self.liste):
            raise StopIteration
        return self.liste[self.pos]


class MessreiheGenIter(Messreihe):
    
    def __init__(self, liste):
        self.pos = -1
        self.liste = liste
        
    def __iter__(self):
        while True:
            self.pos += 1
            yield self.liste[self.pos]












if __name__ == '__main__':
    m = Messreihe(open("messwerte.csv"))
    m2 = Messreihe(open("messwerte.csv"))
    
    
    #testmesswert = Messwert("2018-01-10 14:15:01.570572",21.4375)

    
    
    #print(m + m2)


    #for nr, messwert in enum(m):
     #   print(nr, "->", messwert)
    
    try:  
        mr = Messreihe(open("messwerte.csv"))[:10]
        mr.addNew(mr[0])
    except MonotonieVerstossError:
        print("ich fick dei Kind")
    
    
    
        

