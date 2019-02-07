#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


typedef struct _person *PersPointer;

struct _person{
    char name[25];
    PersPointer next;
    PersPointer prev;
}person;




int main(int argc, char *argv[]){
    int reimzahl = argc-1;
    PersPointer letztePerson;
    PersPointer start;
    PersPointer aktPerson;
    PersPointer temp;
    int counter = 0;
    char aktName[25];
    int i;

    
    /*Einlesevorgang */
    while(scanf("%s", aktName) != EOF){

        /*Startperson */
        if(counter == 0){
            start = malloc(sizeof(person));
            strcpy(start->name, aktName); 
            letztePerson = start;
            counter++;
            
        /*Alle anderen */
        }else {
            PersPointer neuePerson = malloc(sizeof(person));
            strcpy(neuePerson->name, aktName); 
            letztePerson->next = neuePerson;
            neuePerson->prev = letztePerson;
            letztePerson = neuePerson;
            counter ++;
        }
        
    }
    /*Ende mit Anfang verbinden */
    letztePerson->next = start;
    start->prev = letztePerson;
    aktPerson = start;
    
    

    /*Abzaehlreim */
    while(counter){
        for(i=reimzahl-1; i>0;i--){
            aktPerson = aktPerson -> next;
            
        }
        /*Rausschmeissen und neu verbinden */
            temp = aktPerson;
            aktPerson->prev->next = aktPerson->next;
            aktPerson -> next -> prev = aktPerson ->prev;
            aktPerson = aktPerson -> next;
            printf("%s\n", temp->name);

            free(temp);

        counter--;
    }
    
        
        
        
        
    
        
        
        
           return 0;
 
    }
    
