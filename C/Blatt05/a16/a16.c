#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "textfun.h"



int main(int argc, char *argv[]){
    /*Einlesen der Woerter */
    int i;
    char *suchwort;
    char *ersatzwort;
    size_t buffsize = 200;
    char *buffer;
    int anzahl;
    
    
    buffer = (char *)malloc(buffsize *sizeof(char));
    
    /*Lese alle Woerter ein */
    for(i = 1; i<argc; i++){
        suchwort = strtok(argv[i], "=");
        ersatzwort = strtok(NULL, "=");
        addPair(suchwort, ersatzwort);
        
        printf("SUCHWORT: %s\n", suchwort);
        printf("Ersatzwort: %s\n", ersatzwort);
        printf("\n");   
    }
    
    
    /*Lese Satz ein */
    
    while(getline(&buffer, &buffsize, stdin) != EOF){
        anzahl = replaceAll(buffer); 
        printf("%s\n", buffer); 
        printf("%d Ersetzungen\n", anzahl);
        
        
    }
    
    return 0;
}
