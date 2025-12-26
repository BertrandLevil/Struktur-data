#include "pemberlanjaan.h"

int main() {
    ListPembeli LP;
    ListBarang LB;
    ListRelasi LR;
    createListPembeli(LP);
    createListBarang(LB);
    createListRelasi(LR);
    int pilih;
    do {
        cout << endl <<"=== DATA PERBELANJAAN ===" << endl;
        cout << "1. Tambah Pembeli" << endl;
        cout << "2. Tambah Barang" << endl;
        cout << "3. Beli Barang" << endl;
        cout << "4. Tampilkan Pembeli + Barang" << endl;
        cout << "5. Barang Terbanyak & Tersedikit" << endl;
        cout << "6. Hapus Pembeli" << endl;
        cout << "7. Hapus Barang" << endl;
        cout << "8. Tampilkan pembeli berdasarkan barang yang dibeli" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            Pembeli p;
            cout << "ID: "; cin >> p.id;
            cout << "Nama: "; cin >> p.nama;
            cout << "Saldo: "; cin >> p.saldo;
            insertPembeliFirst(LP, newPembeli(p));
        }
        else if (pilih == 2) {
            Barang b;
            cout << "ID: "; cin >> b.id;
            cout << "Nama: "; cin >> b.nama;
            cout << "Harga: "; cin >> b.harga;
            cout << "Stok: "; cin >> b.stok;
            insertBarangLast(LB, newBarang(b));
        }
        else if (pilih == 3) {
            string idP, idB;
            int qty;
            cout << "ID Pembeli: "; cin >> idP;
            cout << "ID Barang: "; cin >> idB;
            cout << "Qty: "; cin >> qty;

            adrPembeli p = searchPembeli(LP, idP);
            adrBarang b = searchBarang(LB, idB);

            if (p != NULL && b != NULL)
                beliBarang(LR, p, b, qty);
            else
                cout << "Data tidak ditemukan" << endl;
        }
        else if (pilih == 4) {
            showPembeliDenganBarang(LP, LR);
        }
        else if (pilih == 5) {
            barangTerbanyakTersedikit(LB, LR);
        } else if (pilih == 6) {
            string idP;
            cout << "ID Pembeli yang dihapus: "; cin >> idP;
            deletePembeli(LP, LR, idP);
        }
        else if (pilih == 7) {
            string idB;
            cout << "ID Barang yang dihapus: "; cin >> idB;
            deleteBarang(LB, LR, idB);
        } else if (pilih == 8) {
            string idB;
            cout << "ID Barang: "; cin >> idB;
            cout << "Pembeli yang membeli barang " << idB << ":" << endl;
            showPembeliPembeliBarang(LR, idB);
        }

    } while (pilih != 0);

    return 0;
}
