#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru) {
    if (*root == NULL) {
        Node *baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        cout << "Data bertambah";
    } else if (databaru < (*root)->data) {
        tambah(&(*root)->kiri, databaru);
    } else if (databaru > (*root)->data) {
        tambah(&(*root)->kanan, databaru);
    } else {
        cout << "Data sudah ada";
    }
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main()
{
    int pil, data;
    Node *pohon;
    pohon = NULL;
    do
    {
        system("clear");
        cout << "1. Tambah\n";
        cout << "2. PreOrder\n";
        cout << "3. inOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Exit\n";
        cout << "\nPilihan : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            cout << "\n INPUT : ";
            cout << "\n -------";
            cout << "\n Data baru : ";
            cin >> data;
            tambah(&pohon, data);
            cout << "\n";
            break;
        case 2:
            cout << "\nPreOrder";
            cout << "\n------------------------\n";
            if (pohon != NULL)
            {
                preOrder(pohon);
                cout << "\n";
            }
            else
                cout << "Masih Kosong\n";
            break;
        case 3:
            cout << "\ninOrder";
            cout << "\n------------------------\n";
            if (pohon != NULL)
            {
                inOrder(pohon);
                cout << "\n";
            }
            else
                cout << "Masih Kosong\n";
            break;
        case 4:
            cout << "\nPostOrder";
            cout << "\n------------------------\n";
            if (pohon != NULL)
            {
                postOrder(pohon);
                cout << "\n";
            }
            else
                cout << "Masih Kosong\n";
            break;
        case 5:
            return 0;
        }
        getch();
    } while (pil != 5);
    return EXIT_FAILURE;
}