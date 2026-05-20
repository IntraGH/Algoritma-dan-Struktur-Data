//nama : Aufa Thariq Akram
//NIM. : 2510817310014
//implemensasi algoritma sorting dan binary search 
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int arr[] = {40, 92, 115, 72, 27, 144, 195, 140, 189, 56, 175, 180, 155, 44, 71, 18, 148, 130, 24, 88, 
                 12, 98, 69, 42, 8, 142, 152, 23, 29, 108, 75, 164, 159, 137, 167, 190, 174, 94, 187, 25, 
                 21, 58, 93, 190, 172, 179, 138, 51, 54, 181, 72, 180, 187, 91, 42, 60, 32, 24, 19, 26, 
                 2, 63, 7, 156, 98, 56, 151, 163, 166, 68, 41, 109, 59, 63, 163, 89, 76, 161, 27, 95, 
                 1, 87, 57, 21, 72, 184, 141, 196, 36, 170, 60, 118, 109, 50, 4, 198, 117, 97, 9, 155};
    int target = 198;

    sort(arr, arr + 100);
    for (int i = 0; i < 100; i++) cout << arr[i] << " ";

    cout << "\n\n";
 int left = 0, right = 99, hasil = -1;
 while(left <= right) {
 int mid = left + (right - left) / 2;
 if (arr[mid] == target) { hasil = mid; break;}
 if (arr[mid] < target) left = mid + 1;
 else right = mid - 1;
 }


 if (hasil != -1) cout << "menemukan angka " << target << " di indeks " << hasil << endl;
 else cout << "tidak menemukan angka " << target << endl;


return 0;
}