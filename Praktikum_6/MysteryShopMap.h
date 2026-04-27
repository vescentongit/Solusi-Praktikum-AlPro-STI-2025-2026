#ifndef MYSTERYSHOPMAP_H
#define MYSTERYSHOPMAP_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define MAX_ITEM 100
#define MAX_KEY_LEN 32

typedef char KeyType[MAX_KEY_LEN];

typedef struct {
    KeyType key;
    int value; /* stok */
} MapEntry;

typedef struct {
    MapEntry data[MAX_ITEM];
    int count;
} MysteryShopMap;

/* Membuat map kosong. */
void CREATE_MAP(MysteryShopMap *M){
    M->count = 0;
}

/* Mengembalikan true jika map kosong. */
bool IS_EMPTY(const MysteryShopMap *M){
    return (M->count == 0);
}

/* Menambahkan pasangan (key, value) ke map.
   Jika key belum ada, tambahkan entry baru.
   Jika key sudah ada, update value dengan yang baru.
   Return true jika berhasil menambah entry baru atau mengupdate. */
bool SET_ITEM(MysteryShopMap *M, const char *key, int value){
    for (int i = 0; i < M->count; i++) {
        if (strcmp(M->data[i].key, key) == 0) {
            M->data[i].value = value;
            return true;
        }
    }
    
    if (M->count < MAX_ITEM) {
        strcpy(M->data[M->count].key, key);
        M->data[M->count].value = value;
        M->count++;
        return true;
    }

    return false;
}

/* Menghapus entry dengan key tertentu.
   Return true jika entry ditemukan dan dihapus, false jika tidak ada. */
bool UNSET_ITEM(MysteryShopMap *M, const char *key){
    for (int i = 0; i < M->count; i++) {
        if (strcmp(M->data[i].key, key) == 0) {
            
            for (int j = i; j < M->count - 1; j++) {
                M->data[j] = M->data[j + 1];
            }
            M->count--;
            return true;
        }
    }
    return false;
}

/* Mencari stok (value) berdasarkan key.
   Jika ditemukan, tulis stok ke *value dan return true.
   Jika tidak ditemukan, return false. */
bool FIND_ITEM(const MysteryShopMap *M, const char *key, int *value){
    for (int i = 0; i < M->count; i++) {
        if (strcmp(M->data[i].key, key) == 0) {
            *value = M->data[i].value;
            return true;
        }
    }
    return false;
}

/* Mengembalikan jumlah total stok semua barang di dalam map. */
int TOTAL_STOCK(const MysteryShopMap *M){
    int sum = 0;
    for (int i = 0; i < M->count; i++){
        sum += M->data[i].value;
    }

    return sum;
}

/* Mencetak seluruh isi map dalam format:
   key value
   urut sesuai urutan penyimpanan (indeks array dari 0..count-1). */
void PRINT_MAP(const MysteryShopMap *M){
    for (int i = 0; i < M->count; i++){
        printf("%s %d", M->data[i].key, M->data[i].value);
        if (i != M->count-1) printf(" ");
    }
    printf("\n");
}

#endif