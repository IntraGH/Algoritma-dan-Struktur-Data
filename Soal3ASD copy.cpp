#include <iostream>
#include <string>
using namespace std;

struct DataInput {
    char huruf;
    char kata[50];
    int angka;
};

int main() {
    DataInput input;

    cout << "a. Masukkan sebuah huruf = "; 
    cin >> input.huruf;
    
    cin.ignore();
    cout << "b. Masukkan sebuah kata  = "; 
    cin.getline(input.kata, 50);
    
    cout << "c. Masukkan Angka        = "; 
    cin >> input.angka;

    cout << endl;
    cout << "d. Huruf yang Anda masukkan adalah " << input.huruf << endl;
    cout << "e. Kata yang Anda masukkan adalah " << input.kata << endl;
    cout << "f. Angka yang Anda masukkan adalah " << input.angka << endl;

    return 0;
}