#!usr/bin/python3
# -*- coding: utf-8 -*-

PATH = "/Users/Josh/Dropbox/Uni/5. Semester/Programmieren3/programmieren3/Blatt8/a32 - fahrzeiten/a32-fahrzeiten.txt"

def ankunft(linie, start, ziel):
    if(start == ziel):
        return (0, [start   ])


    with open(PATH) as file:
        a = file.readlines()
        dic = {}
        linieListe = []
        for ele in a:
            ele = ele.strip("\n") #lösche Umbrüche
            ele = ele.split(";") #erstelle Liste in Liste

            if ele[0] == linie: #ffalls buslinie
                dic[ele[1]] = [ele[2], ele[3]] #dic k:Starthalte / v:[Ziel, zeit]


        haltestellen = []
        zeit = 0

        aktHalte = start


        while aktHalte != ziel: #für alle Haltestellen der Linie
            haltestellen.append(aktHalte)

            if(aktHalte in dic.keys()): #dass die Endhalte nicht abgefragt wird
                zeit += int(dic[aktHalte][1])
                aktHalte = dic[aktHalte][0]
                haltestellen.append(aktHalte)
            else:
                break;



        return (zeit, haltestellen)











print(ankunft("Bus6", "Nordfriedhof", "Münsterplatz"))
