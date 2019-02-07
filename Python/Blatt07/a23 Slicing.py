#user/bin/python3
#-*- coding: utf-8 -*-

l = list(range(0,101))

#extrahieren Sie die ersten 10 Zahlen
print(l[:10])

#die letzten 10 Zahlen
print(l[-10:])

#jede 10. Zahl (beginnend mit 0)
print(l[::10])

#die mittlere Zahl
print(l[len((l)) // 2])


#jede dritte Zahl, aber davon! nicht die ersten vier und nicht die letzten fünf
print(l[::3][4:-5])