#include "pemberlanjaan.h"


void createListPembeli(ListPembeli &L) {
    L.first = NULL;
}

void createListBarang(ListBarang &L) {
    L.first = NULL;
}

void createListRelasi(ListRelasi &L) {
    L.first = NULL;
}

adrPembeli newPembeli(Pembeli x) {
    adrPembeli p = new elmPembeli;
    p->info = x;
    p->next = NULL;
    return p;
}

adrBarang newBarang(Barang x) {
    adrBarang b = new elmBarang;
    b->info = x;
    b->next = NULL;
    return b;
}

adrRelasi newRelasi(adrPembeli p, adrBarang b) {
    adrRelasi r = new elmRelasi;
    r->pembeli = p;
    r->barang = b;
    r->next = NULL;
    return r;
}

void insertPembeliFirst(ListPembeli &L, adrPembeli p) {
    p->next = L.first;
    L.first = p;
}

adrPembeli searchPembeli(ListPembeli L, string id) {
    adrPembeli p = L.first;
    while (p != NULL) {
        if (p->info.id == id)
            return p;
        p = p->next;
    }
    return NULL;
}

void deletePembeli(ListPembeli &LP, ListRelasi &LR, string id) {
    adrPembeli p = LP.first, prev = NULL;

    while (p != NULL && p->info.id != id) { 
        prev = p; 
        p = p->next; 
    }

    if (p != NULL) {
        if (prev == NULL)
            LP.first = p->next;
        else
            prev->next = p->next;

        adrRelasi r = LR.first, pr = NULL;
        while (r != NULL) {
            if (r->pembeli == p) {
                if (pr == NULL)
                    LR.first = r->next;
                else
                    pr->next = r->next;
            } else {
                pr = r;
            }
            r = r->next;
        }
        delete p;
    }
}

void showPembeli(ListPembeli L) {
    adrPembeli p = L.first;
    while (p != NULL) {
        cout << p->info.id << " - " << p->info.nama
             << " (Saldo: " << p->info.saldo << ")" << endl;
        p = p->next;
    }
}


void insertBarangLast(ListBarang &L, adrBarang b) {
    if (L.first == NULL)
        L.first = b;
    else {
        adrBarang p = L.first;
        while (p->next != NULL)
            p = p->next;
        p->next = b;
    }
}

adrBarang searchBarang(ListBarang L, string id) {
    adrBarang b = L.first;
    while (b != NULL) {
        if (b->info.id == id)
            return b;
        b = b->next;
    }
    return NULL;
}

void deleteBarang(ListBarang &LB, ListRelasi &LR, string id) {
    adrBarang b = LB.first, prev = NULL;

    while (b != NULL && b->info.id != id) {
        prev = b;
        b = b->next;
    }

    if (b != NULL) {
        if (prev == NULL)
            LB.first = b->next;
        else
            prev->next = b->next;

        adrRelasi r = LR.first, pr = NULL;
        while (r != NULL) {
            if (r->barang == b) {
                if (pr == NULL)
                    LR.first = r->next;
                else
                    pr->next = r->next;
            } else {
                pr = r;
            }
            r = r->next;
        }
        delete b;
    }
}


void beliBarang(ListRelasi &LR, adrPembeli p, adrBarang b, int qty) {
    if (qty <= 0) {
        cout << "Qty harus lebih dari 0" << endl;
        return;
    }

    int bought = 0;
    for (int i = 0; i < qty; i++) {
        if (p->info.saldo >= b->info.harga && b->info.stok > 0) {
            adrRelasi r = newRelasi(p, b);
            r->next = LR.first;
            LR.first = r;

            p->info.saldo -= b->info.harga;
            b->info.stok--;
            bought++;
        } else {
            break;
        }
    }

    if (bought > 0) {
        cout << "Pembelian berhasil: " << bought << " unit" << endl;
        if (bought < qty)
            cout << "Pembelian terhenti: saldo tidak cukup atau stok habis" << endl;
    } else {
        cout << "Saldo tidak cukup atau stok habis" << endl;
    }
}

void showPembeliDenganBarang(ListPembeli LP, ListRelasi LR) {
    adrPembeli p = LP.first;
    while (p != NULL) {
        cout << p->info.nama << " membeli:" << endl;
        adrRelasi r = LR.first;
        while (r != NULL) {
            if (r->pembeli == p)
                cout << "- " << r->barang->info.nama << endl;
            r = r->next;
        }
        cout << endl;
        p = p->next;
    }
}

void showBarangDibeliPembeli(ListRelasi LR, string idPembeli) {
    adrRelasi r = LR.first;
    while (r != NULL) {
        if (r->pembeli->info.id == idPembeli)
            cout << "- " << r->barang->info.nama << endl;
        r = r->next;
    }
}

void showPembeliPembeliBarang(ListRelasi LR, string idBarang) {
    adrRelasi r = LR.first;
    while (r != NULL) {
        if (r->barang->info.id == idBarang)
            cout << "- " << r->pembeli->info.nama << endl;
        r = r->next;
    }
}

void barangTerbanyakTersedikit(ListBarang LB, ListRelasi LR) {
    adrBarang b = LB.first;
    int max = -1, min = 9999;
    string maxNama, minNama;

    while (b != NULL) {
        int count = 0;
        adrRelasi r = LR.first;
        while (r != NULL) {
            if (r->barang == b)
                count++;
            r = r->next;
        }

        if (count > max) {
            max = count;
            maxNama = b->info.nama;
        }
        if (count < min) {
            min = count;
            minNama = b->info.nama;
        }
        b = b->next;
    }

    cout << "Barang paling banyak dibeli: " << maxNama << endl;
    cout << "Barang paling sedikit dibeli: " << minNama << endl;
}
