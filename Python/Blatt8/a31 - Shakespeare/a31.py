#!user/bin/python3
# -*- coding: utf-8 -*-


import sys

arg = sys.argv


def count_words(name):
    """"Zählt die Wörter einer Textdatei, ohne Groß/Kleinschreibung zu beachten"""
    dic = {}
    with open(name) as f:
        f = f.read().split()



        for word in f:
            if word.strip() == 'ACT I':
                continue



            if word not in dic:
                dic[word] = 1
            else:
                dic[word] += 1
    return dic


def count_chars(name):
    """"Zählt die Buchstaben einer Textdatei, ohne Groß/Kleinschreibung zu beachten"""
    dic = {}
    with open(name) as f:
        f = list(f.read())

        for char in f:
            if char != "\n":
                char = char.lower()

                if char not in dic:
                    dic[char] = 1
                else:
                    dic[char] += 1
    return dic


def twentyFiveMostUsed(dic):
    for w in sorted(dic, key=dic.get, reverse=True)[0:25]:
            print(w, "(%s)"% dic[w])











path = "/Users/Josh/Dropbox/Uni/5. Semester/Programmieren3/programmieren3/Blatt8/a31 - Shakespeare/"
dateiname = "a31-midsummernightsdream.txt"


twentyFiveMostUsed(count_words(path + dateiname))
twentyFiveMostUsed(count_chars(path + dateiname))


