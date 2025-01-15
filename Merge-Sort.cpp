#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua subarray
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Ukuran subarray kiri
    int n2 = right - mid;    // Ukuran subarray kanan

    // Buat array sementara
    vector<int> L(n1), R(n2);

    // Salin data ke array sementara
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Gabungkan array sementara ke dalam array asli
    int i = 0, j = 0, k = left;
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

    // Salin elemen yang tersisa di L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin elemen yang tersisa di R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Rekursif untuk bagian kiri dan kanan
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gabungkan bagian yang sudah diurutkan
        merge(arr, left, mid, right);
    }
}

// Fungsi utama
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Array sebelum diurutkan: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Array setelah diurutkan: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
