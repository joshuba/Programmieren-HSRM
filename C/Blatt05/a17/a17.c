#include <stdio.h>

void schreibbit(int z){
    int temp;
    int wort [32] = {0};
    int i = 0;
    
    
    while(z){
        temp = (z & 0x1);
        wort[i] = temp;
        z = z >> 1; /*Hole mittels maske den hintersten Bit wert*/
        i++;
        
    }
    for(i = 32; i>=0;i--){ /*32, da 4 Byte = 32 Bit */
        putchar(wort[i]+48);
    }
    printf("");
    
    
    
} 



int main(int argc, char *argv[]){
    
    union _test{
        int i [2];
        double d;
    }test;

    test.d = 3.5717178E-12;
    
        schreibbit(test.i[1]);
        schreibbit(test.i[0]);
        printf("\n");


    
    
    
    
    return 0;
}
