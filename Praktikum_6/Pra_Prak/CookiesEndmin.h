#ifndef COOKIESENDMIN_H
#define COOKIESENDMIN_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_COOKIES 100

/* ADT set integer unik dengan kapasitas tetap. */
typedef struct {
    int data[MAX_COOKIES];  
    int count;
} CookiesEndmin;

/* Inisialisasi set kosong. Parameter: S = set yang akan diinisialisasi. */
void CREATE_SET(CookiesEndmin *S){
    S->count = 0;
}

/* Cek apakah x anggota set. Return true jika ada, false jika tidak. */
bool IS_MEMBER(const CookiesEndmin *S, int x){
    for (int i = 0; i < S->count; i++){
        if (S->data[i] == x) return true;
    }

    return false;
}

/* Tambah x jika belum ada. Return true jika berhasil, false jika duplikat/penuh. */
bool INSERT(CookiesEndmin *S, int x){
    if (IS_MEMBER(S, x)) return false;
    if (S->count == MAX_COOKIES) return false;
    
    S->data[S->count] = x;
    S->count++;
    return true;
}

/* Hapus x jika ada. Return true jika elemen ditemukan dan dihapus. */
bool REMOVE(CookiesEndmin *S, int x){
    for (int i = 0; i < S->count; i++){
        if (S->data[i] == x){
            for (int j = i; j < S->count - 1; j++){
                S->data[j] = S->data[j + 1];
            }
            S->count--;
            return true;
        }
    }
    return false;
}

/* Jumlah elemen unik saat ini. */
int CARDINALITY(const CookiesEndmin *S){
    return S->count;
}

/* "output": cetak isi set dengan format {a, b, c}; jika kosong cetak "{}". */
  void PRINT_SET(const CookiesEndmin *S){
    if (S->count == 0) {
        printf("{}");
        return;
    }
    
    printf("{");
    for (int i = 0; i < S->count; i++) {
        printf("%d", S->data[i]);
        if (i != S->count - 1) {
            printf(", ");
        }
    }
    printf("}");

#endif