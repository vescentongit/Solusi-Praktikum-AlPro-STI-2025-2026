#include <stdbool.h>
#include <stdio.h>

#define MAX_ORANGE 100

/* ADT set integer untuk menyimpan diameter orange unik. */
typedef struct {
    int data[MAX_ORANGE];
    int count;
} DoroOrangeSet;

/* Inisialisasi set kosong. */
void CREATE_SET(DoroOrangeSet *S){
    S->count = 0;
}

/* Cek apakah x anggota set. */
bool IS_MEMBER(const DoroOrangeSet *S, int x){
    for (int i = 0; i < S->count; i++){
        if (S->data[i] == x) return true;
    }

    return false;
}

/* Tambah x jika belum ada. Return true jika berhasil, false jika duplikat/penuh. */
bool ADD_ORANGE(DoroOrangeSet *S, int x){
    if (IS_MEMBER(S, x)) return false;
    if (S->count == MAX_ORANGE) return false;

    int i = S->count - 1;

    while (i >= 0 && S->data[i] > x){
        S->data[i + 1] = S->data[i];
        i--;
    }

    S->data[i + 1] = x;
    S->count++;

    return true;
}

/* Hapus x jika ada. Return true jika berhasil dihapus. */
bool REMOVE_ORANGE(DoroOrangeSet *S, int x){
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

/* Jumlah elemen unik pada set. */
int CARDINALITY(const DoroOrangeSet *S){
    return S->count;
}

/* Jumlah total diameter semua orange di set. */
int TOTAL_ENERGY(const DoroOrangeSet *S){
    int sum = 0;
    for (int i  = 0; i < S->count; i++){
        sum += S->data[i];
    }

    return sum;
}

/* "output": cetak set dengan format {a, b, c}; jika kosong cetak "{}". */
void PRINT_SET(const DoroOrangeSet *S){
    if (S->count == 0) {
    printf("{}\n");
    }
    else{
        printf("{");
        for (int i = 0; i < S->count; i++) {
            printf("%d", S->data[i]);
            if (i < S->count - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}