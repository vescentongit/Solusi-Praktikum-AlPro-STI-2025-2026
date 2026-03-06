#include <stdio.h>
#include <math.h>

int checkEqual(float a, float b, float c){
    float AB = fabs(a-b);
    float AC = fabs(a-c);
    float BC = fabs(b-c);

    if(AB < 0.001 && AC < 0.001 && BC < 0.001){
        return 3;
    }
    else if(AB < 0.001 || AC < 0.001 || BC < 0.001){
        return 2;
    }
    else return 0;
}

int checkPythagoras(float a, float b, float c){
    if (fabs(a*a + b*b - c*c) < 0.001 ||
        fabs(a*a + c*c - b*b) < 0.001 ||
        fabs(b*b + c*c - a*a) < 0.001){
            return 1;
        }
        
    return 0;
}

int main(){

    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);

    if(a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || b+c<=a){
        printf("Tidak valid\n");
        return 0;
    }

    int equal = checkEqual(a,b,c);
    int right = checkPythagoras(a,b,c);

    if(equal == 3)
        printf("Segitiga Sama Sisi\n");
    else if(right && equal == 2)
        printf("Segitiga Siku-Siku Sama Kaki\n");
    else if(right)
        printf("Segitiga Siku-Siku\n");
    else if(equal == 2)
        printf("Segitiga Sama Kaki\n");
    else
        printf("Segitiga Sembarang\n");

    return 0;
}