#include <stdio.h>
#include <string.h>
#include "list.h"



int main(int argc, char *argv[]){
    nodep liste = NULL;
    nodep listeCopy = NULL;
    int data0 = 0;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    int data4 = 4;

    
    liste = insertAt(liste, 0, data0);
    liste = insertAt(liste, 1, data1);
    liste = insertAt(liste, 2, data2);
    liste = insertAt(liste, 0, data3);
    liste = insertAt(liste, 3, data4);
    
    listeCopy = copyList(liste);
    listeCopy = deleteAt(listeCopy, 0);
    listeCopy = deleteAt(listeCopy, 3);

    liste = deleteAt(liste, 0);
    liste = deleteAt(liste, 3);
    liste = deleteList(liste);
    
          
    
    printList(liste);
    
    printf("Kopierte Liste: \n");
    
    printList(listeCopy);
    
    listeCopy = deleteList(listeCopy);

    

   
    
    return 0;
}
