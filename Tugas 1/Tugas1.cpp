#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
} TNode;

TNode *head, *tail;

int pil;
char pilihan[10];
string dataBaru, dataDelete;

void init();
int isEmpty();

void tambahDepan();
void tambahBelakang();
void hapusDepan(int n = -1);
void hapusBelakang(int n = -1);
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main() {
    do {
        cout << "Single Linked List Circular (SLLC)" << endl;
        cout << "==================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Hapus Semua Elemen" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Hapus Setiap Data Tertentu" << endl;
        cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
        cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout << "11. Quit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch(pil) {
            case 1:
                tambahDepan();
                break;
            case 2:
                tambahBelakang();
                break;
            case 3:
                hapusDepan();
                if(!dataDelete.empty()) {
                    cout << "Data \"" << dataDelete << "\" yang dituju telah berhasil dihapus." << endl;
                }
                break;
            case 4:
                hapusBelakang();
                if(!dataDelete.empty()) {
                    cout << "Data \"" << dataDelete << "\" yang dituju telah berhasil dihapus." << endl;
                }
                break;
            case 5:
                tampilkan();
                break;
            case 6:
                reset();
                break;
            case 7:
                cariData();
                break;
            case 8:
                hapusData();
                break;
            case 9:
                sisipkanSebelum();
                break;
            case 10:
                sisipkanSetelah();
                break;
            case 11:
                cout << "\nTERIMA KASIH" << endl;
                cout << "Program was made by Aufa Thariq Akram (2510817310014)." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

        if (pil != 11) {
            cout << "\nPress Enter to continue!" << endl;
            cin.ignore(10000, '\n');
            if (cin.peek() == '\n') {
                cin.ignore();
            }
            system("clear");
        }

    } while (pil != 11);
    return 0;
}

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

void tambahDepan() {
    cout << "Masukkan data : ";
    while(cin.peek() == '\n' || cin.peek() == ' ') cin.ignore();
    getline(cin, dataBaru);
    cin.putback('\n'); 

    stringstream ss(dataBaru);
    string token;
    TNode *tempHead = NULL, *tempTail = NULL;

    while(ss >> token) {
        TNode *baru = new TNode;
        baru->data = token;
        baru->next = baru;

        if(tempHead == NULL) {
            tempHead = baru;
            tempTail = baru;
        } else {
            tempTail->next = baru;
            tempTail = baru;
        }
    }

    if(tempHead != NULL) {
        if(isEmpty() == 1) {
            head = tempHead;
            tail = tempTail;
            tail->next = head;
        } else {
            tempTail->next = head;
            head = tempHead;
            tail->next = head;
        }
        cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian depan." << endl;
    }
}

void tambahBelakang() {
    cout << "Masukkan data : ";
    TNode *baru = new TNode;
    cin >> dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty() == 1) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan dibagian belakang." << endl;
}

void hapusDepan(int n) {
    dataDelete = "";
    if(isEmpty() == 0) {
        if(n == -1) {
            cout << "Masukkan posisi node dari depan (N) : ";
            cin >> n;
        }

        int count = 0;
        TNode *bantu = head;
        do {
            count++;
            bantu = bantu->next;
        } while(bantu != head);

        if(n > count) {
            hapusBelakang(1);
            return;
        }

        if(n <= 1) {
            TNode *hapus = head;
            dataDelete = hapus->data;
            if(head != tail) {
                head = head->next;
                tail->next = head;
            } else {
                init();
            }
            delete hapus;
            return;
        }

        TNode *prev = tail;
        bantu = head;
        for(int i = 1; i < n; i++) {
            prev = bantu;
            bantu = bantu->next;
        }

        dataDelete = bantu->data;
        prev->next = bantu->next;
        if(bantu == tail) {
            tail = prev;
        }
        delete bantu;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusBelakang(int n) {
    dataDelete = "";
    if(isEmpty() == 0) {
        if(n == -1) {
            cout << "Masukkan posisi node dari belakang (N) : ";
            cin >> n;
        }

        int count = 0;
        TNode *bantu = head;
        do {
            count++;
            bantu = bantu->next;
        } while(bantu != head);

        if(n > count) {
            hapusDepan(1);
            return;
        }

        int targetPos = count - n + 1;
        if(targetPos <= 1) {
            hapusDepan(1);
            return;
        }

        TNode *prev = tail;
        bantu = head;
        for(int i = 1; i < targetPos; i++) {
            prev = bantu;
            bantu = bantu->next;
        }

        dataDelete = bantu->data;
        prev->next = bantu->next;
        if(bantu == tail) {
            tail = prev;
        }
        delete bantu;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void tampilkan() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        do {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        } while(bantu != head);
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void reset() {
    if(isEmpty() == 0) {
        TNode *bantu = head, *hapus;
        int count = 1;
        do {
            hapus = bantu;
            bantu = bantu->next;
            cout << "Proses penghapusan: Node ke-" << count << " dengan isi data \"" << hapus->data << "\" telah dihapus." << endl;
            delete hapus;
            count++;
        } while(bantu != head);

        init();
        cout << "Seluruh elemen pada Linked List telah dibersihkan." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void cariData() {
    if(isEmpty() == 0) {
        string cari;
        cout << "Masukan data yang ingin dicari : ";
        cin >> cari;

        TNode *bantu = head, *bantuTampilkan;
        bool apaDitemukan = false;

        do {
            if(cari == bantu->data) {
                cout << "Setiap data yang berada di dalam tanda kurung siku ([...]) merupakan data yang anda cari." << endl;
                cout << "Linked List : ";
                bantuTampilkan = head;

                do {
                    if(cari == bantuTampilkan->data)
                        cout << "[" << bantuTampilkan->data << "] ";
                    else
                        cout << bantuTampilkan->data << ' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while(bantuTampilkan != head);

                apaDitemukan = true;
                cout << endl;
                break;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(!apaDitemukan)
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusData() {
    if(isEmpty() == 0) {
        string cari;
        cout << "Masukkan data yang ingin dihapus : ";
        cin >> cari;

        TNode *bantu = head, *sebelum = tail, *hapusArr[225];
        int hitung = 0;
        bool apaDitemukan = false;

        do {
            if(cari == bantu->data) {
                hapusArr[hitung++] = bantu;
                apaDitemukan = true;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan) {
            for(int i = 0; i < hitung; i++) {
                if(hapusArr[i] == head) {
                    hapusDepan(1);
                } else if(hapusArr[i] == tail) {
                    hapusBelakang(1);
                } else {
                    bantu = head;
                    sebelum = tail;
                    while(bantu != hapusArr[i]) {
                        sebelum = bantu;
                        bantu = bantu->next;
                    }
                    sebelum->next = bantu->next;
                    delete bantu;
                }
            }
            cout << "Setiap data \"" << cari << "\" yang terdapat pada Linked List telah dihapus." << endl;
        } else cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSebelum() {
    if(isEmpty() == 0) {
        TNode *bantu = head, *sebelum = tail;
        string nextData;
        bool apaAda = false;

        cout << "Sisipkan data baru sebelum data : ";
        cin >> nextData;

        do {
            if(nextData == bantu->data) {
                apaAda = true;
                break;
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;

            sebelum->next = baru;
            if(bantu == head) {
                head = baru;
            }
            cout << "Data \"" << dataBaru << "\" berhasil disisipkan sebelum data \"" << nextData << "\"." << endl;
        } else {
            cout << "Tidak terdapat data \"" << nextData << "\" pada Linked List." << endl;
        }
    } else cout << "Tidak tedapat data pada Linked List." << endl;
}

void sisipkanSetelah() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        string prevData;
        bool apaAda = false;

        cout << "Sisipkan data baru setelah data : ";
        cin >> prevData;

        do {
            if(prevData == bantu->data) {
                apaAda = true;
                break;
            } else {
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;

            bantu->next = baru;
            if(bantu == tail) {
                tail = baru;
            }
            cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah data \"" << prevData << "\"." << endl;
        } else {
            cout << "Tidak terdapat data \"" << prevData << "\" pada Linked List." << endl;
        }
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}