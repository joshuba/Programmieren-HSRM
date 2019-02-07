#include <stdio.h>

void schreibbit(unsigned z){
    int temp;
    int wort [16] = {0};
    int i = 0;
    
    
    while(z){
        temp = (z & 0x1);
        wort[i] = temp;
        z = z >> 1; /*Hole mittels maske den hintersten Bit wert*/
        i++;
        
    }
    for(i = 16; i>=0;i--){
        putchar(wort[i]+48);
    }
    printf("\n");
    
    
    
} 

unsigned liesbit(void){
    /*Liest die Bitzahl als Int ein und gibt die Dezimalzahl als int zurueck*/
    unsigned eingabe;
    unsigned ausgabe = 0;
    int temp;
    int counter = 0;

    
    scanf("%u", &eingabe);
    
    while(eingabe){
        temp = eingabe%10; /*letzte stelle*/
        
        if(temp == 1){
            ausgabe = ausgabe | (0x1 << counter); /*Schiebe alle 1er an ihre stelle*/

        }
        eingabe = eingabe/10;
    
        counter++;
    }
    
    return ausgabe;
}



int main(void){
    unsigned a = liesbit();
    unsigned b = liesbit();
    
    
    printf("a & b = ");
    schreibbit(a & b);
    printf("a | b = ");
    schreibbit(a | b);
    printf("a ^ b = ");
    schreibbit(a ^ b);

    return 0;
    
}
