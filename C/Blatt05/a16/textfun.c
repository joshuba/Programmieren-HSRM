#include <stdio.h>
#include "textfun.h"
#include <stdlib.h>
#include <string.h>

void addPair(const char *such, const char *ersetz){

        listEle new = malloc(sizeof(struct _listEle));
        strcpy(new -> suchWort, such);
        
        strcpy(new -> ersetzungsWort, ersetz);
        new -> next = NULL;
    
    
    if(wordList == NULL){ /*Falls Liste leer */
        wordList = new;
    }else{ /*Falls nicht lollicopter */
        listEle aktNode = wordList;
        while(aktNode->next){
            aktNode = aktNode -> next;
        }
        aktNode->next = new;
      
    }
}


void clearList(void){
    
    
}

char *find(const char *s){
    char *wordP1 = s;
    char *wordP2 = s;
    char *zensurP;
    
    listEle aktNode = wordList;
   while(*wordP1){ /*P1 navigiert durch das Wort */
        while(aktNode != NULL){ /*Iteriere durch alle Zensurwoerter */
           zensurP = aktNode -> suchWort;
           while(*zensurP == *wordP2 && *wordP2 != 0){ /*Iteriere durch aktuelles Zensurwort */
                   zensurP ++;
                   wordP2 ++;
           }
           if(*zensurP  == '\0'){ /*Wenn eine Stelle Weiter eine 0 steht, wurde das ganze wort gefunden */
               return wordP1;
           }
            wordP2 = wordP1;   
        
           
            aktNode = aktNode->next;
           
            
                    
        }    
            aktNode = wordList;
            wordP1 ++;
            wordP2 = wordP1;
        
    }
    
    return NULL;
}

int replaceAll(char *s){
    char neuesWort [200] ={0};
    char *newWort = neuesWort;
    
    char* p1 = s;
    char* n1 = neuesWort;
    char *aktErsetzung = NULL;
    
    listEle aktNode = wordList;
    char *zensWort;
    int suchwortLen = 0;
    int i = 0;
    int counter = 0;
    int newLen = 0;
    
    
    while(*p1 != NULL && *p1 != '\n'){ /*Bis die Eingabe durchlaufen ist */
        aktErsetzung = find(p1);
        
        while(p1 != aktErsetzung && *p1){ /*Durchlaufe Wort bis man auf Ersetzungswort stoesst und kopiere alle Buchstaben davor */
            *n1 = *p1;
            n1++;
            p1++;
        }
        if(p1 == aktErsetzung){ /*Wenn man auf Ersetzungswort gestossen ist */
            aktNode = wordList;
            while(aktNode != NULL){ /*Iteriere durch alle Zensurwoerter */
                zensWort = aktNode -> suchWort;
                while(*zensWort == *aktErsetzung){ /*Iteriere durch aktuelles Zensurwort */
                   zensWort ++;
                   aktErsetzung ++;
                }if(*zensWort == '\0'){ /*Wenn das richtige Wort in Wordlist gefunden wurde */
                    counter++;
                    suchwortLen = strlen(aktNode->suchWort);
                    aktErsetzung = aktNode -> ersetzungsWort;

                    while(*aktErsetzung){ /* Ersetze... */
                        *n1 = *aktErsetzung;
                        n1++;
                        aktErsetzung++;
                        
                    }
                    for(i = 0; i <suchwortLen; i++){ /*Schiebe p1 um das Suchwort weiter */
                        p1++;
                    }
                    aktNode = NULL;
    
                    
                }
                if(aktNode != NULL){
                        aktNode = aktNode -> next;
                }
                
            }
            
            
            
        }
    }
    

    n1++;
    *n1 = '\0';
    
    /*schreibe in 2 */
    while(*newWort){
        *s = *newWort;
        s++;
        newWort++;
    }
    *s = '\0';
    
    return counter;
}

