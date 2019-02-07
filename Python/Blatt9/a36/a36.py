#!user/bin/python3

#aufsteigend sortierte Liste der Wohnorte aller Männer
print(sorted([y[4] for y in [x.strip().split(";")
                             for x in open("/Users/Josh/Dropbox/Uni/5. Semester/Programmieren3/programmieren3/Blatt9/a36/a36-bonz.txt").readlines()]
       if y[0] == "Herr"]))

#Summe der Gehälter aller Frauen
print(sum([int(y[3]) for y in [x.strip().split(";")
                               for x in open("/Users/Josh/Dropbox/Uni/5. Semester/Programmieren3/programmieren3/Blatt9/a36/a36-bonz.txt").readlines()]
       if y[0] == "Frau"]))


#den Wohnort der Person, die unter allen, deren Vorname mit 'J' beginnt am meisten verdient
print((sorted([z for z in[(y[3], y[4]) for y in [x.strip().split(";")
                              for x in open("/Users/Josh/Dropbox/Uni/5. Semester/Programmieren3/programmieren3/Blatt9/a36/a36-bonz.txt").readlines()]
       if y[2].startswith("J")]], reverse=True, key=lambda x: int(x[0]))[0])[1])


#Eine (inhaltlich natürlich nicht gerechtfertigte) Liste von gehaltsbezogenen Schmähungen für
# alle Personen mit Gehalt ab 100000 Euro in der Form “Anrede Nachname bekommt mehr, als er/sie verdient!”
# (Beispiel: “Herr Meier ist bekommt mehr, als er verdient!” oder “Frau Schmitz bekommt mehr, als sie verdient!”)
print([y[0] + " " + y[1] + " bekommt mehr als er verdient" if y[0] == "Herr" else y[0] + " " + y[1] + " bekommt mehr als sie verdient"  for y in [x.strip().split(";")
       for x in open("/Users/Josh/Dropbox/Uni/5. Semester/Programmieren3/programmieren3/Blatt9/a36/a36-bonz.txt").readlines()]
       if int(y[3]) >= 100000])
