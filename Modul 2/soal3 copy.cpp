#include <iostream>
#include <stdlib.h>

#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();

int PIL, F, R;
char HURUF;
char Q[n];

void Inisialisasi() {
    F = R = -1;
}

void RESET() {
    F = R = -1;
    cout << "Queue dikosongkan" << endl;
}

void INSERT() {
    if (R == n - 1) {
        cout << "Queue Penuh!" << endl;
    } else {
        cout << "Masukkan data: ";
        cin >> HURUF;
        if (F == -1) {
            F = R = 0;
        } else {
            R++;
        }
        Q[R] = HURUF;
        cout << "Data masuk ke queue" << endl;
    }
}

void DELETE() {
    if (F == -1) {
        cout << "Queue Kosong!" << endl;
    } else {
        cout << "Data keluar: " << Q[F] << endl;
        if (F == R) {
            F = R = -1;
        } else {
            F++;
        }
    }
}

void CETAKLAYAR() {
    if (F == -1) {
        cout << "Queue kosong" << endl;
    } else {
        cout << "Isi Queue: ";
        for (int i = F; i <= R; i++) { 
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Inisialisasi();
    do {
        cout << "QUEUE" << endl;
        cout << "===============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PIL; 

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }
        
        if (PIL < 4) {
            cout << "press any key to continue" << endl;
            cin.ignore(); 
            system("clear"); 
        }
        
    } while (PIL < 4);

    return 0;
}