#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


void printList(nodep list){
    if(list == NULL){
        printf("Ausgabe: Liste ist leer\n");
    }else {
        nodep aktNode = list;
        
        while(aktNode != NULL){
            printf("%p\n", aktNode -> data);
            aktNode = aktNode -> next;
        }
     }
}

nodep insertAt(nodep list, int pos, void *data){
    /*Bestimme Listenlaenge */
    nodep aktPos = list;
    int laenge = 1;
    int i = 0;
    
    if(list == NULL){ /*Liste leer */
        if(pos != 0){
            printf("Du willst an %d einfuegen, die Liste ist aber leer\n", pos);
            return list;
        }else {/*Falls erstes Objekt eingefuegt wird */
            nodep new = malloc(sizeof(nodep));
            new -> data = data;
            return new;
        }
    } 
        
    /*Laenge bestimmen */
    aktPos = list;
     do{
        if(aktPos -> next != NULL){
            aktPos = aktPos -> next;
            laenge ++;
           }
        }while(aktPos->next != NULL);
    
    
    
    /*Falls Pos zu hoch ist */
    if(pos > laenge){
        printf("Du willst an %d einfuegen, die Liste ist aber nur %d Stellen lang\n", pos, laenge);
        return list;
    }else {
        nodep new = malloc(sizeof(nodep));
        aktPos = list;
        if(pos < 0){
            pos = laenge + (pos +1);
        }
        

        for(i = 0; i<pos-1; i++){ /*Suche Position, an der eingefuegt werden soll bzw eine davor */
            aktPos = aktPos -> next;
        }
        
        if(pos == laenge){ /*Am ende einfuegen */
            aktPos -> next = new;
            new -> data = data;
            new -> prev = aktPos;
            return list;
        }else if(pos > 0 && pos < laenge){ /*Mitten drin einfuegen */
            new -> data = data;
            aktPos -> next -> prev = new;
            new -> next = aktPos -> next;
            new -> prev = aktPos;
            aktPos -> next = new;
            return list;
        }else if(pos == 0){/*Am Anfang einfuegen */
            aktPos -> prev = new;
            new -> next = aktPos;
            new -> data = data;
            return new;
        }
        
                
        return list;
        
    }

}

nodep deleteAt(nodep list, int pos){
      /*Bestimme Listenlaenge */
    nodep aktPos = list;
    int laenge = 1;
    int i = 0;
    
    if(list == NULL){ /*Liste leer */
        printf("Du willst an %d loeschen, die Liste ist aber leer\n", pos);
        return list;
    } 
        
    /*Laenge bestimmen */
    aktPos = list;
     do{
        if(aktPos -> next != NULL){
            aktPos = aktPos -> next;
            laenge ++;
           }
        }while(aktPos->next != NULL);
    
    
    
    /*Falls Pos zu hoch ist */
    if(pos > laenge){
        printf("Du willst an %d loeschen, die Liste ist aber nur %d Stellen lang\n", pos, laenge);
        return list;
    }else {
        aktPos = list;
        if(pos < 0){ /* Falls der Wert negativ ist */
            pos = laenge + (pos +1);
        }
        

        for(i = 0; i<pos; i++){ /*Suche Position, an der geloescht werden soll */
            aktPos = aktPos -> next;
        }
        
        if(pos == laenge-1){ /*Am ende loeschen */
            aktPos->prev -> next = NULL;
            free(aktPos);
            return list;
        }else if(pos > 0 && pos < laenge){ /*Mitten drin loeschen */
            aktPos -> next -> prev = aktPos -> prev;
            aktPos -> prev -> next = aktPos -> next;
            free(aktPos);
            return list;
        }else if(pos == 0){/*Am Anfang loeschen */
            list = aktPos -> next;
            list -> prev = NULL;
            free(aktPos);
            return list;
        }
        
                
        return list;
        
    }

}

nodep copyList(nodep list){
    nodep copy;
    if(list == NULL){
        printf("Leere Liste kopiert");
        return NULL;
    }else{
        nodep aktposALT = list;
        nodep aktposNEU = NULL;
        
        
        /* Iteriere durch Liste und kopiere stueck fuer stueck */
        while(aktposALT != NULL){
            if(aktposALT -> prev == NULL){ /*Falls Anfang */
                nodep copyNode = malloc(sizeof(nodep));
                copy = copyNode;
                copyNode -> prev = NULL;
                copyNode -> data = aktposALT -> data;
                aktposNEU = copyNode;
                aktposALT = aktposALT -> next;
            }else if(aktposNEU != NULL){ /*Ansonsten */
                nodep copyNode1 = malloc(sizeof(nodep));
                copyNode1 -> prev = aktposNEU;
                copyNode1 -> data = aktposALT -> data;
                aktposNEU -> next = copyNode1;
                aktposNEU = copyNode1;
                aktposALT = aktposALT -> next;
                }
        }
      
    }
    
        return copy;
}

nodep deleteList(nodep list){
    nodep aktpos = list;
    while(list != NULL){
        list = list -> next;
        free(aktpos);
        aktpos = list;
    }
    
        return list;

}
