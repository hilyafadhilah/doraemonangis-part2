# Mobilita End Game
## Latar Belakang
> 'Mobita menjadi seorang kurir demi mencari nafkah untuk keluarganya.'  Dengan adanya pandemi COVID-19, usaha orang tua Mobita mengalami penurunan
pendapatan. Setelah diringankannya PPKM, Mobita ingin membantu orang tuanya
mendapat penghasilan menjadi seorang kurir. Tugas kalian adalah membantu Mobita
membuatkan aplikasi yang akan membantunya melacak pesanan, navigasi peta, mengambil
dan menurunkan barang.


## Deskripsi Program
Tugas Besar Mata Kuliah IF2110 Algoritma dan Struktur Data.
Permainan berbasis CLI (command-line interface) tentang pengantaran
barang. Permainan ini dibuat dalam bahasa C dengan menggunakan berbagai kumpulan struktur data.

## Direktori
    src
    ├── adt                        # Berisi ADT sederhana
    │    ├── charmachine
    │   ├── matrix
    │   ├── point
    │   ├── wordmachine
    │   └── boolean.h
    ├── adt_modified               # Berisi ADT yang sudah dimodifikasi
    │   ├── displaymap
    │   ├── gadget
    │   ├── item
    │   ├── listpointdin
    │   ├── pesanan
    │   ├── player
    │   ├── speedboost
    │   ├── stack_linked
    │   ├── tas
    │   ├── todolist
    │   └── word
    ├── modules                    # Fungsi-fungsi yang digunakan di main
    │   ├── command
    │   ├── config
    │   ├── help
    │   ├── load
    │   ├── newgame
    │   └── pcolor
    ├── config.txt                 # File config yang akan diload saat new game
    ├── <save>.txt                 # File save jika menjalankan save game
    ├── game_header.h              # Header untuk semua ADT
    ├── main_program.c             # File main program
    └── run.bat                    # File script untuk menjalankan main program

## Instalasi
(Windows)  
Jalankan `run.bat` yang terletak pada folder src di terminal vs code.  
(Linux)  
Jalankan command `gcc main_program.c -o main.exe && ./m
ain.exe` di direktori src.

## Anggota Kelompok
1.	13520002 – Muhammad Fikri Ranjabi 
2.	13520007 – Nadia Mareta Putri Leiden  
3.	13520024 – Hilya Fadhilah Imania  
4.	13520026 – Muhammad Fajar Ramadhan
5.	13520049 – Aditya Prawira Nugroho

## Pembagian Tugas
| Nama - NIM                           | Job Description                                                                                                     |
|--------------------------------------|---------------------------------------------------------------------------------------------------------------------|
| Muhammad Fikri Ranjabi - 13520002    | 1. Membuat fungsi Pick-up                                                                                           |
|                                      | 2. Membuat fungsi Drop off                                                                                          |
|                                      | 3. Membuat fungsi In-Progress                                                                                       |
|                                      | 4. Membuat impelementasi Fungsi Map, Matrix, Bangunan dan Move (Bersama Adit)                                       |
|                                      | 5. Memasukkan fungsi-fungsi di game header                                                                          |
| Nadia Mareta Putri Leiden - 13520007 | 1. Mengurus kebutuhan dokumentasi dan kelengkapan laporan                                                           |
|                                      | 2. Membuat Main program, fungsi help, implementasi input command dengan word machine                                |
|                                      | 3. Menyiapkan kebutuhan compiling: Makefile (tidak jadi dipakai), bat file, dan game header untuk menyatukan header |
| Hilya Fadhilah Imania - 13520024     | 1. Modifikasi ADT Mesin Kata / Word Machine                                                                         |
|                                      | 2. Membuat implementasi In progress (Gabungan stack + linked list)                                                  |
|                                      | 3. Membuat fungsi untuk menerima konfigurasi file, load game dan save game                                          |
| Muhammad Fajar Ramadhan - 13520026   | 1. Membuat fungsi tas dan gadget                                                                                    |
|                                      | 2. Membuat fungsi To-do-List dengan impelementasi queue                                                             |
|                                      | 3. Membuat ADT untuk daftar Pesanan                                                                                 |
|                                      | 4. Membuat fungsi buy dan inventory                                                                                 |
| Aditya Prawira Nugroho - 13520049    | 1. Membuat ADT Player (Current Player)                                                                              |
|                                      | 2. Warnain Map, dengan p color                                                                                      |
|                                      | 3. Membuat fungsi Map, Matrix, Bangunan dan Move (Bersama Ranjabi)                                                  |
|                                      | 4. Refactor fungsi                                                                                                  |
|                                      | 5. Mengimplementasikan ability                                                                                      |

## Daftar Fitur
| Daftar Fitur                            | Status Pengerjaan |
|-----------------------------------------|-------------------|
| New Game, Save Game, dan Load Game      | Selesai           |
| Mekanisme waktu                         | Selesai           |
| Pesanan                                 | Selesai           |
| To Do List                              | Selesai           |
| In Progress                             | Selesai           |
| Tas                                     | Selesai           |
| Efek Item (Heavy, Perishable)           | Selesai           |
| Ability Speedboost                      | Selesai           |
| Ability Increase Capacity               | Selesai           |
| Gadget (termasuk bonus Senter Pengecil) | Selesai           |
| Inventory                               | Selesai           |
| Peta                                    | Selesai           |
| Command MOVE, PICK_UP, DROP_OFF         | Selesai           |
| Buy Item                                | Selesai           |
| Help                                    | Selesai           |
