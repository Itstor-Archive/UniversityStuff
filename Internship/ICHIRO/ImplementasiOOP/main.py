from busmanager.script import loadData
from busmanager.var import setup
import busmanager

if __name__ == '__main__':
    while True:
        c = input("New/Load save data? (N/L) ").lower()
        if c == "n":
            setup(100000000)
            break
        elif c == "l":
            loadData()
            break

    while True:
        busmanager.mainmenu()
