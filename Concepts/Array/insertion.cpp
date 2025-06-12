#include <iostream>
using namespace std;

void insertElement(int arr[], int &n, int element, int position) {
    if (position < 0 || position > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the right
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element
    arr[position] = element;
    n++;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {1, 2, 4, 5}; // Initial array
    int n = 4; // Current size of the array

    cout << "Original array: ";
    printArray(arr, n);

    int element = 3, position = 2;
    insertElement(arr, n, element, position);

    cout << "Array after insertion: ";
    printArray(arr, n);

    return 0;
}