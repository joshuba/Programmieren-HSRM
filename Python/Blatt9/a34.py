#!user/bin/python3

import sys

irj = "irjmnzltacogdeksvbphxqyuwf"
abc = "abcdefghijklmnopqrstuvwxyz"


print("".join(["abcdefghijklmnopqrstuvwxyz"["irjmnzltacogdeksvbphxqyuwf".index(y)] #setze index des buchstabens in crypt ins alphabet
               if y in "irjmnzltacogdeksvbphxqyuwf" else y #führe obere zeile aus falls zeichen in crypt ist ansonsten übernehme zeichen
               for y in open(sys.argv[1]).read().lower()])) #lese jedes Zeichen aus textdatei







