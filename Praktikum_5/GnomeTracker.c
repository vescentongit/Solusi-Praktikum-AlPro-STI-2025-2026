#include <stdio.h>
#include <string.h>

/* *** Konstanta *** */
#define CAPACITY 100
#define IDX_UNDEF -1
#define boolean unsigned char
#define true 1
#define false 0

/* *** Type Data *** */
typedef int IdxType;

/* Struktur Gnome */
typedef struct {
    int id;                         // ID unik gnome
    char name[30];                  // Nama Gnome
    float height;                   // Tinggi Gnome
    char type[20];                  // Tipe Gnome (contoh: "forest", "leader", "builder", dsb)
    boolean isFriendly;             // TRUE jika gnome ramah, FALSE jika gnome berbahaya
} Gnome;

/* Struktur GnomeTrack */
typedef struct {
    Gnome contents[CAPACITY];      // Tempat penyimpanan data Gnome
    int nEff;                      // Jumlah elemen efektif dalam list
} GnomeTrack;

/**
 * Rentang indeks yang digunakan adalah [0 .. CAPACITY-1]
 * Jika L adalah List bernama GnomeTrack:
 *   - L.contents[i] mengakses Gnome ke-i
 *   - L.nEff menyatakan jumlah elemen yang valid
 * 
 * Definisi:
 *   - List kosong: L.nEff = 0
 *   - Elemen pertama: L.contents[0]
 *   - Elemen terakhir: L.contents[L.nEff - 1]
 */

/* ********** KONSTRUKTOR ********** */
/**
 * I.S. sembarang
 * F.S. Terbentuk list kosong dengan jumlah elemen efektif 0
 */
void createTracker(GnomeTrack *L);

/* ********** SELEKTOR ********** */
/**
 * Mengembalikan banyaknya elemen efektif
 */
int length(GnomeTrack L);

/**
 * Mengembalikan kapasitas maksimum list
 */
int maximumCap();

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen pertama
 */
IdxType getFirstIdx(GnomeTrack L);

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen terakhir
 */
IdxType getLastIdx(GnomeTrack L);

/**
 * Mengembalikan Gnome pada indeks ke-i
 * Prekondisi: i adalah indeks efektif yang valid
 */
Gnome getElmt(GnomeTrack L, IdxType i);

/* ********** SETTER ********** */
/**
 * Mengubah elemen pada indeks i menjadi nilai val
 */
void setElmt(GnomeTrack *L, IdxType i, Gnome val);

/**
 * Mengatur nilai jumlah elemen efektif menjadi N
 */
void setLength(GnomeTrack *L, int N);

/* ********** Validasi INDEKS ********** */
/**
 * Mengembalikan true jika indeks berada dalam rentang kapasitas [0..CAPACITY-1]
 */
boolean isIdxValid(IdxType i);

/**
 * Mengembalikan true jika indeks adalah indeks efektif [0..nEff-1]
 */
boolean isIdxEff(GnomeTrack L, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/**
 * Mengembalikan true jika list kosong
 */
boolean isEmpty(GnomeTrack L);

/**
 * Mengembalikan true jika list penuh
 */
boolean isFull(GnomeTrack L);

/* ********** Operasi Dasar ********** */
/**
 * Menyisipkan Gnome pada indeks tertentu
 * Semua elemen setelah indeks digeser ke kanan
 */
void insertAt(GnomeTrack *L, Gnome g, IdxType idx);

/**
 * Menambahkan Gnome ke posisi pertama dalam list
 * Semua elemen yang ada digeser ke kanan
 */
void insertFirst(GnomeTrack *L, Gnome g);

/**
 * Menambahkan Gnome ke posisi terakhir dalam list
 */
void insertLast(GnomeTrack *L, Gnome g);

/**
 * Menghapus Gnome pada indeks tertentu
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *g
 */
void deleteAt(GnomeTrack *L, IdxType idx, Gnome *g);

/**
 * Menghapus Gnome pada indeks pertama (0)
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *g
 */
void deleteFirst(GnomeTrack *L, Gnome *g);

/**
 * Menghapus Gnome pada indeks terakhir
 * Elemen terakhir disimpan pada *g
 */
void deleteLast(GnomeTrack *L, Gnome *g);

/**
 * Mengembalikan indeks Gnome berdasarkan ID
 * Jika tidak ditemukan, mengembalikan IDX_UNDEF
 */
IdxType indexOf(GnomeTrack L, int id);

/* ********** Utilitas dan Output ********** */
/**
 * Menampilkan seluruh isi list GnomeTrack
 * Format:
 * Gnome Entry-<index>: 
 * ID=xxx 
 * NAME=xxx 
 * HEIGHT=xxx.xx (2 angka di belakang koma)
 * TYPE=xxx 
 * FRIENDLY=Yes/No
 */
/* Setiap tampilan elemen dipisahkan dengan baris kosong */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void printAllGnome(GnomeTrack L);

/**
 * Menghapus seluruh Gnome yang tidak ramah (isFriendly == false)
 * Setiap Gnome yang dihapus akan dicetak namanya ke layar
 * Format output: "DELETED: <nama_gnome>"
 * I.S. L terdefinisi
 * F.S. Semua Gnome tidak ramah dihapus dari list dan ditampilkan namanya
 */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void deleteUnfriendly(GnomeTrack *L);

/**
 * Menampilkan hanya Gnome dengan height >= minHeight
 * format penampilan sama seperti printAllGnome
 */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void filterByHeight(GnomeTrack L, float minHeight);

/**
 * Menampilkan hanya Gnome dengan tipe tertentu
 * format penampilan sama seperti printAllGnome
 */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void filterByType(GnomeTrack L, char *targetType);

/* *** Konstanta *** */
/**
 * Rentang indeks yang digunakan adalah [0 .. CAPACITY-1]
 * Jika L adalah List bernama GnomeTrack:
 *   - L.contents[i] mengakses Gnome ke-i
 *   - L.nEff menyatakan jumlah elemen yang valid
 * 
 * Definisi:
 *   - List kosong: L.nEff = 0
 *   - Elemen pertama: L.contents[0]
 *   - Elemen terakhir: L.contents[L.nEff - 1]
 */

/* ********** KONSTRUKTOR ********** */
/**
 * I.S. sembarang
 * F.S. Terbentuk list kosong dengan jumlah elemen efektif 0
 */
void createTracker(GnomeTrack *L){
    L->nEff = 0;
}

/* ********** SELEKTOR ********** */
/**
 * Mengembalikan banyaknya elemen efektif
 */
int length(GnomeTrack L){
    return L.nEff;
}

/**
 * Mengembalikan kapasitas maksimum list
 */
int maximumCap(){   
    return CAPACITY;
}

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen pertama
 */
IdxType getFirstIdx(GnomeTrack L){
    return 0;
}

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen terakhir
 */
IdxType getLastIdx(GnomeTrack L){
    return L.nEff-1;
}

/**
 * Mengembalikan Gnome pada indeks ke-i
 * Prekondisi: i adalah indeks efektif yang valid
 */
Gnome getElmt(GnomeTrack L, IdxType i){
    return L.contents[i];
}

/* ********** SETTER ********** */
/**
 * Mengubah elemen pada indeks i menjadi nilai val
 */
void setElmt(GnomeTrack *L, IdxType i, Gnome val){
    L->contents[i] = val;
}

/**
 * Mengatur nilai jumlah elemen efektif menjadi N
 */
void setLength(GnomeTrack *L, int N){
    L->nEff = N;
}

/* ********** Validasi INDEKS ********** */
/**
 * Mengembalikan true jika indeks berada dalam rentang kapasitas [0..CAPACITY-1]
 */
boolean isIdxValid(IdxType i){
    return (i <= CAPACITY-1 && i >= 0);
}

/**
 * Mengembalikan true jika indeks adalah indeks efektif [0..nEff-1]
 */
boolean isIdxEff(GnomeTrack L, IdxType i){
    return (i >= 0 && i < L.nEff);
}

/* ********** TEST KOSONG/PENUH ********** */
/**
 * Mengembalikan true jika list kosong
 */
boolean isEmpty(GnomeTrack L){
    return (L.nEff == 0);
}

/**
 * Mengembalikan true jika list penuh
 */
boolean isFull(GnomeTrack L){
    return (L.nEff == CAPACITY);
}

/* ********** Operasi Dasar ********** */
/**
 * Menyisipkan Gnome pada indeks tertentu
 * Semua elemen setelah indeks digeser ke kanan
 */
void insertAt(GnomeTrack *L, Gnome g, IdxType idx){
    if (!isFull(*L) && idx >= 0 && idx <= L->nEff){
        for(int i = getLastIdx(*L); i >= idx; i--){
            L->contents[i+1] = L->contents[i];
        }
        L->contents[idx] = g;
        L->nEff++;
    }
}

/**
 * Menambahkan Gnome ke posisi pertama dalam list
 * Semua elemen yang ada digeser ke kanan
 */
void insertFirst(GnomeTrack *L, Gnome g){
    if (!isFull(*L)){
        for(int i = getLastIdx(*L); i >= getFirstIdx(*L); i--){
            L->contents[i+1] = L->contents[i];
        }
        L->contents[0] = g;
        L->nEff++;
    }
}

/**
 * Menambahkan Gnome ke posisi terakhir dalam list
 */
void insertLast(GnomeTrack *L, Gnome g){
    if (!isFull(*L)){
        L->contents[L->nEff] = g;
        L->nEff++;
    }
}

/**
 * Menghapus Gnome pada indeks tertentu
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *g
 */
void deleteAt(GnomeTrack *L, IdxType idx, Gnome *g){
    if (!isIdxEff(*L, idx)) return;
    *g = L->contents[idx];
    
    for(int i = idx; i < getLastIdx(*L); i++){
        L->contents[i] = L->contents[i+1];
    }

    L->nEff--;
}

/**
 * Menghapus Gnome pada indeks pertama (0)
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *g
 */
void deleteFirst(GnomeTrack *L, Gnome *g){
    if (isEmpty(*L)) return;
    *g = L->contents[0];
    for (int i = getFirstIdx(*L); i < getLastIdx(*L); i++){
        L->contents[i] = L->contents[i+1];
    }
    L->nEff--;
}

/**
 * Menghapus Gnome pada indeks terakhir
 * Elemen terakhir disimpan pada *g
 */
void deleteLast(GnomeTrack *L, Gnome *g){
    if (!isEmpty(*L)){
    *g = L->contents[getLastIdx(*L)];
    L->nEff--;
    }
}

/**
 * Mengembalikan indeks Gnome berdasarkan ID
 * Jika tidak ditemukan, mengembalikan IDX_UNDEF
 */
IdxType indexOf(GnomeTrack L, int id){
    IdxType a = 0;
    if (isEmpty(L)) return IDX_UNDEF;
    for(int i = getFirstIdx(L); i <= getLastIdx(L); i++){
        if (L.contents[i].id == id) {
            a = i;
            return a;
        }
    }

    return IDX_UNDEF;
}

/* ********** Utilitas dan Output ********** */
/**
 * Menampilkan seluruh isi list GnomeTrack
 * Format:
 * Gnome Entry-<index>: 
 * ID=xxx 
 * NAME=xxx 
 * HEIGHT=xxx.xx (2 angka di belakang koma)
 * TYPE=xxx 
 * FRIENDLY=Yes/No
 */
/* Setiap tampilan elemen dipisahkan dengan baris kosong */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void printAllGnome (GnomeTrack L){
    if (L.nEff == 0) printf("List kosong\n");
    else {
        for (int i = 0; i < L.nEff; i++){
            printf("Gnome Entry-%d:\n",i);
            printf("ID=%d\n",L.contents[i].id);
            printf("NAME=%s\n",L.contents[i].name);
            printf("HEIGHT=%.2f\n", L.contents[i].height);
            printf("TYPE=%s\n", L.contents[i].type);
            L.contents[i].isFriendly ? printf("FRIENDLY=Yes\n") : printf("FRIENDLY=No\n");
            if (i != L.nEff - 1) printf("\n");
        }
    }
}

/**
 * Menghapus seluruh Gnome yang tidak ramah (isFriendly == false)
 * Setiap Gnome yang dihapus akan dicetak namanya ke layar
 * Format output: "DELETED: <nama_gnome>"
 * I.S. L terdefinisi
 * F.S. Semua Gnome tidak ramah dihapus dari list dan ditampilkan namanya
 */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void deleteUnfriendly(GnomeTrack *L){
    if (L->nEff == 0){  
        printf("List kosong\n");
    } else {
        int i = 0;
        while (i < L->nEff){
            if (!L->contents[i].isFriendly){
                printf("DELETED: %s\n", L->contents[i].name);
                
                for (int j = i; j < L->nEff - 1; j++){
                    L->contents[j] = L->contents[j+1];
                }
                L->nEff--;
            } else {
                i++;
            }
        }
    }
}

/**
 * Menampilkan hanya Gnome dengan height >= minHeight
 * format penampilan sama seperti printAllGnome
 */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void filterByHeight(GnomeTrack L, float minHeight){
    if (L.nEff == 0){
        printf("List kosong\n");
    } else {
        boolean first = true;
        for (int i = 0; i < L.nEff; i++){
            if (L.contents[i].height >= minHeight){
                if (!first) printf("\n");
                first = false;
                printf("Gnome Entry-%d:\n", i);
                printf("ID=%d\n", L.contents[i].id);
                printf("NAME=%s\n", L.contents[i].name);
                printf("HEIGHT=%.2f\n", L.contents[i].height);
                printf("TYPE=%s\n", L.contents[i].type);
                L.contents[i].isFriendly ? printf("FRIENDLY=Yes\n") : printf("FRIENDLY=No\n");
            }
        }
    }
}

/**
 * Menampilkan hanya Gnome dengan tipe tertentu
 * format penampilan sama seperti printAllGnome
 */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */

void filterByType(GnomeTrack L, char *targetType){
    if (L.nEff == 0){
        printf("List kosong\n");        
    } else {
        boolean first = true;
        for (int i = 0; i < L.nEff; i++){
            if (strcmp(L.contents[i].type, targetType) == 0){
                if (!first) printf("\n");
                first = false;
                printf("Gnome Entry-%d:\n", i);
                printf("ID=%d\n", L.contents[i].id);
                printf("NAME=%s\n", L.contents[i].name);
                printf("HEIGHT=%.2f\n", L.contents[i].height);
                printf("TYPE=%s\n", L.contents[i].type);
                L.contents[i].isFriendly ? printf("FRIENDLY=Yes\n") : printf("FRIENDLY=No\n");
            }
        }
    }
}