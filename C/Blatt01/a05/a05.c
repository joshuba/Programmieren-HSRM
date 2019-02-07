#include <stdio.h>
#include <string.h>

/*ROT13 mit eigener Eingabe*/
int main(void){
    char eingabe [255]; 
    char aktChar;
    int i;
    int len;
    
    printf("Geben Sie den zu verschlüsselnden Text ein\n");
    fgets(eingabe, 255, stdin);
    
    /* StrLen bestimmen */
    len = strlen(eingabe)-1;
    
    
    for(i = 0; i< len;i++){
        aktChar = eingabe[i];
        
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
