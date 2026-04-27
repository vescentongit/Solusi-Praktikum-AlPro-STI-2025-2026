#ifndef MESINKETIK_H
#define MESINKETIK_H

#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 200

typedef char ElType;
typedef struct {
    ElType contents[CAPACITY];
    int nEff;
    int cursor; /* Menyimpan posisi kursor saat ini (0 <= cursor <= nEff) */
} ListKetik;

/* ********** KONSTRUKTOR ********** */
void CreateList(ListKetik *L){
    L->nEff = 0;
    L->cursor = 0;
}
/* I.S. L sembarang */
/* F.S. Terbentuk List L kosong dengan nEff = 0 dan cursor = 0 */

/* ********** SELEKTOR ********** */
int length(ListKetik L){
    return L.nEff;
}

/* ********** FUNGSI ********** */

void typeChar(ListKetik *L, ElType x){
    if (L->nEff == CAPACITY) return;
    else {
        for (int i = L->cursor; i < L->nEff; i++){
            L->contents[i+1] = L->contents[i];
        }
        L->nEff++;
        L->contents[L->cursor] = x;
        L->cursor++;
    }
}
/* I.S. L terdefinisi, mungkin penuh. */
/* F.S. Jika list belum penuh, karakter x disisipkan tepat pada posisi cursor. 
 * Semua karakter dari posisi cursor hingga akhir bergeser 1 langkah ke kanan. 
 * cursor kemudian bertambah 1. nEff bertambah 1. */

void backspace(ListKetik *L){
    if (L->cursor > 0){
        for (int i = 0;i < L->nEff-1; i++){
            L->contents[i] = L->contents[i+1];
        }
        L->nEff--;
        L->cursor--;
    }
    else {
        return;
    }
}
/* I.S. L terdefinisi. */
/* F.S. Jika cursor > 0, karakter tepat di kiri kursor (posisi cursor - 1) dihapus.
 * Karakter di kanannya bergeser 1 langkah ke kiri.
 * cursor berkurang 1. nEff berkurang 1. */

void deleteAll(ListKetik *L, ElType x){

}
/* I.S. L terdefinisi. */
/* F.S. SELURUH kemunculan karakter x di dalam list dihapus.
 * Sisa karakter merapat ke kiri (collapse).
 * PERHATIAN: Jika karakter yang terhapus berada di sebelah KIRI kursor, 
 * kursor harus ikut bergeser ke kiri agar posisi relatifnya terjaga. */


/* ********** NAVIGASI KURSOR ********** */

void cursorLeft(ListKetik *L){
    if (L->cursor > 0) L->cursor--;
    else return;
}
/* Jika cursor > 0, cursor mundur 1 langkah. */

void cursorRight(ListKetik *L){
    if (L->cursor < L->nEff) L->cursor++;
    else return;
}
/* Jika cursor < nEff, cursor maju 1 langkah. */

void cursorHome(ListKetik *L){
    L->cursor = 0;
}
/* cursor pindah ke awal list (posisi 0). */

void cursorEnd(ListKetik *L){
    L->cursor = L->nEff;
}
/* cursor pindah ke akhir teks (posisi nEff). */

void printTeks(ListKetik L){
    for (int i = 0; i < L.nEff; i++){
        printf("%c", L.contents[i]);
    }
    printf("\n");
}
/* I.S. L terdefinisi */
/* F.S. Mencetak karakter dalam L berderet, lalu cetak "\n" */

#endif