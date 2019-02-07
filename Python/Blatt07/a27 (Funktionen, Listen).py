#!user/bin/python3
# -*- coding: utf-8 -*-

def dreh(lst):
    "Rekursive Funktion die eine Liste umdreht"

    temp = 0
    if len(lst) == 0:
        return lst
    else:
        temp = lst[0]

        lst = dreh(lst[1:])
        lst.append(temp)
        return lst


if __name__ == "__main__":
    lst = list(range(1, 100))
    lst = [1, 2, 3, 4]
    print(dreh(lst))

    help(dreh)
