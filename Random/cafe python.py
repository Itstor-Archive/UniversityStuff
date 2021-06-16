# Variabel Global
# Variabel Menu Awal
# Ini menurutku lebih enak pake dictionary
data_nama = ["Test Login"]
data_email = ["1"]
data_password = ["1"]
# Ini juga
# Variabel Membership
data_namalengkap = []
data_notelpon = []
data_kodeunik = ["130402"]
# Variabel Loop
keluar = False
logged = False

# bikin fungsi input_int, ini fungsinya buat ngehindari force close program klo user salah input. fungsi ini dipake buat pengganti input yang diconvert jadi integer/int


def input_int(inputmsg, errormsg=None):
    while True:
        try:
            x = int(input(inputmsg))
            break
        except ValueError:
            # Ini pake ternary operator.
            print(errormsg if errormsg is not None else "Masukkan hanya angka")
            # fungsi ternary operator buat nyingkat if else statement biar jadi satu baris
            # jadi itu sebenere sama kya
            # if errormsg is not None:
            #   print(errormsg)
            # else:
            #   print("masukkan hanya angka")
    return x

# Menu Awal


def menu_awal():
    print("[1] Login")
    print("[2] Daftar")
    print("[3] Keluar")

# Menu Registrasi


def daftar():
    print("---------- Daftar ----------")
    print("\nSilahkan Mengisi Data yang Diperlukan")

    nama = input("Masukkan Nama Anda \n>> ")
    data_nama.append(nama)

    email = input("Masukkan email Anda \n>> ")
    # ini bisa pake regex, biar gak hanya gmail aja yang support, tp email lain juga bisa
    harus_ada1 = "@gmail.com"
    while not (harus_ada1 in email):
        print("Masukkan email Google yang benar!")
        email = input("\nMasukkan email Google Anda \n>> ")
    data_email.append(email)

    password = input("Masukkan Password Anda \n>> ")
    while not (len(password) >= 8 and password.isalnum()):
        print(
            "Masukkan password dengan minimal 8 karakter dengan kombinasi angka dan huruf")
        password = input("\nMasukkan password Anda \n>> ")
    data_password.append(password)

    print("Terima kasih, Data Anda Sudah Terdaftar")
    print("Silakan Login di Menu Awal")
    return

# Menu Login


def masuk():
    print("---------- Login ----------")
    print("\nSilakan Masukkan Akun Anda yang telah terdaftar ")

    email_login = input("Email: ")

    password_login = input("Password: ")
    validasi = False
    while not validasi:
        for i in range(len(data_email)):
            if (email_login == data_email[i]) and (password_login == data_password[i]):
                validasi = True
                print("Login berhasil! \n")
                return data_nama[i]
        if validasi:
            break
        else:
            print("Email atau Password salah!")
            email_login = input("Email: ")
            password_login = input("Password: ")

# Menu Utama setelah Login


def menu_utama(name):
    print("===== Selamat Datang", nama, " =====")
    print("---------- MENU ----------")
    print("[1] Membership")
    print("[2] Transaksi")
    print("[3] Pengaturan Akun")
    print("[4] Keluar")

# Menu Membership


def member():

    def riwayat():
        print("Bentar dulu")

    def daftar_member():
        print("Silakan masukkan data diri Anda!")
        nama_member = input("Nama Lengkap:\n>> ")
        data_namalengkap.append(nama_member)

        notelpon = int(input("Nomor Telepon:\n>> "))
        data_notelpon.append(notelpon)

        kode_unik = int(input("Kode Unik:\n>> "))
        data_kodeunik.append(kode_unik)

    def cek_member():
        cek_kode = input("Masukkan kode unik membership Anda:\n>> ")
        validasi = False
        while not validasi:
            for i in range(len(data_kodeunik)):
                if (cek_kode == data_kodeunik[i]):
                    validasi = True
                    print("Anda Mempunyai Membership!\n")
                    print("----- Membership Menu ------")
                    print("[1.] Cek Riwayat Transaksi")
                    print("[2.] Kembali")
                    riwayat_transaksi = int(input("Pilih Menu\n>> "))
                    if riwayat_transaksi == 1:
                        riwayat()
                    elif riwayat_transaksi == 2:
                        return  # balik ke menu awal pake return aja

            if validasi:
                break
            else:
                print("Kode Unik salah!")
                cek_kode = input("Kode Unik:\n>> ")

                print("\nAtau apakah Anda belum mendaftar sebagai member?")
                choice = input("Anda ingin mendaftar menjadi member? [Y/N]")
                print("Pendaftaran member dikenakan biaya Rp30.000")
                if choice == "Y":
                    daftar_member()
                else:
                    return  # balik ke menu awal pake return aja

    print("Apakah Anda mempunyai Membership? [Y/N]")
    itu = input().upper()
    if itu == "Y":
        print("Apakah Anda ingin Cek Membership? [Y/N]")
        ini = input().upper()
        if ini == "Y":
            cek_member()
        elif ini == "N":
            return  # balik ke menu awal pake return aja
    elif itu == "N":
        print("Apakah Anda ingin mendaftar Membership? [Y/N]")
        print("Pendaftaran member dikenakan biaya Rp30.000")
        iniitu = input().upper()
        if iniitu == "Y":
            daftar_member()
        elif iniitu == "N":
            return  # balik ke menu awal pake return aja


# Menu Transaksi
def transaksi():
    def billing():
        print("Silakan pilih paket yang Anda inginkan\n>>")
        print("1. Standar (Rp4000/jam)")
        print("2. VIP (Rp6000/jam)")
        print("3. VVIP (Rp9000/jam)")
        print("4. Kembali")

    print
    billing()
    while True:
        pilih3 = input_int("Silakan pilih\n>> ")

        if pilih3 == 1:
            standar = 4000
            durasi = int(input("Input durasi (jam): "))
            net = durasi * standar
        elif pilih3 == 2:
            vip = 6000
            durasi = int(input("Input durasi (jam): "))
            net = durasi * vip
        elif pilih3 == 3:
            vvip = 4000
            durasi = int(input("Input durasi (jam): "))
            net = durasi * vvip
        elif pilih3 == 4:
            return  # balik ke menu awal pake return aja

# fnb dimasukin ke menu billing terus ditotal


def fnb():
    # tambah pilihan 9, buat pilihan selesai
    print("Food and Beverage")
    print("[1] Roti      : Rp5.000,00")
    print("[2] Mi Goreng : Rp5.000,00")
    print("[3] Mi Kuah   : Rp5.000,00")
    print("[4] Nugget    : Rp7.000,00")
    print("[5] Kentang   : Rp8.000,00")
    print("[6] Es Teh    : Rp3.000,00")
    print("[7] Es Jeruk  : Rp3.000,00")
    print("[8] Susu      : Rp5.000,00")
    print("[9] Selesai")

    # ini dijadikan satu aja.
    totalHarga = 0
    while True:
        # aku saranin jangan make nama variabel dan nama fungsi sama. klo di python si kyknya gk begitu masalah. tp klo dibahasa C/C++ bisa error
        pilihan = input_int("Masukkkan Menu")
        if fnb == 1:
            harga = 5000
        elif fnb == 2:
            harga = 5000
        elif fnb == 3:
            harga = 5000
        elif fnb == 4:
            harga = 7000
        elif fnb == 5:
            harga = 8000
        elif fnb == 6:
            harga = 3000
        elif fnb == 7:
            harga = 3000
        elif fnb == 8:
            harga = 3000
        elif fnb == 9:
            break
        else:
            print("=====Menu Tidak Tersedia,Silahkan Pilih Menu Lainnya!!=====")
            continue

        jumlah_pembelian = input_int("Masukan Jumlah Pembelian : ")
        totalHarga += jumlah_pembelian * harga

    return totalharga


def akun():  # cek lagi logikanya belum masuk

    def ubahpass():
        pass_lama = input("Masukkan Password Lama Akun Anda\n>> ")
        if pass_lama is data_password:
            pass_baru = input("Masukkan Password Baru\n>> ")
            while not (len(pass_baru) >= 8 and pass_baru.isalnum()):
                print(
                    "Masukkan password dengan minimal 8 karakter dengan kombinasi angka dan huruf")
                pass_baru = input("\nMasukkan password Anda \n>> ")
        data_password[0] = pass_baru

    def ubahemail():
        email_lama = input("Masukkan Email Lama Akun Anda\n>> ")
        if email_lama is data_email:
            email_baru = input("Masukkan Email Baru\n>> ")
            harus_ada1 = "@gmail.com"
            while not (harus_ada1 in email):
                print("Masukkan email Google yang benar!")
                email = input("\nMasukkan email Google Anda \n>> ")
        data_email[0] = email_baru

    def hapusakun():
        print("")

    print("---------- PENGATURAN AKUN ----------")
    print("[1] Ubah Kata Sandi")
    print("[2] Ubah Email")
    print("[3] Hapus Akun")
    print("[4] Keluar")

    pilih4 = int(input("Silakan pilih\n>> "))
    while True:  # ini diganti while True aja. semua nilai yang bukan 0 itu sifatnya True. jadi nilai 4 sama aja dengan True. penggunaan angka 4 di while itu gk biasa. standarnya make 1/0 atau True/False
        if pilih4 == 1:
            ubahpass()
        elif pilih4 == 2:
            ubahemail()
        elif pilih4 == 3:
            hapusakun()
        elif pilih4 == 4:
            return  # exit dari menu lain pake return biar balik ke menu awal. klo pake yg sebelumnya bakalan infinite loop


# Perintah Run
if __name__ == "__main__":
    # sebelum login dan setelah login bisa dijadikan satu.
    nama = ""
    while not keluar:
        print("===== Internet Billing Cafe =====\n\n")
        # ini pake ternary operator. jadi ketika logged TRUE jalanin menu_awal() ketika FALSE menu_utama(nama)
        menu_awal() if not logged else menu_utama(nama)

        pilih1 = input_int("Silakan pilih\n>> ")

        while not logged:
            if pilih1 == 1:
                nama = masuk()
                logged = True
                break
            elif pilih1 == 2:
                daftar()
                break
            elif pilih1 == 3:
                print("\n"*100)
                keluar = True
                break
            else:
                print("Maaf pilihan yang dimasukkan tidak terdaftar")
                print("Coba lagi [Y/N] ?")
                coba = input().upper()
                if coba == "Y":
                    break
                else:
                    print("\n"*100)
                    keluar = True
                    break

        else:
            if pilih1 == 1:
                member()
            elif pilih1 == 2:
                transaksi()
            elif pilih1 == 3:
                akun()
            elif pilih1 == 4:
                logged = False
            elif pilih1 == 5:
                print("Maaf pilihan yang dimasukkan tidak terdaftar")
                print("Coba lagi [Y/N] ?")
                coba = input().upper()
                if coba == "Y":
                    break
                else:
                    print("\n"*100)
                    keluar = True
                    break

    else:
        print("Terima kasih telah menggunakan program ini!")
