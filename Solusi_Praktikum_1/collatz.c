#include <stdio.h>

int main(){
    long long N,X,Y;
    scanf("%lld", &N);
    Y = N;
    X = 0;

    while (N != 1){
        if (N % 2 == 0){
            printf("%lld\n", N);
            N /= 2;
            X++;
            if (N > Y){
                Y = N;
            }
        }
        else if (N % 2 != 0){
            printf("%lld\n",N);
            N = (3*N)+1;
            X++;
            if (N > Y){
                Y = N;
            }
        } 
    }

    printf("%lld\n", N);
    printf("Langkah: %lld\n", X);
    printf("Nilai maksimum: %lld\n", Y);



    return 0;
}