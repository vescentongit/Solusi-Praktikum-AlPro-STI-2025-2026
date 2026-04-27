#include <stdbool.h>
#include <string.h>

#define MAX_PORTALS 100
#define MAX_KEY_LEN 64

/* ADT map array key-value untuk menyimpan data portal (mendekati hash map). */
typedef struct {
    char key[MAX_KEY_LEN];
    int value;
} PortalRecord;

typedef struct {
    PortalRecord records[MAX_PORTALS];
    int count;
} PortalMap;

/* Inisialisasi map kosong. Parameter: M = map yang akan diinisialisasi. */
void CREATE_MAP(PortalMap *M){
    M->count = 0;
}

/* Tambah/update pasangan key-value. Jika key sudah ada, value diperbarui. */
void PUT(PortalMap *M, const char *key, int value){
// Cek apakah key sudah ada untuk di-update
    for (int i = 0; i < M->count; i++) {
        if (strcmp(M->records[i].key, key) == 0) {
            M->records[i].value = value;
            return;
        }
    }
    
    if (M->count < MAX_PORTALS) {
        strcpy(M->records[M->count].key, key);
        M->records[M->count].value = value;
        M->count++;
    }
}

/* Ambil value dari key. Return true jika key ditemukan, false jika tidak. */
bool GET(const PortalMap *M, const char *key, int *value){
    for (int i = 0; i < M->count; i++) {
        if (strcmp(M->records[i].key, key) == 0) {
            *value = M->records[i].value;
            return true;
        }
    }
    return false;
}

/* Cek apakah key ada di map. Return true jika ada, false jika tidak. */
bool EXISTS(const PortalMap *M, const char *key){
    for (int i = 0; i < M->count; i++) {
        if (strcmp(M->records[i].key, key) == 0) {
            return true;
        }
    }
    return false;
}

/* Hapus key jika ada. Return true jika berhasil dihapus, false jika tidak ditemukan. */
bool REMOVE_KEY(PortalMap *M, const char *key){
    for (int i = 0; i < M->count; i++) {
        if (strcmp(M->records[i].key, key) == 0) {
            
            for (int j = i; j < M->count - 1; j++) {
                M->records[j] = M->records[j + 1];
            }
            M->count--;
            return true;
        }
    }
    return false;
}

/* Jumlah key aktif saat ini. */
int SIZE(const PortalMap *M){
    return M->count;
}