// Insert a element=8 at index=3 in the array={3,5,7,9,11,13,15,17} and print the array after insertion.



#include <iostream>
using namespace std;
void insertElement(int arr[], int &n, int element, int position) {
    if (position < 0 || position > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    
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
    int arr[10] = {3, 5, 7, 9, 11, 13, 15, 17};
    int n = 8; 

    cout << "Original array: ";
    printArray(arr, n);

    int element = 8, position = 3;
    insertElement(arr, n, element, position);

    cout << "Array after insertion: ";
    printArray(arr, n);

    return 0;
}
// Output:
// Original array: 3 5 7 9 11 13 15 17
// Array after insertion: 3 5 7 8 9 11 13 15 17
