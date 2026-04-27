#include <stdio.h>

#define boolean unsigned char
#define true 1
#define false 0

typedef struct
{
   float width;  /* panjang denah kayu */
   float height; /* lebar denah kayu */
} RECTANGLE;

/* *** Notasi Akses: Selektor RECTANGLE (Kaca Pembesar Dipper) *** */
#define Width(R) (R).width
#define Height(R) (R).height

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

/* *** Konstruktor membentuk RECTANGLE *** */
RECTANGLE MakeRectangle(float width, float height);
/* *** Membentuk sebuah denah RECTANGLE dari komponen-komponen kayunya *** */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS *** */
void readRectangle(RECTANGLE *R);
/* Membaca nilai panjang dan lebar dari keyboard (input dari Grunkle Stan) 
   dan membentuk RECTANGLE R berdasarkan dari nilai tersebut */
/* Komponen panjang dan lebar dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk RECTANGLE dengan panjang 1 dan lebar 2 */

void printRectangle(RECTANGLE R);
/* Nilai R ditulis ke layar monitor kasir dengan format "R(PanjangxLebar)"
   misalnya denah dengan panjang 1 dan lebar 2 akan ditulis
   sebagai "R(1.00x2.00)" */

boolean isSquare(RECTANGLE R);
/* Mengirimkan true jika width dan height dari RECTANGLE sama (Bujur sangkar sempurna / Anomali Geometris) */

boolean isNotSquare(RECTANGLE R);
/* Mengirimkan true jika width dan height dari RECTANGLE tidak sama (Normal) */

float area(RECTANGLE R);
/* Menghitung luas RECTANGLE dengan rumus: PanjangxLebar*/

float perimeter(RECTANGLE R);
/* I.S. R terdefinisi */
/* F.S. Keliling R dengan rumus 2 * (width + height) (Untuk menghitung panjang pagar pembatas) */

void swap(RECTANGLE *R);
/* R yang panjang dan lebarnya ditukar akibat efek medan gravitasi, 
   sehingga panjang sebesar lebar dan lebar sebesar panjang */

void add(RECTANGLE *R, float deltaWidth, float deltaHeight);
/* R yang ditambah panjangnya sebesar deltaWidth dan ditambah lebarnya sebesar deltaHeight */

RECTANGLE plusRectangle(RECTANGLE R, float deltaWidth, float deltaHeight);
/* Mengirim salinan blueprint R yang panjangnya adalah Width(R) + deltaWidth 
   dan lebarnya adalah Height(R) + deltaHeight */


RECTANGLE MakeRectangle(float width, float height) {
    RECTANGLE R;
    Width(R) = width;
    Height(R) = height;
    return R;
}

void readRectangle(RECTANGLE *R){
    scanf("%f %f", &R->width, &R->height);
}

void printRectangle(RECTANGLE R){
    printf("R(%.2fx%.2f)\n", Width(R), Height(R));
}

boolean isSquare(RECTANGLE R){
    return Width(R) == Height(R);
}

boolean isNotSquare(RECTANGLE R){
    return Width(R) != Height(R);
}

float area(RECTANGLE R){
    return Width(R)*Height(R);
}

float perimeter(RECTANGLE R){
    float keliling = 2*(Width(R)+Height(R));
    return keliling;
}

void swap(RECTANGLE *R){
    float temp = R->width;
    R->width = R->height;
    R->height = temp;
}

void add(RECTANGLE *R, float deltaWidth, float deltaHeight){
    R->width += deltaWidth;
    R->height += deltaHeight;
}

RECTANGLE plusRectangle(RECTANGLE R, float deltaWidth, float deltaHeight){
    RECTANGLE new;
    Height(new) = Height(R) + deltaHeight;
    Width(new) = Width(R) + deltaWidth;

    return new;
}