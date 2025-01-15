#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Kelas abstrak Reservasi
class Reservasi {
protected:
    string namaPelanggan;
    string tanggalCheckIn;
    string tanggalCheckOut;
    int totalHarga;

public:
    Reservasi(string nama, string checkIn, string checkOut)
        : namaPelanggan(nama), tanggalCheckIn(checkIn), tanggalCheckOut(checkOut), totalHarga(0) {}

    // Fungsi virtual untuk menghitung total harga
    virtual void hitungHarga() = 0;

    // Fungsi virtual untuk menampilkan informasi reservasi
    virtual void tampilkanInfo() = 0;

    // Fungsi untuk mendapatkan harga total
    int getTotalHarga() { return totalHarga; }
};

// Kelas ReservasiTamu (turunan dari Reservasi)
class ReservasiTamu : public Reservasi {
private:
    int jumlahKamar;
    int hargaPerKamar;

public:
    ReservasiTamu(string nama, string checkIn, string checkOut, int kamar, int harga)
        : Reservasi(nama, checkIn, checkOut), jumlahKamar(kamar), hargaPerKamar(harga) {}

    // Menghitung total harga untuk tamu
    void hitungHarga() override {
        totalHarga = jumlahKamar * hargaPerKamar;
    }

    // Menampilkan informasi reservasi untuk tamu
    void tampilkanInfo() override {
        cout << "Reservasi Tamu: " << namaPelanggan << endl;
        cout << "Check-in: " << tanggalCheckIn << ", Check-out: " << tanggalCheckOut << endl;
        cout << "Jumlah Kamar: " << jumlahKamar << ", Harga per Kamar: " << hargaPerKamar << endl;
        cout << "Total Harga: " << totalHarga << endl;
    }
};

// Kelas ReservasiGrup (turunan dari Reservasi)
class ReservasiGrup : public Reservasi {
private:
    int jumlahKamar;
    int hargaPerKamar;
    int diskon;

public:
    ReservasiGrup(string nama, string checkIn, string checkOut, int kamar, int harga, int diskon)
        : Reservasi(nama, checkIn, checkOut), jumlahKamar(kamar), hargaPerKamar(harga), diskon(diskon) {}

    // Menghitung total harga untuk grup dengan diskon
    void hitungHarga() override {
        totalHarga = (jumlahKamar * hargaPerKamar) - diskon;
    }

    // Menampilkan informasi reservasi untuk grup
    void tampilkanInfo() override {
        cout << "Reservasi Grup: " << namaPelanggan << endl;
        cout << "Check-in: " << tanggalCheckIn << ", Check-out: " << tanggalCheckOut << endl;
        cout << "Jumlah Kamar: " << jumlahKamar << ", Harga per Kamar: " << hargaPerKamar << endl;
        cout << "Diskon: " << diskon << endl;
        cout << "Total Harga: " << totalHarga << endl;
    }
};

int main() {
    // Membuat objek ReservasiTamu dan ReservasiGrup
    ReservasiTamu reservasiTamu("Ibnu UTP", "2025-01-20", "2025-01-25", 2, 500000);
    ReservasiGrup reservasiGrup("PT. Mencari Cinta Sejati", "2025-02-01", "2025-02-03", 10, 400000, 500000);

    // Menghitung harga untuk masing-masing reservasi
    reservasiTamu.hitungHarga();
    reservasiGrup.hitungHarga();

    // Menampilkan informasi reservasi
    cout << "\nInformasi Reservasi Tamu:" << endl;
    reservasiTamu.tampilkanInfo();

    cout << "\nInformasi Reservasi Grup:" << endl;
    reservasiGrup.tampilkanInfo();

    return 0;
}

// jadi gitu pak, tapi tolong banget pak tugasnya banyak sekaliii, sama ini belum saya coba, jadi gatau deh ini bakal error atau ngganya
