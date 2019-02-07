#!user/bin/python3

import fileinput
import re

umdrehen = lambda x: print(re.sub(r'\w*',lambda y: y.group()[::-1], x))
    

for line in fileinput.input():
    
    umdrehen(line)


   

