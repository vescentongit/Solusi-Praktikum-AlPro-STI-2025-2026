/* MODUL hidden face - LIST STATIK IMPLISIT */
/* Penempatan elemen tidak rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit dengan nilai MARK */

#ifndef HIDDENFACE_H
#define HIDDENFACE_H

#include "boolean.h"

/*  Kamus Umum */
#define CAPACITY 100
#define IDX_MIN 0
#define IDX_UNDEF -1
#define MARK '\0' 

/* Definisi elemen dan koleksi objek */
typedef char ElType;
typedef int IdxType;

typedef struct{
    ElType contents[CAPACITY];
} HiddenFaces;

/* Deklarasi akses elemen */
/* Gunakan definisi ini untuk mempermudah akses elemen */
/* l adalah list, i adalah indeks */
#define ELMT(l, i) (l).contents[(i)]

/* Indeks yang digunakan [0..CAPACITY-1] */
/* List kosong jika indeks elemen pertama adalah IDX_UNDEF */

/* ********** KONSTRUKTOR ********** */
void CreateFaces(HiddenFaces *f){
    ELMT(*f, IDX_MIN) = IDX_UNDEF;
    for (int i = 1; i < CAPACITY; i++){
        ELMT(*f, i) = MARK;
    }
}
/* I.S. f sembarang */
/* F.S. Terbentuk list f kosong dengan semua elemen bernilai MARK */

/* ********** TEST KOSONG / PENUH ********** */
boolean isEmpty(HiddenFaces f){
    return (ELMT(f,0) == IDX_UNDEF);
}
/* Mengirimkan true jika list kosong */

boolean isFull(HiddenFaces f){
    return (ELMT(f, CAPACITY));
}
/* Mengirimkan true jika list penuh */

/* ********** SELEKTOR ********** */
int length(HiddenFaces f){
    int neff = 0;
    for (int i = IDX_MIN; i < CAPACITY; i++){
        if (f.contents[i] != IDX_UNDEF && f.contents[i] != MARK){
            neff++;
        }
    }

    return neff;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Jika list kosong, mengembalikan 0 */

IdxType getFirstIdx(HiddenFaces f){
    return IDX_MIN;
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType getLastIdx(HiddenFaces f){
    IdxType index = 0;
    for (int i = IDX_MIN; i < CAPACITY; i++){
        if (f.contents[i] != IDX_UNDEF && f.contents[i] != MARK){
            index = i;
        }
    }

    return index;
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan indeks elemen terakhir */

ElType getElmt(HiddenFaces f, IdxType i){
    return (ELMT(f,i));
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan elemen list f yang ke-i */

void setElmt(HiddenFaces f, IdxType i, ElType val){

}
/* Prekondisi : f tidak kosong */
/* Mengeset nilai elemen list yang ke-i sehingga bernilai val */

/* ********** TEST INDEKS ********** */
boolean isIdxValid(HiddenFaces f, IdxType i){
    return (i >= IDX_MIN && i < CAPACITY);
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan true jika i adalah indeks valid untuk container */

boolean isIdxEff(HiddenFaces f, IdxType i){
    return (i >= getFirstIdx(f) && i <= getLastIdx(f));
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan true jika i adalah indeks efektif dalam list */

/* ********** OPERASI PENAMBAHAN ELEMEN ********** */
void insertFirst(HiddenFaces *f, ElType val){
    if (!isFull(*f)){
        for (int i = getLastIdx(*f); i >= getFirstIdx(*f); i--){
            ELMT(*f, i+1) = ELMT(*f, i);
        }
        ELMT(*f, getFirstIdx(*f)) = val;
    }
}
/* Prekondisi : f, val terdefinisi */
/* Menambahkan val sebagai elemen pertama */
/* Note: Dapat dipastikan ada ruang kosong sebelum elemen pertama */

void insertAt(HiddenFaces *f, ElType val, IdxType i){
    if (!isFull(*f) && isIdxValid(*f, i)){
        for (int j = getLastIdx(*f); j >= i; j--){
            ELMT(*f, j+1) = ELMT(*f, j);
        }
        ELMT(*f, i) = val;
    }
}
/* Prekondisi : f, val terdefinisi */
/* Menambahkan val di indeks tertentu */
/* Note: Dapat dipastikan ada ruang kosong sebelum elemen pertama dan setelah elemen terakhir */

void insertLast(HiddenFaces *f, ElType val){
    if (!isFull(*f)){
        ELMT(*f, getLastIdx(*f)+1) = val;
    }
}
/* Prekondisi : f, val terdefinisi */
/* Menambahkan val sebagai elemen terakhir */
/* Note: Dapat dipastikan ada ruang kosong setelah elemen terakhir */

/* ********** OPERASI PENGHAPUSAN ELEMEN ********** */
void deleteFirst(HiddenFaces *f, ElType *val){
    if (!isEmpty(*f)){
        *val = ELMT(*f, getFirstIdx(*f));
        for (int i = getFirstIdx(*f); i < getLastIdx(*f); i++){
            ELMT(*f, i) = ELMT(*f, i+1);
        }
        ELMT(*f, getLastIdx(*f)) = MARK;
    }
}
/* Prekondisi : f tidak kosong */
/* Menghapus elemen pertama */

void deleteAt(HiddenFaces *f, ElType *val, IdxType i){
    if (!isEmpty(*f) && isIdxEff(*f, i)){
        *val = ELMT(*f, i);
        for (int j = i; j < getLastIdx(*f); j++){
            ELMT(*f, j) = ELMT(*f, j+1);
        }
        ELMT(*f, getLastIdx(*f)) = MARK;
    }
}
/* Prekondisi : f tidak kosong */
/* Menghapus elemen di indeks tertentu */

void deleteLast(HiddenFaces *f, ElType *val){
    if (!isEmpty(*f)){
        *val = ELMT(*f, getLastIdx(*f));
        ELMT(*f, getLastIdx(*f)) = MARK;
    }
}
/* Prekondisi : f tidak kosong */
/* Menghapus elemen terakhir */

/* ********** FUNGSI ANALISIS ********** */
void printAll(HiddenFaces f){
    if (isEmpty(f)){
        printf("[]\n");
    }
    else {
        printf("[");
        for (int i = getFirstIdx(f); i <= getLastIdx(f); i++){
            printf("%c", ELMT(f, i));
            if (i != getLastIdx(f)) printf(",");
        }
        printf("]\n");
    }
}
/* Prekondisi : f terdefinisi */
/* Menampilkan semua elemen efektif dari list dalam format [x1,x2,...,xn] */
/* Contoh : */
/* ['a','b','c'] */
/* Jika kosong : []*/
/* Pastikan ada newline setelah list ditampilkan */

HiddenFaces concat(HiddenFaces f1, HiddenFaces f2){
    HiddenFaces f;
    CreateFaces(&f);

    for (int i = getFirstIdx(f1); i <= getLastIdx(f1); i++){
        insertLast(&f, ELMT(f1, i));
    }

    for (int j = getFirstIdx(f2); j <= getLastIdx(f2); j++){
        insertLast(&f, ELMT(f2, j));
    }

    return f;
}
/* Prekondisi: f1 dan f2 terdefinisi, mungkin kosong. */
/* Mengembalikan hasil Konkatenasi dua buah list yang rata kiri, f2 ditaruh di belakang f1 */

#endif