#!user/bin/python3
# -*- coding: utf-8 -*-


def ggTn(x, y):
    "Naiver Rekursiver Algorithmus"
    if x == y:
        return x

    if x > y:
        return ggTn(x-y, y)
    elif y > x:
        return ggTn(y-x, x)



def ggTe(x, y):
    "Effizienterer Rekursiver Algorithmus"

    if x > y and x % y != 0:
        return ggTe(x % y, y)
    elif y > x and y % x != 0:
        return ggTe(y % x, x)
    else:
        return x if x < y else y


def ggTi(x, y):
    "Iterativer Algorithmus"
    while(x != 0 and y != 0):
        if x > y:
            x = x % y
        elif y > x:
            y = y % x

    return x if x > y else y


def ggTl(*a):
    "Rechnet den GGT einer beliebigen Sequenz aus"
    x = 0
    a = list(a)
    for ele in range(0, len(a)-1):
            a[ele+1] = ggTe(a[ele], a[ele+1])
    return(a[len(a)-1])








#print(ggTn(90, 55))
#print(ggTe(90, 55))
#print(ggTi(55, 90))
print(ggTl(90, 55, 51, 90, 50, 30, 20, 10))

summe = 0
anzahl = 0
with open("/Users/Josh/Dropbox/Uni/5. Semester/Programmieren3/programmieren3/Blatt8/a30 - ggT-ggts.dat") as f:
    lines = f.readlines()
    for i in range(0, len(lines), 2):
        a = int(lines[i])
        b = int(lines[i+1])
        summe += ggTi(a, b)
        anzahl += 1

    print("Durchschnitt:", summe/anzahl)



