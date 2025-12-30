#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

string username[10];
string password[10];
int jumlahUser = 0;

string tugas[10];
string statusTugas[10];
string kategori[10];
int prioritas[10];
int jumlahTugas = 0;

void clearScreen()
{
    system("cls");
}

void judulTodo()
{
    cout << "████████╗ ██████╗     ██████╗  ██████╗     ██╗     ██╗███████╗████████╗\n";
    cout << "╚══██╔══╝██╔═══██╗    ██╔══██╗██╔═══██╗    ██║     ██║██╔════╝╚══██╔══╝\n";
    cout << "   ██║   ██║   ██║    ██║  ██║██║   ██║    ██║     ██║███████╗   ██║   \n";
    cout << "   ██║   ██║   ██║    ██║  ██║██║   ██║    ██║     ██║╚════██║   ██║   \n";
    cout << "   ██║   ╚██████╔╝    ██████╔╝╚██████╔╝    ███████╗██║███████║   ██║   \n";
    cout << "   ╚═╝    ╚═════╝     ╚═════╝  ╚═════╝     ╚══════╝╚═╝╚══════╝   ╚═╝   \n";
}

void judul()
{
    cout << "=====================================\n";
    cout << "FINAL PROJECT C++\n";
    judulTodo();
    cout << "=====================================\n";
}

void menuLogin()
{
    cout << "\n1. Register\n";
    cout << "2. Login\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

void registerUser()
{
    if (jumlahUser == 5)
    {
        cout << "User penuh!\n";
        return;
    }

    cout << "\n=== REGISTER ===\n";
    cout << "Username: ";
    cin >> username[jumlahUser];
    cout << "Password: ";
    cin >> password[jumlahUser];

    jumlahUser++;
    cout << "\nRegister berhasil! Silakan login.\n";
}

bool loginUser()
{
    string user, pass;
    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    for (int i = 0; i < jumlahUser; i++)
    {
        if (username[i] == user && password[i] == pass)
        {
            cout << "\nLogin berhasil! Selamat datang, " << user << "\n";
            return true;
        }
    }

    cout << "Login gagal!\n";
    return false;
}

void menuTodo()
{
    cout << "\n===== TO DO LIST =====\n";
    cout << "1. Tambah Tugas\n";
    cout << "2. Lihat Semua Tugas\n";
    cout << "3. Tandai Tugas Selesai\n";
    cout << "4. Hapus Tugas\n";
    cout << "5. Lihat Tugas Belum Selesai\n";
    cout << "6. Lihat Tugas Selesai\n";
    cout << "7. Edit Tugas\n";
    cout << "0. Logout\n";
    cout << "Pilih menu: ";
}

void tambahTugas()
{
    if (jumlahTugas == 10)
    {
        cout << "Tugas penuh!\n";
        return;
    }

    cin.ignore();

    cout << "Masukkan nama tugas: ";
    getline(cin, tugas[jumlahTugas]);

pilih_kategori:
    int pilihKategori;
    cout << "\nPilih kategori tugas:\n";
    cout << "1. Kuliah\n";
    cout << "2. Pekerjaan\n";
    cout << "3. Pribadi\n";
    cout << "Pilihan (1-3): ";
    cin >> pilihKategori;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input harus angka 1-3! Pilih Kembali ke menu tambah tugas.\n";
        goto pilih_kategori;
    }

    if (pilihKategori == 1)
    {
        kategori[jumlahTugas] = "Kuliah";
    }
    else if (pilihKategori == 2)
    {
        kategori[jumlahTugas] = "Pekerjaan";
    }
    else if (pilihKategori == 3)
    {
        kategori[jumlahTugas] = "Pribadi";
    }
    else
    {
        cout << "Pilihan kategori tidak valid! Kembali ke menu tambah tugas.\n";
        goto pilih_kategori;
    }

pilih_prioritas:
    int pilihPrioritas;
    cout << "\nPilih prioritas tugas:\n";
    cout << "1. Rendah\n";
    cout << "2. Sedang\n";
    cout << "3. Tinggi\n";
    cout << "Pilihan (1-3): ";
    cin >> pilihPrioritas;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input harus angka 1-3! Kembali ke menu pilih prioritas.\n";
        goto pilih_prioritas;
    }

    if (pilihPrioritas == 1 || pilihPrioritas == 2 || pilihPrioritas == 3)
    {
        prioritas[jumlahTugas] = pilihPrioritas;
    }
    else
    {
        cout << "Pilihan prioritas tidak valid! Kembali ke menu pilih prioritas.\n";
        goto pilih_prioritas;
    }

    statusTugas[jumlahTugas] = "Belum Selesai";
    jumlahTugas++;

    cout << "\nTugas berhasil ditambahkan!\n";
}

void lihatTugas()
{
    if (jumlahTugas == 0)
    {
        cout << "Belum ada tugas.\n";
        return;
    }

    cout << "\nDAFTAR TUGAS:\n";
    for (int i = 0; i < jumlahTugas; i++)
    {
        cout << i + 1 << ". " << tugas[i]
             << " [Status: " << statusTugas[i]
             << "] [Kategori: " << kategori[i]
             << "] [Prioritas: " << prioritas[i] << "]\n";
    }
}

void lihatTugasBelumSelesai()
{
    bool ada = false;
    cout << "\nTUGAS BELUM SELESAI:\n";
    for (int i = 0; i < jumlahTugas; i++)
    {
        if (statusTugas[i] == "Belum Selesai")
        {
            cout << i + 1 << ". " << tugas[i]
                 << " [Kategori: " << kategori[i]
                 << "] [Prioritas: " << prioritas[i] << "]\n";
            ada = true;
        }
    }
    if (!ada)
    {
        cout << "Tidak ada tugas yang belum selesai.\n";
    }
}

void lihatTugasSelesai()
{
    bool ada = false;
    cout << "\nTUGAS SELESAI:\n";
    for (int i = 0; i < jumlahTugas; i++)
    {
        if (statusTugas[i] == "Selesai")
        {
            cout << i + 1 << ". " << tugas[i]
                 << " [Kategori: " << kategori[i]
                 << "] [Prioritas: " << prioritas[i] << "]\n";
            ada = true;
        }
    }
    if (!ada)
    {
        cout << "Tidak ada tugas yang sudah selesai.\n";
    }
}

void tandaiSelesai()
{
    if (jumlahTugas == 0)
    {
        cout << "Belum ada tugas.\n";
        return;
    }

    lihatTugas();
    int nomor;
    cout << "Pilih nomor tugas yang akan ditandai selesai: ";
    cin >> nomor;

    if (nomor < 1 || nomor > jumlahTugas)
    {
        cout << "Nomor tidak valid!\n";
    }
    else
    {
        statusTugas[nomor - 1] = "Selesai";
        cout << "Tugas ditandai selesai!\n";
    }
}

void hapusTugas()
{
    if (jumlahTugas == 0)
    {
        cout << "Belum ada tugas.\n";
        return;
    }

    lihatTugas();
    int nomor;
    cout << "Pilih nomor tugas yang akan dihapus: ";
    cin >> nomor;

    if (nomor < 1 || nomor > jumlahTugas)
    {
        cout << "Nomor tidak valid!\n";
        return;
    }

    cout << "Anda yakin ingin menghapus tugas: " << tugas[nomor - 1] << " ? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y')
    {
        for (int i = nomor - 1; i < jumlahTugas - 1; i++)
        {
            tugas[i] = tugas[i + 1];
            statusTugas[i] = statusTugas[i + 1];
            kategori[i] = kategori[i + 1];
            prioritas[i] = prioritas[i + 1];
        }
        jumlahTugas--;
        cout << "Tugas berhasil dihapus!\n";
    }
    else
    {
        cout << "Penghapusan dibatalkan.\n";
    }
}

void editTugas()
{
    if (jumlahTugas == 0)
    {
        cout << "Belum ada tugas.\n";
        return;
    }

    lihatTugas();

pilih_nomor:
    int nomor;
    cout << "\nPilih nomor tugas yang akan diedit: ";
    cin >> nomor;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input harus angka! Kembali pilih nomor.\n";
        goto pilih_nomor;
    }

    if (nomor < 1 || nomor > jumlahTugas)
    {
        cout << "Nomor tidak valid! Kembali pilih nomor.\n";
        goto pilih_nomor;
    }

    int index = nomor - 1;
    cin.ignore();

    cout << "\nNama tugas sekarang : " << tugas[index] << "\n";
    cout << "Masukkan nama tugas baru (kosongkan jika tidak diubah): ";
    string namaBaru;
    getline(cin, namaBaru);
    if (!namaBaru.empty())
    {
        tugas[index] = namaBaru;
    }

    cout << "\nKategori sekarang   : " << kategori[index] << "\n";
    cout << "Ubah kategori? (y/n): ";
    char ubahKategori;
    cin >> ubahKategori;

    if (ubahKategori == 'y' || ubahKategori == 'Y')
    {

    pilih_kategori_edit:
        int pilihKategori;
        cout << "\nPilih kategori baru:\n";
        cout << "1. Kuliah\n";
        cout << "2. Pekerjaan\n";
        cout << "3. Pribadi\n";
        cout << "Pilihan (1-3): ";
        cin >> pilihKategori;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka 1-3! Kembali ke pilih kategori.\n";
            goto pilih_kategori_edit;
        }

        if (pilihKategori == 1)
        {
            kategori[index] = "Kuliah";
        }
        else if (pilihKategori == 2)
        {
            kategori[index] = "Pekerjaan";
        }
        else if (pilihKategori == 3)
        {
            kategori[index] = "Pribadi";
        }
        else
        {
            cout << "Pilihan kategori tidak valid! Kembali ke pilih kategori.\n";
            goto pilih_kategori_edit;
        }
    }

    cout << "\nPrioritas sekarang  : " << prioritas[index] << "\n";
    cout << "Ubah prioritas? (y/n): ";
    char ubahPrioritas;
    cin >> ubahPrioritas;

    if (ubahPrioritas == 'y' || ubahPrioritas == 'Y')
    {

    pilih_prioritas_edit:
        int pilihPrioritas;
        cout << "\nPilih prioritas baru:\n";
        cout << "1. Rendah\n";
        cout << "2. Sedang\n";
        cout << "3. Tinggi\n";
        cout << "Pilihan (1-3): ";
        cin >> pilihPrioritas;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka 1-3! Kembali ke pilih prioritas.\n";
            goto pilih_prioritas_edit;
        }

        if (pilihPrioritas == 1 || pilihPrioritas == 2 || pilihPrioritas == 3)
        {
            prioritas[index] = pilihPrioritas;
        }
        else
        {
            cout << "Pilihan prioritas tidak valid! Kembali ke pilih prioritas.\n";
            goto pilih_prioritas_edit;
        }
    }

    cout << "\nData tugas berhasil diperbarui!\n";
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int pilih;
    bool login = false;

    clearScreen();
    judul();

    do
    {
        menuLogin();
        cin >> pilih;

        clearScreen();

        if (pilih == 1)
        {
            registerUser();
        }
        else if (pilih == 2)
        {
            login = loginUser();
            if (login)
            {
                int menuTodoPilihan;
                do
                {
                    cout << endl;
                    system("pause");
                    clearScreen();
                    menuTodo();
                    cin >> menuTodoPilihan;
                    clearScreen();

                    if (menuTodoPilihan == 1)
                        tambahTugas();
                    else if (menuTodoPilihan == 2)
                        lihatTugas();
                    else if (menuTodoPilihan == 3)
                        tandaiSelesai();
                    else if (menuTodoPilihan == 4)
                        hapusTugas();
                    else if (menuTodoPilihan == 5)
                        lihatTugasBelumSelesai();
                    else if (menuTodoPilihan == 6)
                        lihatTugasSelesai();
                    else if (menuTodoPilihan == 7)
                        editTugas();
                    else if (menuTodoPilihan == 0)
                        cout << "Logout berhasil.\n";
                    else
                        cout << "Menu tidak tersedia!\n";

                } while (menuTodoPilihan != 0);
            }
        }
        else if (pilih == 0)
        {
            cout << "\nProgram selesai. Terima kasih\n";
        }
        else
        {
            cout << "Menu tidak tersedia!\n";
        }

    } while (pilih != 0);

    return 0;
}
