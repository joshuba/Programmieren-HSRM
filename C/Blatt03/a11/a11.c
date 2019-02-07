#include <stdio.h>
#include <string.h>




void encrypt(char *abc, char *irj, char aktBuchstabe){
    char *abcPos = abc;
    char *irjPos = irj;
    
    if(aktBuchstabe >= 'a' && aktBuchstabe <= 'z'){
        while(*abcPos != aktBuchstabe){
        abcPos++;
        irjPos++;
    }
        putchar(*irjPos);
    }
  
       
    
}




int main(int argc, char *argv[]){
    char abc [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' ,'j', 'k', 'l' , 'm' ,'n' ,'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char irj [] = {'i', 'r', 'j', 'm', 'n', 'z', 'l', 't', 'a', 'c', 'o', 'g', 'd', 'e', 'k', 's', 'v', 'b', 'p', 'h', 'x', 'q', 'y', 'u', 'w', 'f'};
    char c ='0'; 
    
    if(strcmp(argv[1], "encrypt") == 0){
        
        while ((c = getchar()) != EOF){
               encrypt(abc, irj, c); 
            
               
        }
   
    }else if(strcmp(argv[1], "decrypt") == 0){

    }else{
        printf("Falsche eingabe");
    }
    

    return 0;
}
