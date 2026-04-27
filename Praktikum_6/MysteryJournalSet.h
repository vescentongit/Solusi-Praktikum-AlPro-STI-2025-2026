#ifndef MYSTERYJOURNALSET_H
#define MYSTERYJOURNALSET_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_PAGE 200

/* ADT Set of int dengan elemen unik, disimpan di array statik. */
typedef struct {
    int data[MAX_PAGE];
    int count;
} MysteryJournalSet;

/* Inisialisasi set kosong. */
void CREATE_SET(MysteryJournalSet *S){
    S->count = 0;
}

/* Mengembalikan true jika set kosong. */
bool IS_EMPTY(const MysteryJournalSet *S){
    return (S->count == 0);
}

/* Mengembalikan true jika x adalah anggota set. */
bool IS_MEMBER(const MysteryJournalSet *S, int x){
    for (int i = 0; i < S->count; i++){
        if (S->data[i] == x) return true;
    }

    return false;
}

/* Menambah elemen x ke dalam set (jika belum ada). Return true jika berhasil, false jika sudah ada atau penuh. */
bool INSERT_PAGE(MysteryJournalSet *S, int x){
    if (IS_MEMBER(S, x)) return false;
    if (S->count == MAX_PAGE) return false;

    int i = S->count - 1;

    while (i >= 0 && S->data[i] > x){
        S->data[i + 1] = S->data[i];
        i--;
    }

    S->data[i + 1] = x;
    S->count++;

    return true;
}

/* Menghapus elemen x dari set (jika ada).
   Return true jika berhasil menghapus, false jika tidak ditemukan. */
bool DELETE_PAGE(MysteryJournalSet *S, int x){
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

/* Mengembalikan banyaknya elemen di dalam set. */
int CARDINALITY(const MysteryJournalSet *S){
    return S->count;
}

/* Menghasilkan union dari S1 dan S2: semua elemen yang ada di S1 atau S2 atau keduanya. */
MysteryJournalSet UNION_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2){
    MysteryJournalSet SN;
    if (S1->count > S2->count){
        SN.count = S1->count;
        for (int i = 0; i < S1->count; i++){
            SN.data[i] = S1->data[i];
        }

        for (int i = 0; i < S2->count; i++){
            INSERT_PAGE(&SN, S2->data[i]);
        }
    }
    else{
        SN.count = S2->count;
        for (int i = 0; i < S2->count; i++){
            SN.data[i] = S2->data[i];
        }

        for (int i = 0; i < S1->count; i++){
            INSERT_PAGE(&SN, S1->data[i]);
        }
    }

    return SN;
}

/* Menghasilkan intersection dari S1 dan S2: hanya elemen yang ada di kedua set. */
MysteryJournalSet INTERSECTION_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2){
    MysteryJournalSet S;
    if (S1->count < S2->count){
        for (int i = 0; i < S1->count; i++){
            if (IS_MEMBER(S2,S1->data[i])){
                INSERT_PAGE(&S, S1->data[i]);
            }
        }
    }
    else{
        for (int i = 0; i < S2->count; i++){
            if (IS_MEMBER(S1,S2->data[i])){
                INSERT_PAGE(&S, S2->data[i]);
            }
        }
    }

    return S;
}

/* Menghasilkan difference S1 - S2: elemen yang ada di S1 tetapi tidak di S2. */
MysteryJournalSet DIFFERENCE_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2){
    MysteryJournalSet S;
    S.count = S1->count;
    for (int i = 0; i < S1->count; i++){
        if (!IS_MEMBER(S2,S1->data[i])){
            INSERT_PAGE(&S, S1->data[i]);
        }
    }

    return S;
}

/* Mencetak isi set dengan format {a, b, c}. Elemen harus dicetak dalam urutan menaik. Jika kosong, cetak "{}". */
void PRINT_SET(const MysteryJournalSet *S){
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

#endif