// Selection sort 


#include <iostream>
using namespace std;
void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selectionSort(int array[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int min = i;
    for (int j = i; j < size; j++)
    {
      if (array[j] < array[min])
      {
        min = j;
      }
    }
    swap(&array[i], &array[min]);
  }
}
int main()
{
  int data[] = {-10, 100, 12, 0, 12, 2, 1};
  int size = sizeof(data) / sizeof(data[0]);
  selectionSort(data, size);
  cout << "Sorted array in ascending order: " << endl;
  printArray(data, size);
}