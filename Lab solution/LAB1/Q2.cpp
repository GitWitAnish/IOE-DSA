// Delete a element at a given index in the array={7,9,11,13,15,17} and print the array after deletion.

#include <iostream>
using namespace std;

void deleteElement(int arr[], int& n, int index) {
    if (index < 0 || index >= n) {
        cout << "Invalid index!" << endl;
        return;
    }

    for (int i = index; i < n - 1; i++) {
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
    int arr[] = {7, 9, 11, 13, 15, 17};
    int n = 6;

    cout << "Original array: ";
    printArray(arr, n);

    int index = 2; 
    deleteElement(arr, n, index);

    cout << "Array after deletion: ";
    printArray(arr, n);

    return 0;
}
// Output:
// Original array: 7 9 11 13 15 17
// Array after deletion: 7 9 13 15 17
