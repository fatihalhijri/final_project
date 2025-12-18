#include <iostream>
#include <limits>
using namespace std;

string kursi[5] = {"Kosong", "Kosong", "Kosong", "Kosong", "Kosong"};
string penumpang[5];
int total = 0;

// Menampilkan kursi
void lihatKursi() {
    cout << "\n=== DAFTAR KURSI ===\n";
    for (int i = 0; i < 5; i++) {
        cout << "Kursi " << i+1 << " : " << kursi[i] << endl;
    }
}

// Pesan tiket
void pesanTiket() {
    if (total == 5) {
        cout << "\nMaaf, tiket sudah penuh!\n";
        return;
    }

    string nama;
    int nomor;

    cout << "\nMasukkan nama penumpang: ";
    cin >> nama;

    lihatKursi();

    cout << "Pilih nomor kursi (1-5): ";
    cin >> nomor;

    if (nomor < 1 || nomor > 5) {
        cout << "Nomor kursi tidak valid!\n";
    } 
    else if (kursi[nomor - 1] == "Terisi") {
        cout << "Kursi sudah terisi!\n";
    } 
    else {
        kursi[nomor - 1] = "Terisi";
        penumpang[nomor - 1] = nama;
        total++;
        cout << "Tiket berhasil dipesan!\n";
    }
}

// Batalkan tiket
void batalkanTiket() {
    int nomor;
    lihatKursi();
    cout << "\nMasukkan nomor kursi yang ingin dibatalkan: ";
    cin >> nomor;

    if (nomor < 1 || nomor > 5) {
        cout << "Nomor tidak valid!\n";
    } 
    else if (kursi[nomor - 1] == "Kosong") {
        cout << "Kursi memang kosong!\n";
    } 
    else {
        kursi[nomor - 1] = "Kosong";
        penumpang[nomor - 1] = "";
        total--;
        cout << "Tiket berhasil dibatalkan!\n";
    }
}

// Tampilkan semua penumpang
void lihatPenumpang() {
    cout << "\n=== DATA PENUMPANG ===\n";
    for (int i = 0; i < 5; i++) {
        if (kursi[i] == "Terisi") {
            cout << "Kursi " << i+1 << " : " << penumpang[i] << endl;
        }
    }
}

int main() {
    int pilih;

    do {
        cout << "\n==== SIMULASI TIKET KERETA ====\n";
        cout << "1. Lihat Kursi\n";
        cout << "2. Pesan Tiket\n";
        cout << "3. Batalkan Tiket\n";
        cout << "4. Lihat Penumpang\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) lihatKursi();
        else if (pilih == 2) pesanTiket();
        else if (pilih == 3) batalkanTiket();
        else if (pilih == 4) lihatPenumpang();
        else if (pilih == 0) cout << "\nTerima kasih sudah naik kereta 😄\n";
        else cout << "Menu tidak tersedia!\n";

    } while (pilih != 0);

    return 0;
}

