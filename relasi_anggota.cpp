#include "list_anggota.h"
#include "list_peminjaman.h"   
#include <iostream>
using namespace std;

RelasiAnggota* alokasiRelasi(Peminjaman *child) {
    RelasiAnggota *R = new RelasiAnggota;
    R->child = child;
    R->next = NULL;
    return R;
}

void insertRelasi(Anggota *A, Peminjaman *P) {
    RelasiAnggota *R = alokasiRelasi(P);

    R->next = A->relasi;
    A->relasi = R;

    cout << "Relasi berhasil ditambahkan ke anggota: " << A->nama << endl;
}

RelasiAnggota* findRelasi(Anggota *A, Peminjaman *P) {
    RelasiAnggota *R = A->relasi;

    while (R != NULL) {
        if (R->child == P) return R;
        R = R->next;
    }
    return NULL;
}

void deleteRelasi(Anggota *A, Peminjaman *P) {

    if (A->relasi == NULL) return;

    RelasiAnggota *R = A->relasi;

    if (R->child == P) {
        A->relasi = R->next;
        delete R;
        return;
    }
    RelasiAnggota *prev = R;
    R = R->next;

    while (R != NULL) {
        if (R->child == P) {
            prev->next = R->next;
            delete R;
            return;
        }
        prev = R;
        R = R->next;
    }
}

void printRelasiAnggota(Anggota *A) {
    cout << "\n=== Daftar Relasi Peminjaman Anggota ===\n";
    cout << "Anggota : " << A->nama << " (" << A->idAnggota << ")\n";

    if (A->relasi == NULL) {
        cout << "(Tidak ada peminjaman)\n";
        return;
    }

    RelasiAnggota *R = A->relasi;
    while (R != NULL) {
        cout << "- Peminjaman pada alamat object: " << R->child << endl;
        // nanti bisa kamu tambah detail Peminjaman
        R = R->next;
    }
}
