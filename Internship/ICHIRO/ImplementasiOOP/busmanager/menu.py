from .Bus import *


def manageDetail(busName):
    print(chr(27) + "[2J")
    textFrame(var.myBus[busName].nama)
    print("Spesifikasi: \nManufacture: {}\nJumlah Kursi: {}\nHarga Jual: {}".format(
        var.myBus[busName].manufacture, var.myBus[busName].kursi, printUang(var.myBus[busName].harga*0.8)))

    print("1. Jual")

    while True:
        c = input("Pilih: ")
        if c == "1":
            sellBus(busName)
            break
        else:
            print("Pilihan tidak ditemukan")


def manageBus():
    print(chr(27) + "[2J")
    n = 1

    textFrame("Kelola Bus")
    if len(var.myBus.keys()) == 0:
        print("Anda belum memiliki bus")
    else:
        for bus in var.myBus.keys():
            print("{}. {}".format(n, bus))
            n += 1
        print("{}. Keluar".format(n))

        while True:
            try:
                c = int(input("Masukkan pilihan: "))
            except ValueError:
                print("Masukkan berupa angka")
                continue
            if c <= len(var.myBus.keys()):
                manageDetail(list(var.myBus.keys())[c-1])
                break
            elif c == len(var.myBus.keys())+1:
                break
            else:
                print("Pilihan tidak ditemukan")
                continue


def buyBusMenu():
    print(chr(27) + "[2J")
    textFrame("Dealer Bus")
    n = 1
    for i in busDealer.keys():
        print("{}. {}".format(n, i))
        n += 1

    print("{}. Kembali".format(n))

    while True:
        try:
            c = int(input("Masukkan pilihan: "))
        except ValueError:
            print("Masukkan berupa angka")
            continue
        if c <= len(busDealer):
            busDetailMenu(list(busDealer.keys())[c-1])
            break
        elif c == len(busDealer)+1:
            break
        else:
            print("Pilihan tidak ditemukan")
            continue


def checkoutBus(modelName):
    print(chr(27) + "[2J")
    jalur = []
    ongkos = []
    ongkosin = 0
    prevKota = ""

    nama = input("Masukkan nama bus: ")
    supir = input("Masukkan nama supir: ")
    print("Masukkan 3 kota yang akan dilalui oleh bus")
    for i in range(3):
        while True:
            kota = input("Masukkan Nama Kota: ")
            if kota in jalur:
                print("Kota sudah dimasukkan")
                continue
            if i > 0:
                try:
                    ongkosin = int(
                        input("Masukkan ongkos dari {} ke {}: ".format(prevKota, kota)))
                except ValueError:
                    print(
                        "Ongkos yang dimasukkan bukan berupa angka silahkan masukkan kembali kota")
                    continue
            prevKota = kota
            break

        jalur.append(kota)
        ongkos.append(ongkosin)

    var.myBus[nama] = busDealer[modelName](nama, supir, jalur, ongkos)
    var.balance -= busDealer[modelName].harga


def busDetailMenu(modelName):
    print(chr(27) + "[2J")
    textFrame(busDealer[modelName].model)
    print("Spesifikasi: \nManufacture: {}\nJumlah Kursi: {}\nHarga: {}".format(
        busDealer[modelName].manufacture, busDealer[modelName].kursi, printUang(busDealer[modelName].harga)))
    print("\nKas: {}". format(printUang(hitungKas())))

    while True:
        c = input("Apakah anda ingin membelinya? (Y/N) ").lower()
        if c == 'y':
            if hitungKas() - busDealer[modelName].harga < 0:
                print("Maaf uang anda tidak mencukupi")
                continue
            else:
                checkoutBus(modelName)
                break
        elif c == 'n':
            break
        else:
            print("Pilihan tidak ditemukan")


def inputNaik(busName):
    print("Masukkan nama penumpang, akhiri dengan 0 jika selesai")
    while True:
        namaPenumpang = input("Input: ")
        if namaPenumpang == "0":
            break
        var.myBus[busName].naik(namaPenumpang)


def inputTurun(busName):
    print("Masukkan nama penumpang, akhiri dengan 0 jika selesai")
    while True:
        namaPenumpang = input("Input: ")
        if namaPenumpang == "0":
            break
        var.myBus[busName].turun(namaPenumpang)


def menuNaikTurun(naik):
    print(chr(27) + "[2J")
    n = 1

    print("Tambah penumpang pada bus" if naik else "Turnunkan penumpang dari bus")
    for bus in var.myBus.keys():
        print("{}. {}".format(n, bus))
        n += 1
    print("{}. Keluar".format(n))
    while True:
        try:
            c = int(input("Masukkan pilihan: "))
        except ValueError:
            print("Masukkan berupa angka")
        if c <= len(var.myBus.keys()):
            inputNaik(list(var.myBus.keys())[
                      c-1]) if naik else inputTurun(list(var.myBus.keys())[c-1])
            break
        elif c == len(var.myBus.keys())+1:
            break
        else:
            print("Pilihan tidak ditemukan")


def goBus():
    print(chr(27) + "[2J")
    while True:
        if (len(var.myBus) == 0):
            print("Anda tidak memiliki bus")
            break
        elif (var.pos == 1 and var.back) or (var.pos == 3 and not var.back):
            turunAll()
            var.back = True
            break
        else:
            for nama in var.myBus.keys():
                print("Bus {} (id={}) berada di stasiun {}".format(
                    nama, var.myBus[nama].id, var.myBus[nama].jalur[var.pos-1]))
            print("1. Naikkan penumpang\n2. Turunkan penumpang\n3. Lanjut")
            while True:
                c = input("Pilih: ")
                if c == "1":
                    menuNaikTurun(True)
                    break
                elif c == "2":
                    menuNaikTurun(False)
                    break
                elif c == "3":
                    var.pos = var.pos + 1 if not var.back else var.pos - 1
                    break
                else:
                    print("Pilihan tidak ditemukan")


def mainmenu():
    textFrame("Bus Manager")
    print("Kas {}".format(printUang(hitungKas())))
    print("1. Kelola Bus\n2. Beli Bus\n3. Jalan\n4. Save data")
    while True:
        c = input("Pilih: ")
        if c == "1":
            manageBus()
            break
        elif c == "2":
            buyBusMenu()
            break
        elif c == "3":
            goBus()
            break
        elif c == "4":
            packData()
        else:
            print("Pilihan tidak ditemukan")
