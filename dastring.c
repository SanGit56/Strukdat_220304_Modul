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
#include <string.h>
#include <stdio.h>

// Struktur ADT DynamicArray

typedef struct dynamicarr_t {
    char *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi

void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, char *teks);
char*  dArray_getAt(DynamicArray *darray, unsigned index);

// Definisi fungsi

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (char*) malloc(sizeof(char) * 2);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, char *teks)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        char *newArr = (char*) malloc(sizeof(char) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        char *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    strcpy(&darray->_arr[darray->_size++], teks);
	printf("%s\n", &darray->_arr[darray->_size++]);
}

char* dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

/* Gunakan ini untuk mempersingkat penulisan kode */

#define d_init dArray_init
#define d_isEmpty dArray_isEmpty
#define d_pushBack dArray_pushBack
#define d_getAt dArray_getAt

/* */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Buat objek DynamicArray
    DynamicArray myText;

    // PENTING! Jangan lupa diinisialisasi
    dArray_init(&myText);

    // Menaruh karakter
    dArray_pushBack(&myText, "High");
    dArray_pushBack(&myText, "Altitude");
    dArray_pushBack(&myText, "Low");
    dArray_pushBack(&myText, "Opening");

    int i = 0;
    for (; i < myText._size; ++i) {
        printf("%s\n", dArray_getAt(&myText, i));
    }
    printf("\n");
    
    return 0;
}
