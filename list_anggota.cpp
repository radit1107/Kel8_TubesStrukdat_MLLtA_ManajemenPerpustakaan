#include "list_anggota.h"

void createList(ListAnggota &L) {
    L.first = NULL;
    L.last = NULL;
}

Anggota* alokasiAnggota(string id, string nama) {
    Anggota *p = new Anggota;
    p->idAnggota = id;
    p->nama = nama;
    p->next = NULL;
    p->prev = NULL;
    p->relasi = NULL;
    return p;
}

void insertFirst(ListAnggota &L, Anggota* p) {
    if (L.first == NULL) {
        L.first = L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

// ===================== INSERT LAST =====================
void insertLast(ListAnggota &L, Anggota* p) {
    if (L.first == NULL) {
        L.first = L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

Anggota* findAnggota(ListAnggota L, string id) {
    Anggota *p = L.first;
    while (p != NULL) {
        if (p->idAnggota == id) return p;
        p = p->next;
    }
    return NULL;
}

void deleteFirst(ListAnggota &L) {
    if (L.first == NULL) return;

    Anggota *p = L.first;

    if (L.first == L.last) {
        L.first = L.last = NULL;
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
        L.first = L.last = NULL;
    } else {
        L.last = p->prev;
        L.last->next = NULL;
    }
    delete p;
}

void deleteByID(ListAnggota &L, string id) {
    Anggota *p = findAnggota(L, id);
    if (p == NULL) return;

    if (p == L.first)
        deleteFirst(L);
    else if (p == L.last)
        deleteLast(L);
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
}

void printInfo(ListAnggota L) {
    cout << "\n=== LIST ANGGOTA ===\n";

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

void tambahRelasi(Anggota *A, Peminjaman *P) {
    RelasiAnggota *R = new RelasiAnggota;
    R->child = P;
    R->next = A->relasi;
    A->relasi = R;
}

void printRelasiAnggota(Anggota *A) {
    cout << "\nRelasi milik anggota: " << A->nama << endl;

    RelasiAnggota *R = A->relasi;
    if (R == NULL) {
        cout << "(Tidak ada relasi)\n";
        return;
    }

    while (R != NULL) {
        cout << "- Peminjaman ke: " << R->child << endl; // nanti diganti detail
        R = R->next;
    }
}
