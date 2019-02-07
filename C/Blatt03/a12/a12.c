#include <stdio.h>
#include <ctype.h>
#include <string.h>

char tabelle(char c){
    c = toupper(c);
    switch(c){
        case 'B': case 'F': case'P': case'V': return '1'; break;
        case 'C': case 'G': case'J': case'K': case'Q': case'S':case'X':case'Z': return '2'; break;
        case 'D': case 'T': return '3'; break;
        case 'L': return '4'; break;
        case 'M': case 'N': return '5'; break;
        case 'R': return '6'; break;
        default: return '0'; break;
    }
}

 
void soundex(const char s[], char res[]){
    char aktBuchstabe;
    char *ausgabe = res;
    int counter = 1;

    /* 1. Erster Buchstabe */
    res[0] = toupper(s[0]);
    s++;
    res++;
    
    /* Tabellenzuordnung */
    while(*s){
        aktBuchstabe = tabelle(*s);
        if(aktBuchstabe != *(res-1) && aktBuchstabe != '0' && counter != 6){
            *res = aktBuchstabe;
            res++;
            counter++;
        }
        s++;
    }
    
    /* Falls Rest mit 0en fuellen */
    while(counter < 6){
        *res = '0';
        res++;
        counter ++;
        
    }

    /* 0 Terminator */
    res++;
    *res = '\0';
    
    

    /* Ausgabe */
    printf("%s\n", ausgabe);
    
    
    /* Zu */
    while(*ausgabe){
        *ausgabe = 0;
        ausgabe++;
    }
    
     
 }
 
 
 
int main(void){
     const char eingabe [100] = {0};
     char res[7] = {0};
     
     while((scanf("%s", eingabe))!= EOF){
         soundex(eingabe, res);
         
     }
     
     return 0;
 }
