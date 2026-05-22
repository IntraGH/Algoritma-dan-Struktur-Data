#include <iostream>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sstream>
#include <string>

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

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main()
{
    menu:
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"======================================"<<endl;
    cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan Head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    system("clear");
    if(menu==1){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"==============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang (Hapus ke-N)"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Reset (Clear Bergantian)"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pil;

            switch(pil) {
            case 1: tambahDepanH(); break;
            case 2: tambahBelakangH(); break;
            case 3: tampilkanH(); break;
            case 4: hapusDepanH(); break;
            case 5: hapusBelakangH(); break;
            case 6: hapusTargetH(); break;
            case 7: clearH(); break;
            case 8: system("clear"); goto menu;
            default: break;
            }

            cout<<"\n<press any key to continue>"<<endl;
            getch();
            system("clear");

        } while (pil!=8);
    } else if(menu==2){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"==============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang (Hapus ke-N)"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Reset (Clear Bergantian)"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pil;
    
            switch(pil) {
            case 1: tambahDepanHT(); break;
            case 2: tambahBelakangHT(); break;
            case 3: tampilkanHT(); break;
            case 4: hapusDepanHT(); break;
            case 5: hapusBelakangHT(); break;
            case 6: hapusTargetHT(); break;
            case 7: clearHT(); break;
            case 8: system("clear"); goto menu;
            default: break;
            }
    
            cout<<"\npress any key to continue"<<endl;
            getch();
            system("clear");
    
        } while (pil!=8);
    } else {
        cout<<"\nTERIMA KASIH"<<endl;
        cout<<"Program was made by Aufa Thariq Akram (2510817310014)."<<endl;
    }
}

void initH() { head = NULL; }
void initHT() { head = NULL; tail = NULL; }
int isEmptyH() { if(head == NULL) return 1; else return 0; }
int isEmptyHT() { if(tail == NULL) return 1; else return 0; }

void tambahDepanH() {
    cout<<"Masukkan data (pisahkan spasi untuk multi-data) : ";
    cin >> ws; getline(cin, dataBaru);
    stringstream ss(dataBaru); string token;
    TNode *newHead = NULL, *newTail = NULL;
    
    while(ss >> token) {
        TNode *baru = new TNode;
        baru->data = token; baru->next = NULL; baru->prev = NULL;
        if(!newHead) { newHead = newTail = baru; } 
        else { newTail->next = baru; baru->prev = newTail; newTail = baru; }
    }
    
    if(newHead != NULL) {
        if (isEmptyH() == 1) { head = newHead; } 
        else { newTail->next = head; head->prev = newTail; head = newHead; }
        cout << "Data berhasil dimasukkan di bagian depan sesuai urutan input.\n";
    }
}

void tambahDepanHT() {
    cout<<"Masukkan data (pisahkan spasi untuk multi-data) : ";
    cin >> ws; getline(cin, dataBaru);
    stringstream ss(dataBaru); string token;
    TNode *newHead = NULL, *newTail = NULL;
    
    while(ss >> token) {
        TNode *baru = new TNode;
        baru->data = token; baru->next = NULL; baru->prev = NULL;
        if(!newHead) { newHead = newTail = baru; } 
        else { newTail->next = baru; baru->prev = newTail; newTail = baru; }
    }
    
    if(newHead != NULL) {
        if(isEmptyHT() == 1) { head = newHead; tail = newTail; } 
        else { newTail->next = head; head->prev = newTail; head = newHead; }
        cout << "Data berhasil dimasukkan di bagian depan sesuai urutan input.\n";
    }
}

void tambahBelakangH() {
    cout<<"Masukkan data (pisahkan spasi untuk multi-data) : ";
    cin >> ws; getline(cin, dataBaru);
    stringstream ss(dataBaru); string token;
    TNode *newHead = NULL, *newTail = NULL;
    
    while(ss >> token) {
        TNode *baru = new TNode;
        baru->data = token; baru->next = NULL; baru->prev = NULL;
        if(!newHead) { newHead = newTail = baru; } 
        else { newTail->next = baru; baru->prev = newTail; newTail = baru; }
    }
    
    if(newHead != NULL) {
        if(isEmptyH() == 1) { head = newHead; } 
        else {
            TNode *bantu = head;
            while(bantu->next != NULL) bantu = bantu->next;
            bantu->next = newHead;
            newHead->prev = bantu;
        }
        cout << "Data berhasil dimasukkan di bagian belakang sesuai urutan input.\n";
    }
}

void tambahBelakangHT() {
    cout<<"Masukkan data (pisahkan spasi untuk multi-data) : ";
    cin >> ws; getline(cin, dataBaru);
    stringstream ss(dataBaru); string token;
    TNode *newHead = NULL, *newTail = NULL;
    
    while(ss >> token) {
        TNode *baru = new TNode;
        baru->data = token; baru->next = NULL; baru->prev = NULL;
        if(!newHead) { newHead = newTail = baru; } 
        else { newTail->next = baru; baru->prev = newTail; newTail = baru; }
    }
    
    if(newHead != NULL) {
        if(isEmptyHT() == 1) { head = newHead; tail = newTail; } 
        else { tail->next = newHead; newHead->prev = tail; tail = newTail; }
        cout << "Data berhasil dimasukkan di bagian belakang sesuai urutan input.\n";
    }
}

void tampilkanH() {
    TNode *bantu = head;
    if(isEmptyH() == 0) {
        while(bantu != NULL) {
            cout<<bantu->data<<' '; 
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List.\n";
}

void tampilkanHT() {
    TNode *bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != NULL) {
            cout<<bantu->data<<' '; 
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List.\n";
}

void hapusDepanH() {
    if(isEmptyH() == 0) {
        TNode *hapus = head; string data = hapus->data;
        if(head->next != NULL) { head = head->next; head->prev = NULL; } 
        else { initH(); }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.\n";
    } else cout<<"Tidak terdapat data pada Linked List.\n";
}

void hapusDepanHT() {
    if(isEmptyHT() == 0) {
        TNode *hapus = head; string data = hapus->data;
        if(head->next != NULL) { head = head->next; head->prev = NULL; } 
        else { initHT(); }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.\n";
    } else cout<<"Tidak terdapat data pada Linked List.\n";
}

void hapusBelakangH() {
    if(isEmptyH() == 1) { cout<<"Tidak terdapat data pada Linked List.\n"; return; }
    int n; cout<<"Masukkan N (hapus node ke-N dari belakang) : "; cin>>n;
    
    int count = 0; TNode* bantu = head; TNode* tempTail = NULL;
    while(bantu != NULL) { count++; if(bantu->next == NULL) tempTail = bantu; bantu = bantu->next; }
    
    int pos = n % count;
    if(pos == 0) pos = count;
    
    bantu = tempTail;
    for(int i = 1; i < pos; i++) bantu = bantu->prev;
    
    string dataHapus = bantu->data;
    if(bantu == head && bantu->next == NULL) { head = NULL; } 
    else if(bantu == head) { head = head->next; head->prev = NULL; } 
    else if(bantu->next == NULL) { bantu->prev->next = NULL; } 
    else { bantu->prev->next = bantu->next; bantu->next->prev = bantu->prev; }
    
    delete bantu;
    cout<<"Node ke-"<<n<<" dari belakang (\""<<dataHapus<<"\") berhasil dihapus.\n";
}

void hapusBelakangHT() {
    if(isEmptyHT() == 1) { cout<<"Tidak terdapat data pada Linked List.\n"; return; }
    int n; cout<<"Masukkan N (hapus node ke-N dari belakang) : "; cin>>n;
    
    int count = 0; TNode *bantu = head;
    while(bantu != NULL) { count++; bantu = bantu->next; }
    
    int pos = n % count;
    if(pos == 0) pos = count;
    
    bantu = tail;
    for(int i = 1; i < pos; i++) bantu = bantu->prev;
    
    string dataHapus = bantu->data;
    if(bantu == head && bantu == tail) { head = tail = NULL; } 
    else if(bantu == head) { head = head->next; head->prev = NULL; } 
    else if(bantu == tail) { tail = tail->prev; tail->next = NULL; } 
    else { bantu->prev->next = bantu->next; bantu->next->prev = bantu->prev; }
    
    delete bantu;
    cout<<"Node ke-"<<n<<" dari belakang (\""<<dataHapus<<"\") berhasil dihapus.\n";
}

void hapusTargetH() {
    if(isEmptyH() == 1) { cout << "Linked list kosong.\n"; return; }
    cout << "Masukkan data target yang ingin dihapus: ";
    string target; cin >> ws; getline(cin, target);
    
    TNode *bantu = head; int countDeleted = 0;
    while(bantu != NULL) {
        if(bantu->data == target) {
            TNode *hapus = bantu;
            if(bantu == head) {
                head = head->next;
                if(head != NULL) head->prev = NULL;
                bantu = head; 
            } else {
                bantu->prev->next = bantu->next;
                if(bantu->next != NULL) bantu->next->prev = bantu->prev;
                bantu = bantu->next;
            }
            delete hapus; countDeleted++;
        } else { bantu = bantu->next; }
    }
    
    if(countDeleted > 0) cout << "Berhasil menghapus " << countDeleted << " node dengan data \"" << target << "\".\n";
    else cout << "Pesan: Data \"" << target << "\" tidak ditemukan.\n";
}

void hapusTargetHT() {
    if(isEmptyHT() == 1) { cout << "Linked list kosong.\n"; return; }
    cout << "Masukkan data target yang ingin dihapus: ";
    string target; cin >> ws; getline(cin, target);
    
    TNode *bantu = head; int countDeleted = 0;
    while(bantu != NULL) {
        if(bantu->data == target) {
            TNode *hapus = bantu;
            if(bantu == head && bantu == tail) { head = tail = NULL; bantu = NULL; } 
            else if(bantu == head) { head = head->next; head->prev = NULL; bantu = head; } 
            else if(bantu == tail) { tail = tail->prev; tail->next = NULL; bantu = NULL; } 
            else { bantu->prev->next = bantu->next; bantu->next->prev = bantu->prev; bantu = bantu->next; }
            delete hapus; countDeleted++;
        } else { bantu = bantu->next; }
    }
    
    if(countDeleted > 0) cout << "Berhasil menghapus " << countDeleted << " node dengan data \"" << target << "\".\n";
    else cout << "Pesan: Data \"" << target << "\" tidak ditemukan.\n";
}

void clearH() {
    int urutan = 1;
    while(head != NULL) {
        TNode *hapusDepan = head;
        cout << "Penghapusan urutan " << urutan++ << " : " << hapusDepan->data << "\n";
        if(head->next == NULL) { head = NULL; delete hapusDepan; break; }
        head = head->next; head->prev = NULL; delete hapusDepan;

        TNode *hapusBelakang = head;
        while(hapusBelakang->next != NULL) hapusBelakang = hapusBelakang->next;
        cout << "Penghapusan urutan " << urutan++ << " : " << hapusBelakang->data << "\n";
        if(hapusBelakang->prev == NULL) { head = NULL; } 
        else { hapusBelakang->prev->next = NULL; }
        delete hapusBelakang;
    }
    cout << "\nSeluruh data telah dibersihkan secara bergantian.\n";
}

void clearHT() {
    int urutan = 1;
    while(head != NULL) {
        TNode *hapusDepan = head;
        cout << "Penghapusan urutan " << urutan++ << " : " << hapusDepan->data << "\n";
        if(head == tail) { head = tail = NULL; delete hapusDepan; break; }
        head = head->next; head->prev = NULL; delete hapusDepan;

        TNode *hapusBelakang = tail;
        cout << "Penghapusan urutan " << urutan++ << " : " << hapusBelakang->data << "\n";
        if(head == tail) { head = tail = NULL; delete hapusBelakang; break; }
        tail = tail->prev; tail->next = NULL; delete hapusBelakang;
    }
    cout << "\nSeluruh data telah dibersihkan secara bergantian.\n";
}