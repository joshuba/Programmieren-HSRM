#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum{ LEN =200};

void machSexyZensur(char *wort, int argc, char *argv[] ){
    char *wordP1 = wort;
    char *wordP2 = wort;
    char *zensurP;
    int i;
    int j;
    
    while(*wordP1){ /*P1 navigiert durch das Wort */
        for(i = 1; i< argc; i++){ /*Iteriere durch alle Zensurwoerter */
           zensurP = argv[i];
           while(*zensurP == *wordP2 && *wordP2 != 0){ /*Iteriere durch aktuelles Zensurwort */
                   zensurP ++;
                   wordP2 ++;
           }
           if(*zensurP  == '\0'){ /*Wenn eine Stelle Weiter eine 0 steht, wurde das ganze wort gefunden */
               for(j=1; j<(wordP2 -wordP1); j++){
                   wordP1 [j] = '*';
               }
               wordP1 = wordP2;
           }
            wordP2 = wordP1;                
        }    
            wordP1 ++;
            wordP2 = wordP1;
        
    }
    printf("%s", wort);
    printf(" ");
    
    
    
}


int main(int argc, char *argv[]){
    char eingabe [LEN];
    while(scanf("%s", eingabe) != EOF){
        machSexyZensur(eingabe, argc, argv);
        
    }
}
