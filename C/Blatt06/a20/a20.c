#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "textfun.h"





int main(int argc, char *argv[]){
    int i;
    char *suchwort;
    char *ersatzwort;
    size_t buffsize = 200;
    char *buffer;
    int anzahl;
    
    if(argc > 1){ /*Falls Regeln uebergeben werden -> Speichern am ende */
        printf("\nRegeln über Kommandozeile mitgegeben ...\n");
        /*Lese alle Woerter ein */
        for(i = 1; i<argc; i++){
        suchwort = strtok(argv[i], "=");
        ersatzwort = strtok(NULL, "=");
        addPair(suchwort, ersatzwort);
        
        printf("  %s -> ", suchwort);
        printf("%s\n", ersatzwort);
    }
    
    }else { /*Falls nicht -> Lese Regeln aus Datei -> Kein Speichern am Ende */
        printf("\nLese Regeln aus Datei ...\n");
        leseRegelnAusDatei("glogomir.txt");
    }
    
    buffer = (char *)malloc(buffsize *sizeof(char));
    
    
    
    
    /*Lese Satz ein */
    
    while(getline(&buffer, &buffsize, stdin) != EOF){
        anzahl = replaceAll(buffer); 
        printf("%s\n", buffer); 
        printf("%d Ersetzungen\n", anzahl);
        
        
    }
    
    if(argc > 1){ /*Abspeichern falls Regeln mitgegeben wurden */
        printf("\nSchreibe Regeln in Datei ...\n");
        schreibeRegelnInDatei("glogomir.txt");
    }
    free(buffer);
    
    
    
    return 0;
}
