#include <stdio.h>

int hitungJumlahDigit(int N) {
    int total = 0;
    while (N > 0) {
        total += N % 10;
        N /= 10;
    }
    return total;
}

int hitungDigit(int N) {
    int count = 0;
    while (N > 0) {
        count++;
        N /= 10;
    }
    return count;
}

void cariKode(int N) {
    int res1 = hitungJumlahDigit(N);
    int digitN = hitungDigit(N);
    int faktor = 1;

    for (int i = 0; i < digitN; i++) {
        faktor *= 10;
    }
    
    int hasil2 = res1 * faktor + N;
    
    int digitHasil1 = hitungDigit(res1);
    int totalDigitHasil2 = digitHasil1 + digitN;
    
    printf("%d%d\n", totalDigitHasil2, hasil2);
}

int main() {
    int N;
    scanf("%d", &N);
    cariKode(N);

    return 0;
}