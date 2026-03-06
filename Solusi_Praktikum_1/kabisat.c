#include <stdio.h>

int main(){
    // Kabisat : habis dibagi 4, tdk habis dibagi 400, tdk habis dibagi 100
    // habis dibagi 400
    int tahun;
    scanf("%d", &tahun);

    if (tahun <= 0){
        printf("Masukan tidak valid\n");
    }
    else{
        if (tahun % 4 == 0 && tahun % 400 != 0 && tahun % 100 != 0){
            printf("Kabisat\n");
        }
        else if(tahun % 4 != 0){
            printf("Bukan Kabisat\n");
        }
        else if(tahun % 400 == 0){
            printf("Kabisat\n");
        }
        else if(tahun % 400 != 0 && tahun % 100 == 0){
            printf("Bukan Kabisat\n");
        }
    }

    return 0;
}