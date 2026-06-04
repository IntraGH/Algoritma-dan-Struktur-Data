#include <iostream>
#include <random>

using namespace std;

void manualSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, X;

    cout << "Masukkan N (jumlah elemen) dan X (target penjumlahan): ";
    cin >> N >> X;

    if (N < 10) {
        cout << "Error: N harus lebih besar atau sama dengan 10 sesuai instruksi.\n";
        return 0;
    }

    int* arr = new int[N]; 

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 25);

    cout << "\n=== DATA ARRAY ACAK (1 - 25) ===\n";
    cout << "Sebelum Diurutkan : ";
    for (int i = 0; i < N; i++) {
        arr[i] = dist(gen);
        cout << arr[i] << " ";
    }
    cout << "\n";

    manualSort(arr, N);

    cout << "Setelah Diurutkan : ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n================================\n\n";

    int totalPasangan = 0;

    for (int i = 0; i < N - 1; i++) {
        int targetCari = X - arr[i]; 
        
        int kiri = i + 1;
        int kanan = N - 1;
        int foundIdx = -1;

        while (kiri <= kanan) {
            int tengah = kiri + (kanan - kiri) / 2;

            if (arr[tengah] == targetCari) {
                foundIdx = tengah;
                break; 
            } else if (arr[tengah] < targetCari) {
                kiri = tengah + 1;
            } else {
                kanan = tengah - 1;
            }
        }

        if (foundIdx != -1) {
            totalPasangan++;

            int temp = foundIdx - 1;
            while (temp > i && arr[temp] == targetCari) {
                totalPasangan++;
                temp--;
            }

            temp = foundIdx + 1;
            while (temp < N && arr[temp] == targetCari) {
                totalPasangan++;
                temp++;
            }
        }
    }

    cout << "Output: \n";
    cout << totalPasangan << "\n";
    cout << "(Artinya ada " << totalPasangan << " pasangan elemen berbeda yang jika dijumlahkan hasilnya " << X << ")\n";

    delete[] arr; 

    return 0;
}