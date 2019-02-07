class Messwert(object):


    def __init__(self, line=None, temperatur=None):
        if temperatur is not None:
            self._parseBoth(line, temperatur)
        else:
            self._parseLine(line)


    def _parseLine(self, line):
        line = line.replace('"', "")
        line = line.split(",")
        self.zeitpunkt = line[0]
        self.temperatur = float(line[1])


    def _parseBoth(self, zeitpunkt, temperatur):
        self.zeitpunkt = zeitpunkt
        self.temperatur = float(temperatur)

    def __repr__(self):

        return "('%s', %s)" % (str(self.zeitpunkt), str(self.temperatur))

    def __str__(self):
        return "('%s', %s)" % (str(self.zeitpunkt), str(self.temperatur))

    def __eq__(self, other):
        return self.temperatur == other.temperatur \
                and self.zeitpunkt == other.zeitpunkt

    #<
    def __lt__(self, other):
        d = datetime.datetime.strptime(self.zeitpunkt[:-7], "%Y-%m-%d %H:%M:%S")
        o = datetime.datetime.strptime(other.zeitpunkt[:-7], "%Y-%m-%d %H:%M:%S")

        if d == o and self.temperatur < other.temperatur:
            return True
        else:
            return d < o

    
    def __hash__(self):
        return hash((self.temperatur, self.zeitpunkt))
