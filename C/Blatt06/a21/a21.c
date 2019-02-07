#include <stdio.h>
#include <stdlib.h>

struct ele {
      char codezeichen = '0'; /* Zeichen im verschluesselten Text */
      int anzahl = 0;       /* abs. Haeufigkeit dieses Zeichens */
};








void readFile(char *dateiname, struct ele crypt[26]){
    FILE *fp;
    char *line = malloc(255* sizeof(char));
    char *aktline = line;
    int i = 0;
    
    fp = fopen(dateiname, "rt");
    
    if(fp == NULL){
        fprintf(stderr, "Fehler beim lesen der Datei");
    }else{
        while(!feof(fp)) { 
            fgets(line, 255, fp);
    
            while(*aktline){
                printf("%c", *aktline);
                aktline++;
                for(i = 0; i<26; i++){
                    /*TODO: Iteriere durch crypt bis Buchstabe gefunden wurde, ansonsten erstelle neuen., erhoehe zahl */
                    if (crypt[i]->codezeichen == *aktline){
                        cypt[i] -> anzahl = anzahl +=1;
                    }
                    
                }
                
            }
            aktline = line;
            
            
            
                

                    
          
        
        
                
         
   }
        printf("Done\n");

        
    }
    fclose(fp);
    free(line);
 
}



int main(int argc, char* argv[]){
    struct ele crypt[26];
    readFile("a21-raeuberbrief.enc", crypt);
    
    
    
    return 0; 
    
    
}
