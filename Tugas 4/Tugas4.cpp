#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->kiri = NULL;
    baru->kanan = NULL;
    return baru;
}

Node* insertBST(Node* root, int nilai) {
    if (root == NULL) {
        return buatNode(nilai);
    }
    
    if (nilai < root->data) {
        root->kiri = insertBST(root->kiri, nilai);
    } else if (nilai > root->data) {
        root->kanan = insertBST(root->kanan, nilai);
    }
    
    return root;
}

int hitungJarakTerjauh(Node* node, int& jarakMaksimal) {
    if (node == NULL) {
        return 0; 
    }
    
    int tinggiKiri = hitungJarakTerjauh(node->kiri, jarakMaksimal);
    int tinggiKanan = hitungJarakTerjauh(node->kanan, jarakMaksimal);
    
    int jarakLewatSini = tinggiKiri + tinggiKanan;
    
    if (jarakLewatSini > jarakMaksimal) {
        jarakMaksimal = jarakLewatSini;
    }
    
    if (tinggiKiri > tinggiKanan) {
        return tinggiKiri + 1;
    } else {
        return tinggiKanan + 1;
    }
}

int main() {
    int n;
    
    cout << "=== INPUT ===\n";
    cout << "Masukkan jumlah elemen (N) : ";
    cin >> n;
    
    Node* akar = NULL;
    
    cout << "Masukkan " << n << " elemen (pisahkan spasi) : ";
    for (int i = 0; i < n; i++) {
        int angka;
        cin >> angka;
        akar = insertBST(akar, angka);
    }
    
    int jarakMaksimal = 0;
    
    hitungJarakTerjauh(akar, jarakMaksimal);
    
    cout << "\n=== OUTPUT ===\n";
    cout << "Jarak terjauh maksimal : " << jarakMaksimal << "\n";
    
    return 0;
}