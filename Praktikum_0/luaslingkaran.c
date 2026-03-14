#include <stdio.h>

int main(){
    float r, luas;
    const float pi = 3.1415;
    scanf("%f",&r);

    luas = pi * r * r;

    printf("%f\n",luas);

    return 0;
}