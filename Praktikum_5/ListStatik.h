#include <boolean.h>
#include <stdio.h>

#ifndef LIST_STATIK_H
#define LIST_STATIK_H

/* Kamus Umum */
#define MaxCapacity 100
#define IdxMin 1
#define ElUndef -999 /* Elemen tak terdefinisi */

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef int ElType;

typedef struct TabInt{
		ElType TI [MaxCapacity+1]; /* memori tempat penyimpan elemen (container) */
		int Neff; /* banyaknya elemen efektif */
} TabInt;

/* Indeks yang digunakan [IdxMin..MaxCapacity] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Tabel penuh: T.Neff = MaxCapacity 
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyList (TabInt *T){
    T->Neff = 0;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxCapacity */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length (TabInt T){
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
    return MaxCapacity;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
    return T.Neff == 0 ? -1 : IdxMin;
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen pertama */
/* Jika list kosong, return -1 */

IdxType GetLastIdx (TabInt T){
    return T.Neff == 0 ? -1 : T.Neff;
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen terakhir */
/* Jika list kosong, return -1 */

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmtAt (TabInt T, IdxType i){
    return T.TI[i];
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi), i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Jika list kosong, return ElUndef */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout){
    *Tout = Tin;
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */

void SetEl (TabInt *T, IdxType i, ElType v){
    T->TI[i] = v;
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

void SetNeff (TabInt *T, IdxType N){
    T->Neff = N;
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
    return (i >= IdxMin && i <= MaxCapacity);
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi), i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid untuk ukuran tabel yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEff (TabInt T, IdxType i){
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi), i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel yaitu antara indeks pertama dan indeks Neff */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
    return T.Neff == 0;
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
    return T.Neff == MaxCapacity;
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void ShowAll (TabInt T){
    if (T.Neff == 0){
        printf("Tabel kosong\n");
    }
    else{
        printf("[");
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            printf("%d", T.TI[i]);

            if (i != GetLastIdx(T)){
                printf(",");
            }
        }
        printf("],\n");
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : elemen tabel ditulis berderet ke kanan */
/* Tampilkan tabel dalam bentuk [<Elemen-1>,<Elemen-2>,<Elemen-3>,..<Elemen-Neff>], seperti [1,2,3], dan diakhiri newline */
/* Jika T kosong : Hanya menulis "Tabel kosong" dan diakhiri newline */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan dan pengurangan */
TabInt PlusTab (TabInt T1, TabInt T2){
    for(int i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        T1.TI[i] += T2.TI[i];
    }
    return T1;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */

TabInt MinusTab (TabInt T1, TabInt T2){
    for (int i = GetFirstIdx(T1); i<= GetLastIdx(T1); i++){
        T1.TI[i] -= T2.TI[i];
    }

    return T1;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
    ElType max = T.TI[GetFirstIdx(T)];
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i] > max){
            max = T.TI[i];
        }
    }
    return max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin (TabInt T){
    ElType min = T.TI[GetFirstIdx(T)];
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i] < min){
            min = T.TI[i];
        }
    }
    return min;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
    IdxType idxMax = GetFirstIdx(T);

    for (int i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++){
        if (T.TI[i] > T.TI[idxMax]) idxMax = i;
    }

    return idxMax;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType IdxMinTab (TabInt T){
    IdxType idxMin = GetFirstIdx(T);

    for (int i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++){
        if (T.TI[i] < T.TI[idxMin]) idxMin = i;
    }

    return idxMin;
}
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai minimum pada tabel */

/* ********** PENGGABUNGAN TABEL ********** */
TabInt ConcatTable (TabInt T1, TabInt T2){
    IdxType lastT1 = GetLastIdx(T1);
    IdxType startT2 = GetFirstIdx(T2);
    T1.Neff += T2.Neff;
    
    for (int i = lastT1+1; i <= T1.Neff; i++){
        T1.TI[i] = T2.TI[startT2];
        startT2++;
    }
    
    return T1;
}
/* Prekondisi : Tabel T1 dan T2 sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan hasil penggabungan dua buah tabel, T2 ditaruh di belakang T1 */

#endif