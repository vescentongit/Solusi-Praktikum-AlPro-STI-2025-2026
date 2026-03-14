#include <stdio.h>
#include <stdbool.h>

bool isPrime(int p) {
    if (p <= 1) return false;
    if (p <= 3) return true;
    if (p % 2 == 0 || p % 3 == 0) return false;
    for (int i = 5; i * i <= p; i += 6) {
        if (p % i == 0 || p % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int P, D;
    scanf("%d %d", &P, &D);

    int count = 0;

    for (int i = P-D; i <= P+D; i++) {
        if (isPrime(i)){
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}