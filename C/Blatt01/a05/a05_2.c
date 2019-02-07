#include <stdio.h>
#include <string.h>

/*ROT13 mit Einlesen aus Datei*/
int main(void){
    char aktChar;
    char c;
    
    
    
    while((c = getchar())!=EOF){
        
          aktChar = c;
        
        if(aktChar >= 'A' && aktChar <= 'Z'){
            putchar((((aktChar-65)+13)%26)+65);
            
        }else if(aktChar >= 'a' && aktChar <= 'z'){
            putchar((((aktChar-97)+13)%26)+97);
            
        }else{
            putchar(aktChar);
        }
        
                
    }
    

    
        
    return 0;
}
