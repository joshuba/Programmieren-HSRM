#include <stdio.h>

int main(void){
    double x;
    double w;
    double temp;
    
    printf("Bitte gib eine Zahl ein\n");
    scanf("%lf", &x);
    
    w = (1+x)/2;
    temp = x;

    
    while(temp-w > 0.0000001){
        temp = w;
        w=(w+(x/w))/2;
    }
    
    printf("%.4f\n",w);

    
    return 0;
}
