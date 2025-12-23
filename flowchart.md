flowchart TD
    A([Mulai]) --> B[Tampilkan Judul Program]
    B --> C{Menu Login}

    C -->|Register| D[Input Username & Password]
    D --> E[Simpan ke Array User]
    E --> C

    C -->|Login| F[Input Username & Password]
    F --> G{Validasi Login}

    G -->|Gagal| C
    G -->|Berhasil| H[Menu To Do List]

    H -->|Tambah Tugas| I[Input Nama Tugas]
    I --> J[Simpan ke Array Tugas]
    J --> H

    H -->|Lihat Tugas| K[Tampilkan Daftar Tugas]
    K --> H

    H -->|Tandai Selesai| L[Pilih Nomor Tugas]
    L --> M[Ubah Status Menjadi Selesai]
    M --> H

    H -->|Hapus Tugas| N[Pilih Nomor Tugas]
    N --> O[Hapus dari Array]
    O --> H

    H -->|Logout| C
    C -->|Keluar| P([Selesai])
