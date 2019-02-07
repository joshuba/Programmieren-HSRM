#include <stdio.h>

int main(void){
    int zahl;
    
    printf("Gib eine Zahl ein: ");
    scanf("%d", &zahl);
    
    
    while(zahl/1000){
        printf("M");
        zahl = zahl - 1000;
    }     
    
    while(zahl/500){
        printf("D");
        zahl = zahl - 500;
    }    
    
    while(zahl/100){
        printf("C");
        zahl = zahl - 100;
    }
    
    while(zahl/50){
        printf("L");
        zahl = zahl - 50;
    }
    
    while(zahl/10){
        printf("X");
        zahl = zahl - 10;
    }
    
    while(zahl/5){
        printf("V");
        zahl = zahl - 5;
    }
    
    while(zahl/1){
        printf("I");
        zahl = zahl - 1;
    }
    
    
    return 0;
    
    
}
