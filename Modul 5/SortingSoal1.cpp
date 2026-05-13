#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void insSort(string &arr) {
    int len = arr.length();
    for (int i = 1; i < len; i++) {
        char val = arr[i];
        int pos = i - 1;
        while (pos >= 0 && arr[pos] > val) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = val;
    }
}

void gabung(string &arr, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    
    string L = arr.substr(kiri, n1);
    string R = arr.substr(tengah + 1, n2);
    
    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mrgSort(string &arr, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        mrgSort(arr, kiri, tengah);
        mrgSort(arr, tengah + 1, kanan);
        gabung(arr, kiri, tengah, kanan);
    }
}

void shlSort(string &arr) {
    int n = arr.length();
    for (int jarak = n / 2; jarak > 0; jarak /= 2) {
        for (int i = jarak; i < n; i++) {
            char temp = arr[i];
            int j;
            for (j = i; j >= jarak && arr[j - jarak] > temp; j -= jarak) {
                arr[j] = arr[j - jarak];
            }
            arr[j] = temp;
        }
    }
}

int partisi(string &arr, int bawah, int atas) {
    char pivot = arr[atas];
    int i = (bawah - 1);
    for (int j = bawah; j < atas; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[atas]);
    return (i + 1);
}

void qckSort(string &arr, int bawah, int atas) {
    if (bawah < atas) {
        int pi = partisi(arr, bawah, atas);
        qckSort(arr, bawah, pi - 1);
        qckSort(arr, pi + 1, atas);
    }
}

void bblSort(string &arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        bool tukar = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                tukar = true;
            }
        }
        if (!tukar) break;
    }
}

void selSort(string &arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

void eksekusiSort(int pilihan, string data) {
    cout << "Data Sebelum Diurutkan : " << data << "\n";
    
    auto mulai = chrono::high_resolution_clock::now();
    string namaAlgo = "";
    
    if (pilihan == 1) { insSort(data); namaAlgo = "Insertion Sort"; }
    else if (pilihan == 2) { mrgSort(data, 0, data.length() - 1); namaAlgo = "Merge Sort"; }
    else if (pilihan == 3) { shlSort(data); namaAlgo = "Shell Sort"; }
    else if (pilihan == 4) { qckSort(data, 0, data.length() - 1); namaAlgo = "Quick Sort"; }
    else if (pilihan == 5) { bblSort(data); namaAlgo = "Bubble Sort"; }
    else if (pilihan == 6) { selSort(data); namaAlgo = "Selection Sort"; }
    
    auto selesai = chrono::high_resolution_clock::now();
    chrono::duration<double> durasi = selesai - mulai;
    
    cout << "Data Setelah Diurutkan : " << data << "\n";
    cout << fixed << setprecision(9);
    cout << "Waktu Eksekusi " << namaAlgo << " : " << durasi.count() << " detik\n";
}

int main() {
    string nama_mhs = "AufaThariqAkram";
    string nim_mhs = "2510817310014";
    int opsi;
    
    do {
        cout << "--------------------------------\n";
        cout << "            SORTING             \n";
        cout << "--------------------------------\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Shell Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Bubble Sort\n";
        cout << "6. Selection Sort\n";
        cout << "7. Exit\n";
        cout << "--------------------------------\n";
        cout << "Masukkan Pilihan : ";
        cin >> opsi;
        cout << "\n";
        
        if (opsi >= 1 && opsi <= 3) {
            eksekusiSort(opsi, nama_mhs);
        } else if (opsi >= 4 && opsi <= 6) {
            eksekusiSort(opsi, nim_mhs);
        } else if (opsi == 7) {
            cout << "Terima Kasih.\n";
            cout << "Program ini dibuat oleh Aufa Thariq Akram (2510817310014)\n";
        } else {
            cout << "Input tidak valid, silakan coba lagi.\n";
        }
        
        if (opsi != 7) {
            cout << "\nTekan sembarang tombol untuk kembali...";
            getch();
            system("clear");
        }
    } while (opsi != 7);
    
    return 0;
}