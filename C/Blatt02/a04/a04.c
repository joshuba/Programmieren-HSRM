#include <stdio.h>

int aktSpalte;
int aktZeile;


void printTabelle(int eingabe, int array [][9]){
    int i;
    int j;

    
    for(i = 0; i < eingabe; i++){
        for(j=0; j< eingabe; j++){
            if(array[i][j] != 0){
               printf("%2d ", array[i][j]); 
            }
            printf(" ");
        }
        printf("\n");
    }
}

void setzeWert(int eingabe, int array [][9], int zahl){
    if(zahl == 1){ /*Falls erste Zahl */
        aktZeile = eingabe / 2;
        aktSpalte = eingabe /2;
        array[aktZeile][aktSpalte] = 1;
    }else{/*Alle anderen Zahlen */
        aktZeile = (aktZeile +1) % eingabe;
        aktSpalte = (aktSpalte -1) % eingabe;
        if(aktSpalte == -1){ /*Falls die Spalte ueber die Grenze rutscht */
            aktSpalte = eingabe-1;
        }
        if(array[aktZeile][aktSpalte] == 0){ /*Wenn frei Setze aktZahl */
           array[aktZeile][aktSpalte] = zahl; 
        }else{ /*Ansonsten ruecke 2 runter */
            aktSpalte = aktSpalte + 1;
            if(aktSpalte == eingabe){ /*Alle anderen Zahlen */
                aktSpalte = 0;
            }
            aktZeile = (aktZeile +1) %eingabe;
            array[aktZeile][aktSpalte] = zahl;
        }
        
    }
     
}


void insertToTable(int eingabe, int array [][9]){
    int i;

    for(i = 1; i<= eingabe*eingabe; i++){
       setzeWert(eingabe, array, i);
    }

}



int main(void){
    int eingabe;
    int feld [11][11] = {0};
    
    
    printf("Gib eine gerade Zahl unter 10 ein\n");
    scanf("%d",&eingabe);
    
    insertToTable(eingabe, feld);
    printTabelle(eingabe, feld);
    
    
    
    return 0;
    
}
