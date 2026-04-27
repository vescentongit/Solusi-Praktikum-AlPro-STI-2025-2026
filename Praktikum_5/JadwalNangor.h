#ifndef JADWALNANGOR_H
#define JADWALNANGOR_H

#include <stdio.h>

#define CAPACITY 100

typedef int ElType;
typedef struct {
    ElType contents[CAPACITY];
    int nEff;
} ListEkspedisi;

/* ********** KONSTRUKTOR ********** */
void CreateList(ListEkspedisi *L){
    L->nEff = 0;
}
/* I.S. L sembarang */
/* F.S. Terbentuk List L kosong dengan nEff = 0 */

/* ********** SELEKTOR ********** */
int length(ListEkspedisi L){
    return L.nEff;
}
/* Mengirimkan banyaknya elemen efektif list */

/* ********** OPERASI UJUNG LIST ********** */
void insertFirst(ListEkspedisi *L, ElType x){
    if (L->nEff == 0){
        L->contents[0] = x;
        L->nEff++; 
    }
    else{
        for (int i = L->nEff-1; i > 0; i--){
            L->contents[i] = L->contents[i-1];
        }

        L->contents[0] = x;
        L->nEff++;
    }
    
}
/* I.S. L terdefinisi, mungkin kosong, tidak penuh. */
/* F.S. x disisipkan sebagai elemen pertama L. */
/* HINT: lakukan pergeseran */

void insertLast(ListEkspedisi *L, ElType x){
    L->contents[L->nEff] = x;
    L->nEff++;
}
/* I.S. L terdefinisi, mungkin kosong, tidak penuh. */
/* F.S. x disisipkan sebagai elemen terakhir L. */

void deleteFirst(ListEkspedisi *L, ElType *e){
    *e = L->contents[0];

    for(int i = 0; i < L->nEff-1; i++){
        L->contents[i] = L->contents[i+1];
    }

    L->nEff--;
}
/* I.S. L terdefinisi, TIDAK kosong. */
/* F.S. Elemen pertama dihapus, nilainya disimpan ke *e. */
/* HINT: lakukan pergeseran */

void deleteLast(ListEkspedisi *L, ElType *e){
    *e = L->contents[L->nEff-1];
    L->nEff--;
}
/* I.S. L terdefinisi, TIDAK kosong. */
/* F.S. Elemen terakhir dihapus dan nilainya disimpan ke *e. */

/* ********** OPERASI TAMBAHAN ********** */
int TotalJarak(ListEkspedisi L){
    int total = 0;
    for (int i = 0; i < L.nEff; i++){
        total += L.contents[i];
    }

    return total;
}
/* Mengembalikan jumlah total nilai semua elemen di dalam List. Kembalikan 0 jika kosong. */

void printList(ListEkspedisi L){
    printf("[");
    for(int i = 0; i < L.nEff; i++){
        printf("%d"), L.contents[i];
        
        if (i != L.nEff-1) printf(",");
    }
    printf("]\n");
}
/* Mencetak isi list dengan format [x1,x2,...,xn] diakhiri newline (\n). */

#endif