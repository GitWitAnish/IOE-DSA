#include <iostream>
using namespace std;

void deleteElement(int arr[], int& n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    cout << "Original array: ";
    printArray(arr, n);

    int pos = 2;
    deleteElement(arr, n, pos);

    cout << "Array after deletion: ";
    printArray(arr, n);

    return 0;
}