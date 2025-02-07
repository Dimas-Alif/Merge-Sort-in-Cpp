def tambah(a, b):
    return a + b

def kurang(a, b):
    return a - b

def kali(a, b):
    return a * b

def bagi(a, b):
    if b == 0:
        return "Error! Tidak bisa dibagi dengan nol."
    return a / b

while True:
    print("\n=== Kalkulator Sederhana ===")
    print("1. Penjumlahan")
    print("2. Pengurangan")
    print("3. Perkalian")
    print("4. Pembagian")
    print("5. Keluar")

    pilihan = input("Pilih operasi (1/2/3/4/5): ")

    if pilihan == '5':
        print("Terima kasih! Keluar dari program.")
        break

    if pilihan in ['1', '2', '3', '4']:
        try:
            angka1 = float(input("Masukkan angka pertama: "))
            angka2 = float(input("Masukkan angka kedua: "))

            if pilihan == '1':
                print(f"Hasil: {tambah(angka1, angka2)}")
            elif pilihan == '2':
                print(f"Hasil: {kurang(angka1, angka2)}")
            elif pilihan == '3':
                print(f"Hasil: {kali(angka1, angka2)}")
            elif pilihan == '4':
                print(f"Hasil: {bagi(angka1, angka2)}")
        except ValueError:
            print("Error! Masukkan angka yang valid.")
    else:
        print("Pilihan tidak valid! Silakan pilih kembali.")
