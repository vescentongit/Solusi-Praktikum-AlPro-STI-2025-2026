#include <stdio.h>
#include <stdbool.h>

int faktorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * faktorial(n - 1);
}

bool cekAngkaAneh(int x) {

    int jumlah = 0;
    int temp = x;

    while (temp > 0) {
        int digit = temp % 10;
        jumlah += faktorial(digit);
        temp /= 10;
    }

    return jumlah == x;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int F;
        scanf("%d", &F);

        if (cekAngkaAneh(F))
            printf("BAHAYA\n");
        else
            printf("AMAN\n");
    }

    return 0;
}