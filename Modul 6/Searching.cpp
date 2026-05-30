#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <termios.h>
#include <unistd.h>

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

void sequentialSearch(vector<int> &nums, int target) {
    int counter = 0;
    int lastIndex = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            counter++;
            lastIndex = i;
        }
    }

    if (counter > 0) {
        cout << "Data ditemukan sebanyak " << counter << " kali.\n";
        cout << "Kemunculan terakhir pada indeks ke-" << lastIndex << ".\n";
    } else {
        cout << "Data tidak ditemukan!\n";
    }
}

void binarySearch(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    cout << "Data setelah diurutkan:\n";
    cout << "Data: ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    int kiri = 0, kanan = nums.size() - 1;
    bool ketemu = false;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (nums[tengah] == target) {
            ketemu = true;
            break;
        } else if (target < nums[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu) {
        cout << "Angka ditemukan!" << endl;
    } else {
        cout << "Angka tidak ditemukan!" << endl;
    }
}

void clearScreen() {
    system("clear");
}

// MODIFIKASI: Fungsi explain() dirombak total menggunakan gaya penjelasan baru
void explain() {
    cout << "\n=======================================================\n";
    cout << "      KONSEP DASAR SEQUENTIAL & BINARY SEARCHING\n";
    cout << "=======================================================\n\n";

    cout << "[A] SEQUENTIAL SEARCH (Pencarian Linear)\n";
    cout << "Analogi: Seperti mencari sebuah buku spesifik di dalam tumpukan\n";
    cout << "         kardus yang berantakan dengan mengeceknya satu per satu.\n";
    cout << "Cara Kerja:\n";
    cout << "- Algoritma menyisir data dari elemen paling awal (indeks 0)\n";
    cout << "  sampai elemen paling akhir secara berurutan.\n";
    cout << "Kelebihan:\n";
    cout << "  * Sangat fleksibel! Data boleh dalam kondisi acak atau tidak terurut.\n";
    cout << "Kekurangan:\n";
    cout << "  * Sangat lambat untuk data berskala besar (kompleksitas O(n)).\n";
    cout << "    Bayangkan mengecek 1 juta data satu per satu dari awal.\n\n";

    cout << "[B] BINARY SEARCH (Pencarian Bagi Dua)\n";
    cout << "Analogi: Seperti mencari nama orang di dalam buku telepon.\n";
    cout << "         Kita langsung buka bagian tengah, lalu menebak apakah\n";
    cout << "         namanya ada di paruh kiri atau kanan, begitu seterusnya.\n";
    cout << "Cara Kerja:\n";
    cout << "- Syarat mutlak: Data WAJIB diurutkan (sorting) terlebih dahulu.\n";
    cout << "- Algoritma akan membelah rentang pencarian menjadi dua bagian,\n";
    cout << "  mengecek nilai tengah, lalu membuang separuh data yang tidak relevan.\n";
    cout << "Kelebihan:\n";
    cout << "  * Performa super kilat dan efisien (kompleksitas O(log n)).\n";
    cout << "  * Mencari dari 1 juta data maksimal hanya butuh 20 kali tebakan.\n";
    cout << "Kekurangan:\n";
    cout << "  * Tidak bisa langsung dipakai pada data yang masih acak.\n\n";

    cout << "* KESIMPULAN PENGGUNAAN:\n";
    cout << "Gunakan Sequential Search jika jumlah data sedikit atau sering berubah-ubah.\n";
    cout << "Gunakan Binary Search jika data berukuran masif dan sudah terstruktur rapi.\n";
    cout << "=======================================================\n";
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums(100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = dist(rng);
                }

                cout << "100 data acak telah dibuat:\n";
                cout << "Data: ";
                for (int val : nums) {
                    cout << val << " ";
                }
                cout << "\n";

                cout << "Masukkan angka yang ingin dicari: ";
                cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = dist(rng);
                }

                cout << size << " data acak telah dibuat:\n";
                cout << "Data: ";
                for (int val : nums) {
                    cout << val << " ";
                }
                cout << "\n";

                cout << "Masukkan angka yang ingin dicari: ";
                cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Program dibuat oleh Aufa Thariq Akram (2510817310014)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}