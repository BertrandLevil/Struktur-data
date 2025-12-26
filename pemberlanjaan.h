#ifndef PEMBELANJAAN_H
#define PEMBELANJAAN_H
#include <iostream>
using namespace std;

struct Pembeli {
    string id;
    string nama;
    int saldo;
};

struct Barang {
    string id;
    string nama;
    int harga;
    int stok;
};

typedef struct elmPembeli* adrPembeli;
typedef struct elmBarang* adrBarang;
typedef struct elmRelasi* adrRelasi;

struct elmPembeli {
    Pembeli info;
    adrPembeli next;
};

struct elmBarang {
    Barang info;
    adrBarang next;
};

struct elmRelasi {
    adrPembeli pembeli;
    adrBarang barang;
    adrRelasi next;
};

struct ListPembeli {
    adrPembeli first;
};

struct ListBarang {
    adrBarang first;
};

struct ListRelasi {
    adrRelasi first;
};

void createListPembeli(ListPembeli &L);
void createListBarang(ListBarang &L);
void createListRelasi(ListRelasi &L);
adrPembeli newPembeli(Pembeli x);
adrBarang newBarang(Barang x);
adrRelasi newRelasi(adrPembeli p, adrBarang b);
void insertPembeliFirst(ListPembeli &L, adrPembeli p);
adrPembeli searchPembeli(ListPembeli L, string id);
void deletePembeli(ListPembeli &LP, ListRelasi &LR, string id);
void showPembeli(ListPembeli L);
void insertBarangLast(ListBarang &L, adrBarang b);
adrBarang searchBarang(ListBarang L, string id);
void deleteBarang(ListBarang &LB, ListRelasi &LR, string id);
void showBarang(ListBarang L);
void beliBarang(ListRelasi &LR, adrPembeli p, adrBarang b, int qty);
void showPembeliDenganBarang(ListPembeli LP, ListRelasi LR);
void showBarangDibeliPembeli(ListRelasi LR, string idPembeli);
void showPembeliPembeliBarang(ListRelasi LR, string idBarang);
void barangTerbanyakTersedikit(ListBarang LB, ListRelasi LR);

#endif
