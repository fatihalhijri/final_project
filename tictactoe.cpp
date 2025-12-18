
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;


bool validPanjang(string teks) {
    return teks.length() >= 4;
}

/* ======================
   DATA LOGIN (ARRAY)
====================== */
string username[5];
string password[5];
int jumlahUser = 0;

/* ======================
   DATA TIC TAC TOE
====================== */
char board[3][3];
char pemain = 'X';

/* ======================
   FUNCTION JUDUL
====================== */


void judulTicTacToe() {
    cout << "████████╗ ██╗ ██████╗     ████████╗ █████╗  ██████╗     ████████╗ ██████╗ ███████╗\n";
    cout << "╚══██╔══╝ ██║██╔════╝     ╚══██╔══╝██╔══██╗██╔════╝     ╚══██╔══╝██╔═══██╗██╔════╝\n";
    cout << "   ██║    ██║██║             ██║   ███████║██║             ██║   ██║   ██║█████╗  \n";
    cout << "   ██║    ██║██║             ██║   ██╔══██║██║             ██║   ██║   ██║██╔══╝  \n";
    cout << "   ██║    ██║╚██████╗        ██║   ██║  ██║╚██████╗        ██║   ╚██████╔╝███████╗\n";
    cout << "   ╚═╝    ╚═╝ ╚═════╝        ╚═╝   ╚═╝  ╚═╝ ╚═════╝        ╚═╝    ╚═════╝ ╚══════╝\n";
}
void judul() {
    cout << "=================================\n";
    // cout << "      TIC TAC TOE GAME\n";
    cout << "FINAL PROJECT C++\n";
    judulTicTacToe();
    cout << "=================================\n";
}

/* ======================
   MENU LOGIN
====================== */
void menuLogin() {
    cout << "\n1. Register\n";
    cout << "2. Login\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

/* ======================
   REGISTER
====================== */
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

/* ======================
   LOGIN
====================== */
bool loginUser() {
    string user, pass;
    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    for (int i = 0; i < jumlahUser; i++) {
        if (username[i] == user && password[i] == pass) {
            cout << "\nLogin berhasil! Selamat bermain 🎮\n";
            return true;
        }
    }

    cout << "Login gagal!\n";
    return false;
}

/* ======================
   SET BOARD
====================== */
void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

/* ======================
   TAMPIL BOARD
====================== */
void tampilBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---+---+---\n";
    }
    cout << "\n";
}

/* ======================
   GANTI PEMAIN
====================== */
void gantiPemain() {
    pemain = (pemain == 'X') ? 'O' : 'X';
}

/* ======================
   CEK MENANG
====================== */
bool cekMenang() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == pemain && board[i][1] == pemain && board[i][2] == pemain)
            return true;
        if (board[0][i] == pemain && board[1][i] == pemain && board[2][i] == pemain)
            return true;
    }

    if (board[0][0] == pemain && board[1][1] == pemain && board[2][2] == pemain)
        return true;
    if (board[0][2] == pemain && board[1][1] == pemain && board[2][0] == pemain)
        return true;

    return false;
}

/* ======================
   MAIN GAME
====================== */
void mainGame() {
    int baris, kolom;
    resetBoard();

    for (int turn = 0; turn < 9; turn++) {
        tampilBoard();
        cout << "\nPemain " << pemain << endl;
        cout << "Masukkan baris (1-3): ";
        cin >> baris;
        cout << "Masukkan kolom (1-3): ";
        cin >> kolom;

        baris--; kolom--;

        if (board[baris][kolom] != ' ') {
            cout << "Kotak sudah terisi!\n";
            turn--;
            continue;
        }

        board[baris][kolom] = pemain;

        if (cekMenang()) {
            tampilBoard();
            cout << "\nPemain " << pemain << " MENANG! 🎉\n";
            return;
        }

        gantiPemain();
    }

    tampilBoard();
    cout << "\nPermainan SERI!\n";
}

/* ======================
   MAIN FUNCTION
====================== */
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
                mainGame();
                break;
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
