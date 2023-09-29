/**
 * Implementasi ADT SInglyList (Singly Linked List)
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
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct snode_t {
    char data[101];
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, char *teks);
void slist_pushBack(SinglyList *list, char *teks);
void slist_insertAt(SinglyList *list, int index, char *teks);
char*  slist_getAt(SinglyList *list, int index);

/* Function definition below */

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, char *teks) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, teks);

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_pushBack(SinglyList *list, char *teks)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, teks);
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_insertAt(SinglyList *list, int index, char *teks)
{
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, teks);
        return;    
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, teks);
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        strcpy(newNode->data, teks);
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

char* slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList myList;

    // PENTING! Jangan lupa diinisialisasi
    slist_init(&myList);

    // Gunakan operasi linked list
    slist_pushBack(&myList, "Down");
    slist_pushBack(&myList, "Under");
    slist_pushBack(&myList, "Neath");
    slist_pushBack(&myList, "Intelligence");
    slist_pushBack(&myList, "Agency");

    slist_pushFront(&myList, "Opening");
    slist_pushFront(&myList, "Low");
    slist_pushFront(&myList, "Altitude");
    slist_pushFront(&myList, "High");
    
    int i = 0;
    for (; i < myList._size; ++i) {
        printf("%s\n", slist_getAt(&myList, i));
    }
    printf("\n");
    return 0;
}
