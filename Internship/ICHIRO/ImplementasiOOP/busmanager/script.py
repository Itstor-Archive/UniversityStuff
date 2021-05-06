from . import var as var
import pickle


def textFrame(text):
    print("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
    print("=" + " "*((20-len(text)//2)) + text + " "*(20-(len(text)//2)) + "=")
    print("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")


def hitungKas():
    kas = 0
    for bus in var.myBus.values():
        kas += bus.kas

    return var.balance + kas


def printUang(nominal):
    return "Rp.{:0,.2f}".format(nominal)


def sellBus(busName):
    global balance

    var.balance += var.myBus[busName].kas
    var.balance += var.myBus[busName].harga * 0.8

    del var.myBus[busName]


def turunAll():
    for bus in var.myBus.keys():
        if len(var.myBus[bus].penumpang) > 0:
            var.myBus[bus].turun("", True)


def packData():
    saveData([var.balance, var.myBus, var.pos, var.back])


def saveData(data):
    with open("save.dat", "wb") as f:
        pickle.dump(data, f)
    print("Data berhasil disimpan")


def loadData():
    try:
        with open("save.dat", "rb") as f:
            var.balance, var.myBus, var.pos, var.back = pickle.load(f)
        print("Data berhasil dibuka")
    except Exception as e:
        print("Load file gagal", e)
