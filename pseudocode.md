<!-- Deklarasi Datanyyaa -->

DECLARE array username[10], password[10]
DECLARE integer jumlahUser = 0

DECLARE array tugas[10], statusTugas[10]
DECLARE integer jumlahTugas = 0


<!-- Prosedur Register -->

PROCEDURE RegisterUser
    IF jumlahUser == 5 THEN
        DISPLAY "User penuh"
        RETURN
    ENDIF

    INPUT username[jumlahUser]
    INPUT password[jumlahUser]

    jumlahUser = jumlahUser + 1
    DISPLAY "Register berhasil"
ENDPROCEDURE


<!-- Fungsi Login  -->

FUNCTION LoginUser RETURNS boolean
    INPUT user, pass

    FOR i FROM 0 TO jumlahUser - 1 DO
        IF username[i] == user AND password[i] == pass THEN
            DISPLAY "Login berhasil"
            RETURN true
        ENDIF
    ENDFOR

    DISPLAY "Login gagal"
    RETURN false
ENDFUNCTION


<!-- Prosedur Tambah Tugas -->

PROCEDURE TambahTugas
    IF jumlahTugas == 10 THEN
        DISPLAY "Tugas penuh"
        RETURN
    ENDIF

    INPUT tugas[jumlahTugas]
    statusTugas[jumlahTugas] = "Belum Selesai"

    jumlahTugas = jumlahTugas + 1
    DISPLAY "Tugas berhasil ditambahkan"
ENDPROCEDURE

<!-- Prosedur Lihat Tugas -->

PROCEDURE LihatTugas
    IF jumlahTugas == 0 THEN
        DISPLAY "Belum ada tugas"
        RETURN
    ENDIF

    FOR i FROM 0 TO jumlahTugas - 1 DO
        DISPLAY (i+1), tugas[i], statusTugas[i]
    ENDFOR
ENDPROCEDURE


<!-- Prosedur Tandai Tugas Selesai -->

PROCEDURE TandaiSelesai
    CALL LihatTugas
    INPUT nomor

    IF nomor < 1 OR nomor > jumlahTugas THEN
        DISPLAY "Nomor tidak valid"
    ELSE
        statusTugas[nomor - 1] = "Selesai"
        DISPLAY "Tugas ditandai selesai"
    ENDIF
ENDPROCEDURE

<!-- Prosedur Hapus Tugas -->

PROCEDURE HapusTugas
    CALL LihatTugas
    INPUT nomor

    IF nomor < 1 OR nomor > jumlahTugas THEN
        DISPLAY "Nomor tidak valid"
        RETURN
    ENDIF

    FOR i FROM nomor - 1 TO jumlahTugas - 2 DO
        tugas[i] = tugas[i + 1]
        statusTugas[i] = statusTugas[i + 1]
    ENDFOR

    jumlahTugas = jumlahTugas - 1
    DISPLAY "Tugas berhasil dihapus"
ENDPROCEDURE


<!-- Program Utama -->

BEGIN
    DISPLAY Judul Program

    REPEAT
        DISPLAY Menu Login
        INPUT pilih

        IF pilih == 1 THEN
            CALL RegisterUser
        ELSE IF pilih == 2 THEN
            login = LoginUser
            IF login == true THEN
                REPEAT
                    DISPLAY Menu To Do List
                    INPUT menuTodo

                    IF menuTodo == 1 THEN
                        CALL TambahTugas
                    ELSE IF menuTodo == 2 THEN
                        CALL LihatTugas
                    ELSE IF menuTodo == 3 THEN
                        CALL TandaiSelesai
                    ELSE IF menuTodo == 4 THEN
                        CALL HapusTugas
                    ELSE IF menuTodo == 0 THEN
                        DISPLAY "Logout berhasil"
                    ELSE
                        DISPLAY "Menu tidak tersedia"
                    ENDIF
                UNTIL menuTodo == 0
            ENDIF
        ELSE IF pilih == 0 THEN
            DISPLAY "Program selesai"
        ELSE
            DISPLAY "Menu tidak tersedia"
        ENDIF
    UNTIL pilih == 0
END
