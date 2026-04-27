#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define TABLE_SIZE 101
#define MAX_KEY_LEN 32

typedef char KeyType[MAX_KEY_LEN];

typedef enum {
    SLOT_EMPTY,   /* tidak pernah diisi */
    SLOT_OCCUPIED,/* sedang terisi entry valid */
    SLOT_DELETED  /* pernah terisi, sekarang dihapus */
} SlotStatus;

typedef struct {
    KeyType key;
    int value;
    SlotStatus status;
} HashEntry;

typedef struct {
    HashEntry table[TABLE_SIZE];
    int count; /* jumlah entry berstatus SLOT_OCCUPIED */
} CipherHashMap;

/* Inisialisasi map kosong. Semua slot berstatus SLOT_EMPTY. */
void CREATE_HASHMAP(CipherHashMap *M){
    M->count = 0;
    for (int i = 0; i < TABLE_SIZE; i++){
        M->table[i].status = SLOT_EMPTY;
    }
}

/* Fungsi hash sederhana: jumlah kode ASCII karakter key, kemudian mod TABLE_SIZE. */
int HASH_FUNCTION(const char *key){
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++){
        sum += key[i];
    }

    return sum % TABLE_SIZE;   
}

/* Menambahkan atau mengubah pasangan (key, value).
   - Jika key sudah ada, update value.
   - Jika key belum ada, simpan pada slot kosong (EMPTY atau DELETED) pertama yang ditemukan.
   Return true jika berhasil, false jika tabel penuh. */
bool SET_SPELL(CipherHashMap *M, const char *key, int value){
    int index = HASH_FUNCTION(key);
    if (M->table[index].status == SLOT_EMPTY){ 
        strcpy(M->table[index].key, key);
        M->table[index].value = value;
        M->table[index].status = SLOT_OCCUPIED;
        M->count++;
        return true;
    }
    else if (M->table[index].status == SLOT_OCCUPIED && strcmp(M->table[index].key, key) == 0){
        M->table[index].value = value;
        return true;
    }
    else{
        int indexNew = (index + 1) % TABLE_SIZE;
        int startIDX = index;
        while (indexNew != startIDX){
            if (M->table[indexNew].status == SLOT_OCCUPIED && strcmp(M->table[indexNew].key, key) == 0){
                M->table[indexNew].value = value;
                return true;
            }
            
            if (M->table[indexNew].status == SLOT_EMPTY || M->table[indexNew].status == SLOT_DELETED){ 
                strcpy(M->table[indexNew].key, key);
                M->table[indexNew].value = value;
                M->table[indexNew].status = SLOT_OCCUPIED;
                M->count++;
                return true;
            }
            indexNew = (indexNew + 1) % TABLE_SIZE;
        }
    }

    return false;
}

/* Menghapus entry dengan key tertentu.
   - Jika key ditemukan, ubah status slot menjadi SLOT_DELETED dan kembalikan true.
   - Jika tidak ditemukan, kembalikan false. */
bool UNSET_SPELL(CipherHashMap *M, const char *key){
    int index = HASH_FUNCTION(key);
    
    if(M->table[index].status == SLOT_OCCUPIED && strcmp(M->table[index].key, key) == 0){
        M->table[index].status = SLOT_DELETED;
        M->count--;
        return true;
    }

    int indexNew = (index + 1) % TABLE_SIZE;
    int startIDX = index;
    while (indexNew != startIDX){
        if (M->table[indexNew].status == SLOT_EMPTY) return false;
        if (strcmp(M->table[indexNew].key,key) == 0  && M->table[indexNew].status == SLOT_OCCUPIED){
            M->table[indexNew].status = SLOT_DELETED;
            M->count--;
            return true;
        }
        indexNew = (indexNew+1)%TABLE_SIZE;
    }
    return false;

}

/* Mencari value berdasarkan key.
   - Jika ditemukan, tulis ke *value dan kembalikan true.
   - Jika tidak ditemukan, kembalikan false. */
bool FIND_SPELL(const CipherHashMap *M, const char *key, int *value){
    int index = HASH_FUNCTION(key);
    if (M->table[index].status == SLOT_EMPTY) return false;
    if (M->table[index].status == SLOT_OCCUPIED && strcmp(key, M->table[index].key) == 0){
        *value = M->table[index].value;
        return true;
    }

    int indexNew = (index + 1) % TABLE_SIZE;
    int startIDX = index;
    while (indexNew != startIDX){
        if (M->table[indexNew].status == SLOT_EMPTY) return false;
        if (strcmp(M->table[indexNew].key,key) == 0  && M->table[indexNew].status == SLOT_OCCUPIED){
            *value = M->table[indexNew].value;
            return true;    
        }
        indexNew = (indexNew+1)%TABLE_SIZE;
    }
    return false;
}

/* Mencetak semua entry berstatus SLOT_OCCUPIED:
   key value
   Satu entry per baris. Urutan tidak harus terurut. */
void PRINT_HASHMAP(const CipherHashMap *M) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (M->table[i].status == SLOT_OCCUPIED) {
            printf("%s %d\n", M->table[i].key, M->table[i].value);
        }
    }   
}

// int main(){
//     CipherHashMap M;
//     CREATE_HASHMAP(&M);

//     char cmd[32];
//     char key[MAX_KEY_LEN];
//     int value;

//     while (scanf("%s", cmd) == 1) {
//         if (strcmp(cmd, "END") == 0) {
//             break;
//         } else if (strcmp(cmd, "SET") == 0) {
//             scanf("%s %d", key, &value);
//             SET_SPELL(&M, key, value);
//         } else if (strcmp(cmd, "UNSET") == 0) {
//             scanf("%s", key);
//             UNSET_SPELL(&M, key);
//         } else if (strcmp(cmd, "GET") == 0) {
//             scanf("%s", key);
//             if (FIND_SPELL(&M, key, &value)) {
//                 printf("%d\n", value);
//             } else {
//                 printf("NOT_FOUND\n");
//             }
//         } else if (strcmp(cmd, "PRINT") == 0) {
//             PRINT_HASHMAP(&M);
//         }
//     }

//     return 0;
// }