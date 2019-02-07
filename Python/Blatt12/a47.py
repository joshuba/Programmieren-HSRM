#!user/bin/python3

import re

datumPattern = re.compile(r'[12][0-9].([0][1-9]|[1][0-2]).\d{4}')
datum = datumPattern.match('12.02.2012')
print(datum)


euroPattern = re.compile(r'([1-9][0-9]?[0-9]?)((\.\d{3})*)(,\d{2})?( EUR)?')
euro = euroPattern.match('444.444.444.232 EUR')
print(euro)


telefonPattern = re.compile(r'((\+[1-9][0-9][0-9]? [1-9][0-9][0-9]*)|([0-9]{2}))([ -\/]?[0-9]{2}[0-9]*)*')
telefon = telefonPattern.match('01-34-2342 34')
print(telefon)



