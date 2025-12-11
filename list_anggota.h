#ifndef LIST_ANGGOTA_H
#define LIST_ANGGOTA_H

#include <iostream>
#include <string>
using namespace std;

struct Peminjaman; // forward declaration

struct RelasiAnggota {
    Peminjaman *child;
    RelasiAnggota *next;
};

struct Anggota {
    string idAnggota;
    string nama;

    RelasiAnggota *relasi; // LIST RELASI TIPE A
    Anggota *next;
    Anggota *prev;
};

struct ListAnggota {
    Anggota *first;
    Anggota *last;
};

void createList(ListAnggota &L);
Anggota* alokasiAnggota(string id, string nama);

void insertFirst(ListAnggota &L, Anggota *p);
void insertLast(ListAnggota &L, Anggota *p);

Anggota* findAnggota(ListAnggota L, string id);

void deleteFirst(ListAnggota &L);
void deleteLast(ListAnggota &L);
void deleteByID(ListAnggota &L, string id);

void printInfo(ListAnggota L);

void tambahRelasi(Anggota *A, Peminjaman *P);
void printRelasiAnggota(Anggota *A);

#endif
