def persamaan(x):
    return 2*pow(x, 2) - 5*x + 2


def bisection(pers, xl, xu, maxiter=100000):
    for i in range(1, maxiter + 1):
        xr = (xl + xu) / 2
        temp = pers(xl) * pers(xr)
        if temp < 0:
            xu = xr
        elif temp > 0:
            xl = xr
        else:
            print("Iterasi ke " + str(i))
            return xr

    print("Pencarian dengan metode bisection gagal")
    return None


def falsi(pers, xl, xu, maxiter=100000):
    for i in range(1, maxiter + 1):
        xr = xl - (xu-xl) * pers(xl)/(pers(xu) - pers(xl))
        temp = pers(xl) * pers(xr)
        if temp < 0:
            xu = xr
        elif temp > 0:
            xl = xr
        else:
            print("Iterasi ke " + str(i))
            return xr

    print("Pencarian dengan metode bisection gagal")
    return None


while(True):
    xl = float(input("Masukkan batas bawah: "))
    xu = float(input("Masukkan batas atas: "))
    maxiter = input("Masukkkan maksimum iterasi (default=100000): ")

    if(maxiter != ''):
        print(falsi(persamaan, xl, xu, int(maxiter)))
    else:
        print(falsi(persamaan, xl, xu))
