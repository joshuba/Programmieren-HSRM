#!user/bin/python3


l = "eniastruhdlcmogkwbzfvpjxyq"
text = ""





# hinten muss eine liste der häufigkeiten rein
print(dict(map(lambda k, v: (k, v), open("a21-raeuberbrief.enc").read().strip(),
               range(100))))