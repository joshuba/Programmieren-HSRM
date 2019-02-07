#!user/bin/python3
#-*- coding: utf-8 -*-

def devocalize(s):
    "Diese Methode ist total"
    for ele in s:
        if(ele in ("aeiou")):
            s = s.replace(ele, "")
    return s




if __name__ == "__main__":
    print(devocalize("Das ist ein Baerenspass"))

    help(devocalize) #gibt den docstring in nicer ansicht auf dem terminal (nur da) aus