#include <stdio.h>

int main() {
    int N, B;
    scanf("%d %d", &N, &B);

    if (N <= 0 || B < 2 || B > 10) {
        printf("Masukan tidak valid\n");
        return 0;
    }

    int bases[32];
    int count = 0;

    while (N > 0) {
        bases[count] = N % B;
        N /= B;
        count++;
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d", bases[i]);
    }

    printf("\n");

    return 0;
}