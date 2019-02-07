#!user/bin/python3

import re
import socket
from audioop import reverse

def ipCounter(path):
    'returns a dic {"hs-rm.de":anzahl ....}'
    
    dic = {}
    finaldic = {}
    
    with open(path) as file:
        file = file.readlines()
        ipPattern = re.compile(r'\d{1,3}\.\d{2,3}\.\d{2,3}\.\d{1,3}') #extrahiere IP aus ganzer Zeile
        hostPattern = re.compile(r'(\w|-)*\.(de|com|net)') #extrahiere die Endung (Domain)
        
        #erstelle Dic mit allen Zugriffen + ip adresse
        for line in file:
            if ipPattern.search(line):
                ip = ipPattern.search(line).group() #pure IP als String
                if ip not in dic:
                    dic[ip] = 0
                else:
                    dic[ip] = dic.get(ip)+1
                    
                    
    #tausche ip adressen mit Domain aus (Falls vorhanden)              
    for ip in dic.keys():
        try:
            host = hostPattern.search((socket.gethostbyaddr(ip)[0])).group()
            finaldic[host] = dic.get(ip)
        except:
            pass
            
            
    return finaldic
    


def accessCounter(path):
    'returns a dic {"00:00-00:59":counter, "1":counter ...}'
    
    dic = {}
    with open(path) as file:
        file = file.readlines()
        datum = re.compile(r'\[\d{2}.\w{3}.\d{4}:(?P<stunde>\d{2}):(?P<minute>\d{2}):\d{2} \+\d{4}\]')
        lineCounter = 0
        
        #erstelle dic mit den Stunden und den Zugriffstzahlen
        for line in file:
            lineCounter +=1

            if datum.search(line):
                stunde = datum.search(line).group("stunde")
                if stunde not in dic:
                    dic[stunde] = 0
                else:
                    dic[stunde] = dic.get(stunde)+1
                
    #ersetze Zugriffe durch prozentuale Zugriffe
    for ele in dic:
        dic[ele] = round(((int(dic.get(ele))/lineCounter)*100),2)
    return dic


def picCounter(path):
    'returns a dic {"jpg":counter, "png":counter, "gif": counter}'
    dic = {}
       
    with open(path) as file:
        file = file.readlines()
        
        bilder = re.compile('\"GET (\/\S*)*.(?P<endung>(jpg|png|gif))')
        
        
        for line in file:
            if bilder.search(line):
                endung = bilder.search(line).group("endung")                
                if endung not in dic:
                    dic[endung] = 0
                else:
                    dic[endung] = dic.get(endung)+1
    return dic
                
  
#Anzahl der Bilder
print(picCounter("access.log"))

#zugriffszeiten pro stunde in prozent
access = accessCounter("access.log")
for key in sorted(access):
    print("%s:00-%s:59: %s" % (key,key, access[key]) + "%")

#anzahl der Zugriffe von jeweiligem Host
host = ipCounter("access.log")
for key in sorted(host, key =host.get, reverse=True):
    print("%s %s"%(host[key], key))
