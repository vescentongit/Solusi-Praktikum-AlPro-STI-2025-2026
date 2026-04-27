#ifndef WEAPONHASH_H
#define WEAPONHASH_H

#include <stdbool.h>
#include <string.h>

#define CAPACITY 100
#define MAX_KEY_LEN 64

/* Penanda status untuk tiap bucket/slot pada Hash Map */
#define EMPTY 0
#define OCCUPIED 1
#define DELETED 2

/* Elemen penyusun Hash Map */
typedef struct {
    char key[MAX_KEY_LEN];
    int value;
    int status; /* EMPTY, OCCUPIED, atau DELETED */
} HashNode;

/* ADT Hash Map berbasis Open Addressing (Linear Probing) */
typedef struct {
    HashNode elements[CAPACITY];
    int count; /* Jumlah key yang sedang aktif (status OCCUPIED) */
} WeaponHash;

/* Inisialisasi hash map kosong. Semua status bucket di-set menjadi EMPTY. */
void CREATE_HASH(WeaponHash *H){
    H->count = 0;
    for (int i = 0; i < CAPACITY; i++){
        H->elements[i].status = EMPTY;
    }
}

/* Fungsi Hash sederhana: 
   Jumlahkan nilai ASCII semua karakter pada key, lalu dimodulo dengan CAPACITY. */
int HASH_FUNCTION(const char *key){
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++){
        sum += key[i];
    }

    return sum % CAPACITY;
}

/* Tambah/update pasangan key-value. 
   Gunakan Linear Probing jika terjadi collision (tabrakan). 
   Jika key sudah ada, update value-nya. */
void INSERT_HASH(WeaponHash *H, const char *key, int value){
    int index = HASH_FUNCTION(key);
    if (H->elements[index].status == EMPTY){ 
        strcpy(H->elements[index].key, key);
        H->elements[index].value = value;
        H->elements[index].status = OCCUPIED;
        H->count++;
    }
    else if (H->elements[index].status == OCCUPIED && strcmp(H->elements[index].key, key) == 0){
        H->elements[index].value = value;
    }
    else{
        int indexNew = (index + 1) % CAPACITY;
        int startIDX = index;
        while (indexNew != startIDX){
            if (H->elements[indexNew].status == OCCUPIED && strcmp(H->elements[indexNew].key, key) == 0){
                H->elements[indexNew].value = value; // Update valuenya
                return; // Langsung keluar
            }
            
            if (H->elements[indexNew].status == EMPTY || H->elements[indexNew].status == DELETED){ 
                strcpy(H->elements[indexNew].key, key);
                H->elements[indexNew].value = value;
                H->elements[indexNew].status = OCCUPIED;
                H->count++;
                return;
            }
            indexNew = (indexNew + 1) % CAPACITY;
        }
    }
}

/* Ambil value dari key. 
   Return true jika key ditemukan (OCCUPIED), false jika tidak. 
   Pencarian harus melewati elemen DELETED. */
bool GET_HASH(const WeaponHash *H, const char *key, int *value){
    int index = HASH_FUNCTION(key);
    if (H->elements[index].status == EMPTY) return false;
    if (H->elements[index].status == OCCUPIED && strcmp(key, H->elements[index].key) == 0){
        *value = H->elements[index].value;
        return true;
    }

    int indexNew = (index + 1) % CAPACITY;
    int startIDX = index;
    while (indexNew != startIDX){
        if (H->elements[indexNew].status == EMPTY) return false;
        if (strcmp(H->elements[indexNew].key,key) == 0  && H->elements[indexNew].status == OCCUPIED){
            *value = H->elements[indexNew].value;
            return true;    
        }
        indexNew = (indexNew+1)%CAPACITY;
    }
    return false;
}   

/* Hapus key jika ada (Ubah status dari OCCUPIED menjadi DELETED).
   Return true jika berhasil dihapus, false jika tidak ditemukan. */
bool REMOVE_HASH(WeaponHash *H, const char *key){
    int index = HASH_FUNCTION(key);
    
    if(H->elements[index].status == OCCUPIED && strcmp(H->elements[index].key, key) == 0){
        H->elements[index].status = DELETED;
        H->count--;
        return true;
    }

    int indexNew = (index + 1) % CAPACITY;
    int startIDX = index;
    while (indexNew != startIDX){
        if (H->elements[indexNew].status == EMPTY) return false;
        if (strcmp(H->elements[indexNew].key,key) == 0  && H->elements[indexNew].status == OCCUPIED){
            H->elements[indexNew].status = DELETED;
            H->count--;
            return true;
        }
        indexNew = (indexNew+1)%CAPACITY;
    }
    return false;

}

/* Mengembalikan jumlah key aktif saat ini. */
int SIZE_HASH(const WeaponHash *H){
    return H->count;
}

#endif