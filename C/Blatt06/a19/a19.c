#include <stdio.h>
#include <math.h>

double regula(double x1, double x2, double (*f)(double)){
    
    double xs = (x1-f(x1)) * ((x2-x1)/(f(x2)-f(x1))); /*Sekantenverfahren*/
        
    printf("First: %f\n", xs);
    
    while(fabs(f(xs)) > 1.0e-6){ /*Fabs betragfunktion fuer double */
        printf("xs aktuell: %f", xs);
        
        if((xs >= 0 && f(x1 >= 0)) || (((xs <0) && (f(x1 < 0))))){ /*Wenn Vorzeichen gleich ist*/
            xs = xs-f(xs) * ((x2-xs)/(f(x2)-f(xs))); /*Sekantenverfahren*/
            printf("oben %f\n", xs);

        }else{
            xs = x1-f(x1) * ((xs-x1)/(f(xs)-f(x1))); /*Sekantenverfahren*/
            printf("unten %f\n", xs);

        }
    }
    
    return xs;
    
}


double f1(double x){
    return (x*x)-9;
}

double f2(double x){
    return (((1.0/6.0)*(x*x*x))-((1.0/2.0)*x*x) -(1.0/3.0));
}

double f3(double x){
    return (x*x)-2;
}


int main(void){
        
    double (*function) (double);
    double x1 = 3;
    double x2 = 4; 
    
    function = f2;
    

    printf("Ergebnis: %f", regula(x1, x2, function));

    return 0;
}
