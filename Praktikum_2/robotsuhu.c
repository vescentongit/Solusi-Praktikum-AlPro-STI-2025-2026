#include <stdio.h>

float konversiSuhu(float suhu, char asal, char tujuan) {
    if (asal == tujuan) {
        return suhu;
    }

    if (asal == 'C') {
        if (tujuan == 'K') return suhu + 273.15;
        if (tujuan == 'F') return (suhu * 9.0/5.0) + 32.0;
    }

    if (asal == 'K') {
        if (tujuan == 'C') return suhu - 273.15;
        if (tujuan == 'F') return (suhu - 273.15) * 9.0/5.0 + 32.0;
    }

    if (asal == 'F') {
        if (tujuan == 'C') return (suhu - 32.0) * 5.0/9.0;
        if (tujuan == 'K') return (suhu - 32.0) * 5.0/9.0 + 273.15;
    }

    return suhu;
}

int main() {

    float T, T_Akhir;
    char Y, Y_Akhir;
    int N;

    scanf("%f %c %d", &T, &Y, &N);

    for (int i = 0; i < N; i++) {
        char perintah;
        int x;

        scanf(" %c", &perintah);

        if (perintah == 'A') {
            scanf("%d", &x);
            T += x;
        }
        else if (perintah == 'S') {
            scanf("%d", &x);
            T -= x;
        }
        else {
            T = konversiSuhu(T, Y, perintah);
            Y = perintah;
            T_Akhir = T;
            Y_Akhir = Y;
        }
    }

    printf("%.2f %c\n", T, Y);

    return 0;
}