# Implementasi OOP
<b>Nama:</b> Akhmad Thoriq Afif </br>
<b>NRP:</b> 5024201028 </br>
<b>Jurusan:</b> Teknik Komputer </br></br>
<i>Repositori ini dibuat untuk memenuhi tugas magang tim robotik ICHIRO ITS</i>
## Overview
Program ini berjudul <b><i>Bus Manager</i></b>. Merupakan sebuah program untuk me-<i>manage</i> sebuah perusahaan otobus.

## Penjelasan Class
### 1. Class Bus
Class ini berfungsi untuk menampung atribut-atribut dan fungsi umum yang terdapat dalam bus, yaitu:
+ `id` berfungsi sebagai penanda dari objek yang telah dibuat. `id` ini akan terus bertambah seiring pertambahan objek.
+ `nama` merupakan nama dari bus yang dibuat. Setiap bus diharuskan memiliki `nama` yang berbeda-beda agar tidak terjadi conflict dengan objek lain.
+ `supir` merupakan nama dari supir bus
+ `jalur` merupakan jalur yang dilalui oleh bus. `jalur` ini berupa list.
+ `ongkos` merupakan ongkos dari kota n-1 ke n. `ongkos` ini berupa list.
+ `penumpang` merupakan <i>list</i> yang berisikan nama-nama penumpang bus.
+ `penumpangFlag` merupakan penanda untuk penumpang dari pos mana mereka naik. `penumpangFlag` ini akan digunakan untuk menghitung ongkos perjalanan.
+ `__init__(nama, supir, jalur, ongkos)` berfungsi sebagai constructor dari class. Pada constructor ini diperlukan parameter berupa nama, supir, jalur, dan ongkos. yang kemudian paremeter tersebut akan dijadikan sebagai atribut dari objek.
+ `__del__` berfungsi ketika bus dijual
+ `hitungOngkos(penumpang)` berfungsi untuk menghitung ongkos perjalanan penumpang. Cara kerja dari fungsi ini adalah dengan mengambil parameter nama `penumpang` yang akan diturunkan kemudian dilakukan perhitungan `sum()` pada list `ongkos` dengan range antara `penumpangFlag` dengan `pos` saat diturunkan.
+ `naik(penumpang)` merupakan fungsi untuk meng-<i>append</i> nama penumpang yang akan naik. Pada fungsi ini dilakukan pengecekan terlebih dahulu ketia penumpang naik. Pengecekan berupa jumlah kursi dan nama penumpang yang akan naik.
+ `turun(penumpang, all=False)` merupakan fungsi untuk me-<i>remove</i> nama penumpang yang diinputkan dari list `penumpang`. Pada fungsi ini dilakukan pemanggilan fungsi `hitungOngkos` untuk menghitung ongkos penumpang yang kemudian ongkos tersebut ditambahkan pada `kas`.
### 2. CyberBus, VolvoBus, HinoBus (child: Bus)
Class ini merupakan <i>child</i> dari Class `Bus`. sehingga pada class ini mewarisi variabel dan method yang dimiliki oleh Class `Bus`. </br>
Pada Class child ini terdapat penambahan variabel, yaitu:
+ `model` merupakan model dari bus, <b>contoh: Tesla Cyber Bus X12</b>
+ `manufacture` merupakan perusahaan pembuat bus
+ `harga` merupakan harga dari bus
+ `kursi` merupakan jumlah kursi yang berada dalam bus. Jumlah kursi ini akan mempengaruhi seberapa banyak penumpang yang dapat naik ke bus.

| Variabel      | Tipe    |
| ------------- | ------- |
| id            | integer |
| nama          | string  |
| supir         | string  |
| jalur         | list    |
| ongkos        | list    |
| penumpang     | list    |
| penumpangFlag | list    |
| model         | string  |
| manufacture   | string  |
| harga         | integer |
| kursi         | integer |

## Alur Program
1. Pada saat pertama dijalankan, program akan menampilkan pilihan antara new dan load. Setelah memilih salah satu maka akan tampil main menu yang berisikan <b>Jumlah kas, Manage Bus, Beli Bus, Jalan, dan Save data</b>
     * <b>Jumlah Kas</b> akan ditampilan berupa text. Pada awal menjalankan program user akan diberikan kas sebesar Rp.100.000.000,00
     * Jika user memilih <b>Manage Bus</b>, maka akan ditampilkan menu berupa list dari bus yang dimiliki. Ketika salah satu bus dipilih maka akan muncul piihan <b>Jual bus</b>.
     * Jika user memilih <b>Beli Bus</b>, maka akan ditampilkan menu berupa list dari bus yang dapat dibeli.</br>Ketika user memilih salah satu bus. User akan diminta untuk menginput
       * <b>Nama bus</b> untuk nama bus ini diharuskan berbeda agar tidakk  terjadi conflict dengan bus yang lain
       * <b>Nama sopir</b>
       * <b>Kota dan ongkos antar kota</b>
     * Jika user mimilih <b>Save data</b>, maka semua data akan disimpan dalam bentuk file bernama `save.dat`. Data ini kemudian dapat diload sewaktu-waktu dengan memilih <b>Load data</b> ketika program pertama dijalankan.
2. Ketika user sudah memiliki bus untuk dijalankan. User dapat memilih <b>Jalan</b>. Kemudian akan muncul lokasi dari bus tersebut dimulai dari stasiun kota jalur pertama. Pada saat ini user akan diberi 3 pilihan <b>Naikkan penumpang, Turunkan penumpang, dan jalan</b>
   * <b>Naikkan penumpang</b>. User akan diminta untuk menginput nama-nama penumpang yang akan dinaikkan.
   * <b>Turunkan penumpang</b>. User akan diminta untuk menginput nama-nama penumpang yang akan diturunkan. Pada saat ditunkan secara otomatis ongkos perjalan penumpang akan dihitung berdasarkan lokasi penumpang naik dan lokasi penumpang turun.
   * <b>Lanjut</b>. Bus akan lanjut menuju ke kota berikutnya. Ketika bus sampai di kota terakhir, tetapi penumpang masih terdapat pada bus maka secara otomatis penumpang akan diturunkan pada kota tersebut.
## Usage
```
$ python3 main.py
```
</br>
