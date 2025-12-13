#include "list_anggota.h"

/* ===================== CREATE ===================== */
void createList(ListAnggota &L) {
    L.first = NULL;
    L.last = NULL;
}

/* ===================== ALOKASI ===================== */
Anggota* alokasiAnggota(string id, string nama) {
    Anggota *p = new Anggota;
    p->idAnggota = id;
    p->nama = nama;
    p->relasi = NULL; // tidak digunakan (sesuai MLL Tipe A)
    p->next = NULL;
    p->prev = NULL;
    return p;
}

/* ===================== INSERT ===================== */
void insertFirst(ListAnggota &L, Anggota* p) {
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLast(ListAnggota &L, Anggota* p) {
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

/* ===================== DELETE ===================== */
void deleteFirst(ListAnggota &L) {
    if (L.first == NULL) return;

    Anggota *p = L.first;

    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.first = p->next;
        L.first->prev = NULL;
    }

    delete p;
}

void deleteLast(ListAnggota &L) {
    if (L.first == NULL) return;

    Anggota *p = L.last;

    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.last = p->prev;
        L.last->next = NULL;
    }

    delete p;
}

void deleteByID(ListAnggota &L, string id) {
    Anggota *p = findAnggota(L, id);
    if (p == NULL) return;

    if (p == L.first) {
        deleteFirst(L);
    } else if (p == L.last) {
        deleteLast(L);
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
}

/* ===================== FIND ===================== */
Anggota* findAnggota(ListAnggota L, string id) {
    Anggota *p = L.first;
    while (p != NULL) {
        if (p->idAnggota == id) return p;
        p = p->next;
    }
    return NULL;
}

/* ===================== PRINT ===================== */
void printInfo(ListAnggota L) {
    cout << "\n=== LIST ANGGOTA (PARENT 2) ===\n";
    if (L.first == NULL) {
        cout << "Kosong\n";
        return;
    }

    Anggota *p = L.first;
    while (p != NULL) {
        cout << "- ID: " << p->idAnggota
             << " | Nama: " << p->nama << endl;
        p = p->next;
    }
}

void printReverse(ListAnggota L) {
    cout << "\n=== LIST ANGGOTA (REVERSE) ===\n";
    if (L.last == NULL) {
        cout << "Kosong\n";
        return;
    }

    Anggota *p = L.last;
    while (p != NULL) {
        cout << "- ID: " << p->idAnggota
             << " | Nama: " << p->nama << endl;
        p = p->prev;
    }
}
