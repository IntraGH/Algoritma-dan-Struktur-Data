#include <iostream>
#define max 5 

using namespace std;

struct Tumpukan {
    int atas = -1;      
    int data[max];      
} Tumpuk;

int kosong() {
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh() {
    if (Tumpuk.atas == max - 1)
        return 1;
    else
        return 0;
}

void input(int data_baru) {
    if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data_baru;
        cout << "Data " << data_baru << " berhasil dimasukkan ke Stack." << endl;
    } else {
        cout << "Tumpukan Penuh! Tidak dapat menambah data." << endl;
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " telah dihapus dari tumpukan." << endl;
        Tumpuk.atas--;
    } else {
        cout << "Data Kosong!" << endl;
    }
}

void tampil() {
    if (kosong() == 0) {
        cout << "Isi Tumpukan saat ini:" << endl;
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    } else {
        cout << "Tumpukan Kosong!" << endl;
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan telah dibersihkan!" << endl;
}

int main() {
    int pilihan, nilai;

    do {
        cout << "\n=== MENU STACK ===" << endl;
        cout << "1. Input Data (Push)" << endl;
        cout << "2. Hapus Data (Pop)" << endl;
        cout << "3. Tampil Data" << endl;
        cout << "4. Bersihkan Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> nilai;
                input(nilai);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}