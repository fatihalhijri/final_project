#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

bool validPanjang(string teks) {
    return teks.length() >= 4;
}

/* =======================
   DATA LOGIN (ARRAY)
======================= */
string username[10];
string password[10];
int jumlahUser = 0;

/* =======================
   DATA TO DO LIST
======================= */
string tugas[10];
string statusTugas[10];
int jumlahTugas = 0;

/* =======================
   FUNCTION ASCII TITLE
======================= */
void judulTodo() {
    cout << "████████╗ ██████╗     ██████╗  ██████╗     ██╗     ██╗███████╗████████╗\n";
    cout << "╚══██╔══╝██╔═══██╗    ██╔══██╗██╔═══██╗    ██║     ██║██╔════╝╚══██╔══╝\n";
    cout << "   ██║   ██║   ██║    ██║  ██║██║   ██║    ██║     ██║███████╗   ██║   \n";
    cout << "   ██║   ██║   ██║    ██║  ██║██║   ██║    ██║     ██║╚════██║   ██║   \n";
    cout << "   ██║   ╚██████╔╝    ██████╔╝╚██████╔╝    ███████╗██║███████║   ██║   \n";
    cout << "   ╚═╝    ╚═════╝     ╚═════╝  ╚═════╝     ╚══════╝╚═╝╚══════╝   ╚═╝   \n";
}


void judul() {
    cout << "=====================================\n";
    cout << "FINAL PROJECT C++\n";
    // cout << "          TO DO LIST\n";
    judulTodo();
    cout << "=====================================\n";
}

void menuLogin() {
    cout << "\n1. Register\n";
    cout << "2. Login\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

void registerUser() {
    if (jumlahUser == 5) {
        cout << "User penuh!\n";
        return;
    }

    cout << "\n=== REGISTER ===\n";
    cout << "Username: ";
    cin >> username[jumlahUser];
    cout << "Password: ";
    cin >> password[jumlahUser];

    jumlahUser++;
    cout << "\n ===================\n";
    cout << "\nRegister berhasil! Silakan login.\n";
    cout << "\n ===================\n";
}


bool loginUser() {
    string user, pass;
    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    for (int i = 0; i < jumlahUser; i++) {
        if (username[i] == user && password[i] == pass) {
            cout << "\nLogin berhasil! Selamat datang, " << user << " 🎉\n";
            return true;
        }
    }

    cout << "Login gagal!\n";
    return false;
}


void menuTodo() {
    cout << "\n===== TO DO LIST =====\n";
    cout << "1. Tambah Tugas\n";
    cout << "2. Lihat Tugas\n";
    cout << "3. Tandai Tugas Selesai\n";
    cout << "4. Hapus Tugas\n";
    cout << "0. Logout\n";
    cout << "Pilih menu: ";
}


void tambahTugas() {
    if (jumlahTugas == 10) {
        cout << "Tugas penuh!\n";
        return;
    }

    cout << "Masukkan nama tugas: ";
    cin.ignore();
    getline(cin, tugas[jumlahTugas]);

    statusTugas[jumlahTugas] = "Belum Selesai";
    jumlahTugas++;

    cout << "Tugas berhasil ditambahkan!\n";
}


void lihatTugas() {
    if (jumlahTugas == 0) {
        cout << "Belum ada tugas.\n";
        return;
    }

    cout << "\nDAFTAR TUGAS:\n";
    for (int i = 0; i < jumlahTugas; i++) {
        cout << i + 1 << ". " << tugas[i]
             << " [" << statusTugas[i] << "]\n";
    }
}


void tandaiSelesai() {
    int nomor;
    lihatTugas();

    cout << "Pilih nomor tugas: ";
    cin >> nomor;

    if (nomor < 1 || nomor > jumlahTugas) {
        cout << "Nomor tidak valid!\n";
    } else {
        statusTugas[nomor - 1] = "Selesai";
        cout << "Tugas ditandai selesai!\n";
    }
}


void hapusTugas() {
    int nomor;
    lihatTugas();

    cout << "Pilih nomor tugas: ";
    cin >> nomor;

    if (nomor < 1 || nomor > jumlahTugas) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    for (int i = nomor - 1; i < jumlahTugas - 1; i++) {
        tugas[i] = tugas[i + 1];
        statusTugas[i] = statusTugas[i + 1];
    }

    jumlahTugas--;
    cout << "Tugas berhasil dihapus!\n";
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    int pilih;
    bool login = false;

    judul();

    do {
        menuLogin();
        cin >> pilih;

        if (pilih == 1) {
            registerUser();
        } 
        else if (pilih == 2) {
            login = loginUser();
            if (login) {
                int menuTodoPilihan;
                do {
                    menuTodo();
                    cin >> menuTodoPilihan;

                    if (menuTodoPilihan == 1) tambahTugas();
                    else if (menuTodoPilihan == 2) lihatTugas();
                    else if (menuTodoPilihan == 3) tandaiSelesai();
                    else if (menuTodoPilihan == 4) hapusTugas();
                    else if (menuTodoPilihan == 0) cout << "Logout berhasil.\n";
                    else cout << "Menu tidak tersedia!\n";

                } while (menuTodoPilihan != 0);
            }
        } 
        else if (pilih == 0) {
            cout << "\nProgram selesai. Terima kasih 👋\n";
        } 
        else {
            cout << "Menu tidak tersedia!\n";
        }

    } while (pilih != 0);

    return 0;
}
