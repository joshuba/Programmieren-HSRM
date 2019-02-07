#include <stdio.h>


void selectionSort(int *array, int laenge){
    int i = 0;
    int j = 0;
    int aktzahl;
    int aktKleinste;
    int swap;

    /*Durchlaufe alle Zahlen */
    for(i=0; i<laenge; i++){
        aktzahl = array[i];
        aktKleinste = aktzahl;
        for(j=i+1; j<laenge; j++){
            if(array[j] < aktKleinste){
                aktKleinste = array[j];
                swap = j;
            }
            
        }
        /*Tausche falls die kleinste Zahl kleiner als Aktzahl ist */
        if(aktKleinste < aktzahl){
            array[swap] = array[i];
            array[i] = aktKleinste;
        }
    }
    
    
}


int main(void){
    int c = 0;
    int zahlen [20] = {0};
    int anzahl = 0;
    int i;
   
    
    
    while(scanf("%d", &c) != EOF){
        zahlen[anzahl] = c;
        anzahl++;
    }
    
    selectionSort(zahlen, anzahl);
    
    /*Ausgabe des Arrays*/
    for(i=0;i<anzahl;i++){
        printf("%06d\n", zahlen[i]);
    }
    
    return 0;
}
