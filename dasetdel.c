/**
 * Implementasi ADT Dynamic Array
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>

// Struktur ADT DynamicArray

typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi

void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, int value);
void dArray_popBack(DynamicArray *darray);
int  dArray_back(DynamicArray *darray);
int  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, int value);
int  dArray_getAt(DynamicArray *darray, unsigned index);

void taruhPada(DynamicArray *darray, unsigned indeks, int nilai);
void hapusPada(DynamicArray *darray, unsigned indeks);

// Definisi fungsi

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, int value)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

int dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

int dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}

void dArray_setAt(
    DynamicArray *darray, unsigned index, int value)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            darray->_arr[darray->_size-1] = value;
        else
            darray->_arr[index] = value;
    }
}

int dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

void taruhPada(DynamicArray *darray, unsigned indeks, int nilai)
{
    if (!dArray_isEmpty(darray)) {
        if (indeks >= darray->_size)
            darray->_arr[darray->_size-1] = nilai;
        else
            darray->_arr[indeks] = nilai;
    }
}

void hapusPada(DynamicArray *darray, unsigned indeks)
{
	DynamicArray *sementara;
	sementara->_capacity = 2u;
    sementara->_size = 0u;
    sementara->_arr = (int*) malloc((darray->_size - 1) * sizeof(int));
    
    int i = 0;
    
    // Salin data sebelum indeks yang diinginkan
    for (; i < indeks; ++i) {
    	dArray_pushBack(sementara, darray->_arr[i]);
    }
    
    // Salin data setelah indeks yang diinginkan
    for (; i < (darray->_size - 1); ++i) {
        dArray_pushBack(sementara, darray->_arr[i+1]);
    }
    
    free (darray);
    *darray = *sementara;
}

/* Gunakan ini untuk mempersingkat penulisan kode */

#define d_init dArray_init
#define d_isEmpty dArray_isEmpty
#define d_pushBack dArray_pushBack
#define d_popBack dArray_popBack
#define d_back dArray_back
#define d_front dArray_front
#define d_setAt dArray_setAt
#define d_getAt dArray_getAt

/* */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Buat objek DynamicArray
    DynamicArray myArray;

    // PENTING! Jangan lupa diinisialisasi
    dArray_init(&myArray);

    // Isi myArray awal
    dArray_pushBack(&myArray, 5);
    dArray_pushBack(&myArray, 10);
    dArray_pushBack(&myArray, 15);
    dArray_pushBack(&myArray, 20);
    dArray_pushBack(&myArray, 25);

	printf("Isi myArray awal: ");
    int i = 0;
    for (; i < myArray._size; ++i) {
        printf("%d ", dArray_getAt(&myArray, i));
    }
    printf("\n");
    
    // Isi myArray setelah dimasukkan elemen baru pada posisi yang diinginkan
    taruhPada(&myArray, 2, 19);
    taruhPada(&myArray, 3, 23);
    
	printf("Isi myArray setelah taruh: ");
    for (i = 0; i < myArray._size; ++i) {
        printf("%d ", dArray_getAt(&myArray, i));
    }
    printf("\n");
    
    // Isi myArray setelah dihapus elemen baru pada posisi yang diinginkan
    hapusPada(&myArray, 2);
    
	printf("Isi myArray setelah hapus: ");
    for (i = 0; i < myArray._size; ++i) {
        printf("%d ", dArray_getAt(&myArray, i));
    }
    printf("\n");
    
    return 0;
}
