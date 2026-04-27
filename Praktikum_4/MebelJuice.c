#include <stdio.h>
#include <string.h>

/* Konstanta */
#define MAX_STR 100
#define MAX_PESANAN 50

/* Enum suhu minuman */
typedef enum {
    DINGIN,
    NORMAL,
    HANGAT
} Suhu;

/* Enum kadar gula */
typedef enum {
    LOW,
    MEDIUM,
    HIGH
} LevelGula;

/* Tipe data topping */
typedef struct {
    int glitter;        // gram glitter
    int dino;           // jumlah permen dinosaurus
} Topping;

/* Tipe data minuman */
typedef struct {
    char nama[MAX_STR];     // nama minuman (contoh: "Soda")
    Suhu suhu;              // preferensi suhu
    LevelGula levelGula;    // preferensi gula
    int es;                 // gram es
    Topping topping;        // preferensi topping
} Minuman;

/* Tipe data pelanggan */
typedef struct {
    char nama[MAX_STR];     // nama pelanggan
    int id;
} Pelanggan;

/* Tipe data pesanan */
typedef struct {
    Pelanggan pelanggan;    // data pelanggan
    Minuman minuman;        // data minuman
    float volumeGelas;      // preferensi volume      
    float kaloriGelas;      // preferensi kalori
} Pesanan;

/* Tipe data daftar pesanan */
typedef struct {
    Pesanan data[MAX_PESANAN];      // data pesanan
    int jumlah;                     // jumlah minuman yang dipesan
} ListPesanan;

/* Constructor minuman */
/*
 * Membuat pesanan minuman berdasarkan:
 * - nama minuman
 * - tipe suhu (DINGIN, NORMAL, HANGAT)
 * - tipe gula (LOW, MEDIUM, HIGH)
 * - jumlah es (gram)
 * - jumlah glitter (gram)
 * - jumlah permen dinosaurus
 * 
 * Hint: Bisa gunakan method strcpy()
 * Contoh penggunaan:
 * strcpy(warga.pekerjaan, pekerjaan);
*/
Minuman buatMinuman(char *nama, Suhu suhu, LevelGula levelGula, int es, int glitter, int dino);

/**
 * Menghitung volume minuman dalam gram:
 * volume = 200 + berat es + (jumlah dinosaurus * 5) + berat glitter
 */
float hitungVolume(Minuman m);

/**
 * Menghitung kalori minuman:
 * total = base + topping.dino*10 + glitter*2
 * 
 * dengan base memiliki kalori:
 * LOW    = 20
 * MEDIUM = 40
 * HIGH   = 60
 */
float hitungKalori(Minuman m);

/* Constructor pelanggan */
/*
 * Membuat pelanggan berdasarkan:
 * - nama pelanggan
 * - id pelanggan
 * 
 * Hint: Bisa gunakan method strcpy()
 * Contoh penggunaan:
 * strcpy(warga.pekerjaan, pekerjaan);
*/
Pelanggan buatPelanggan(char *nama, int id);

/* Constructor pesanan */
/*
 * Membuat pesanan minuman dengan memasukkan detail:
 * - identitas pelanggan
 * - minuman pelanggan
 * - volume minuman
 * - kalori minuman 
 * 
 * Hint: Bisa gunakan method strcpy()
 * Contoh penggunaan:
 * strcpy(warga.pekerjaan, pekerjaan);
*/
Pesanan buatPesanan(Pelanggan pelanggan, Minuman m);

/**
 * Menampilkan detail pesanan dengan format:
 * "Nama Pelanggan: <nama pelanggan>"
 * "ID Pelanggan: <id>"
 * "Minuman: <nama minuman"
 * "Suhu: <suhu>"
 * "Level Gula: <gula>"
 * "Es: <berat gula> gram"
 * "Glitter: %d gram"
 * "Dino: <jumlah dino>"
 * "Volume: <total volume dengan dua angka desimal> ml"
 * "Kalori: <total kalori dengan dua angka desimal> kkal"
 */
void tampilkanPesanan(Pesanan p);

/**
 * Membuat daftar pesanan kosong
 */
void initList(ListPesanan *l);  

/**
 * Return true jika daftar pesanan kosong
 */
int isEmpty(ListPesanan l);

/**
 * Return true jika daftar pesanan penuh (MAX_PESANAN)
 */
int isFull(ListPesanan l);

/**
 * Menambahkan pesanan ke daftar pesanan
 * Pesanan tidak ditambahkan jika daftar pesanan penuh
 */
void tambahPesanan(ListPesanan *l, Pesanan p);

/**
 * Menghapus pesanan terakhir dari daftar pesanan
 * Jika daftar kosong, tidak melakukan apa-apa
 */
void hapusPesanan(ListPesanan *l);

/**
 * Menampilkan detail seluruh pesanan yang ada
 */
void tampilkanSemuaPesanan(ListPesanan l);

/* UTILITY */
/* Implementasi fungsi di bawah ini untuk mengubah enum menjadi string */

/* Return nilai enum suhu dalam bentuk string ke buffer*/
void suhuToString(Suhu s, char *buffer);

/* Return nilai enum gula dalam bentuk string ke buffer*/
void levelGulaToString(LevelGula g, char *buffer);

void suhuToString(Suhu s, char *buffer) {
    if (s == DINGIN) strcpy(buffer, "DINGIN");
    else if (s == NORMAL) strcpy(buffer, "NORMAL");
    else strcpy(buffer, "HANGAT");
}

void levelGulaToString(LevelGula g, char *buffer) {
    if (g == LOW) strcpy(buffer, "LOW");
    else if (g == MEDIUM) strcpy(buffer, "MEDIUM");
    else strcpy(buffer, "HIGH");
}

Minuman buatMinuman(char *nama, Suhu suhu, LevelGula levelGula, int es, int glitter, int dino){
    Minuman new;
    strcpy(new.nama, nama);
    new.suhu = suhu;
    new.levelGula = levelGula;
    new.es = es;
    new.topping.glitter = glitter;
    new.topping.dino = dino;

    return new;
}

float hitungVolume(Minuman m){
    return 200 + m.es + (m.topping.dino*5) + m.topping.glitter;
}

float hitungKalori(Minuman m){
    int base;
    if (m.levelGula == 0) base = 20;
    else if (m.levelGula == 1) base = 40;
    else if (m.levelGula == 2) base = 60;

    base += (m.topping.dino*10) + (m.topping.glitter*2);

    return base;

}

Pelanggan buatPelanggan(char *nama, int id){
    Pelanggan new;
    strcpy(new.nama, nama);
    new.id = id;

    return new;
}

Pesanan buatPesanan(Pelanggan pelanggan, Minuman m){
    Pesanan new;
    new.pelanggan = pelanggan;
    new.minuman = m;
    new.kaloriGelas = hitungKalori(m);
    new.volumeGelas = hitungVolume(m);

    return new;
}

void tampilkanPesanan(Pesanan p){

    char suhuStr[MAX_STR];
    char gulaStr[MAX_STR];
    suhuToString(p.minuman.suhu, suhuStr);
    levelGulaToString(p.minuman.levelGula, gulaStr);

    printf("Nama Pelanggan: %s\n", p.pelanggan.nama);
    printf("ID Pelanggan: %d\n", p.pelanggan.id);
    printf("Minuman: %s\n", p.minuman.nama);
    printf("Suhu: %s\n", suhuStr);
    printf("Level Gula: %s\n", gulaStr);
    printf("Es: %d gram\n", p.minuman.es);
    printf("Glitter: %d gram\n", p.minuman.topping.glitter);
    printf("Dino: %d\n", p.minuman.topping.dino);
    printf("Volume: %.2f ml\n", p.volumeGelas);
    printf("Kalori: %.2f kkal\n", p.kaloriGelas);

}

void initList(ListPesanan *l) {
    l->jumlah = 0;
}


int isEmpty(ListPesanan l) {
    return l.jumlah == 0;
}


int isFull(ListPesanan l) {
    return l.jumlah == MAX_PESANAN;
}


void tambahPesanan(ListPesanan *l, Pesanan p) {
    if (isFull(*l) == 0) {
        l->data[l->jumlah] = p;
        l->jumlah++;
    }
}


void hapusPesanan(ListPesanan *l) {
    if (isEmpty(*l) == 0) {
        l->jumlah--;
    }
}

void tampilkanSemuaPesanan(ListPesanan l) {
    for (int i = 0; i < l.jumlah; i++) {
        tampilkanPesanan(l.data[i]);
    }
}