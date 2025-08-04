// Quick sort

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
int pivot(int array[], int low, int high)
{
  int pivotele = array[low];
  int i = low;
  int j = high;
  while (i < j)
  {
    while (i < high && array[i] <= pivotele)
    {
      i++;
    }
    while (j > low && array[j] > pivotele)
    {
      j--;
    }
    if (i < j)
    {
      swap(array[i], array[j]);
    }
  }
  swap(array[low], array[j]);
  return j;
}
void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pe = pivot(array, low, high);
    quickSort(array, low, pe - 1);
    quickSort(array, pe + 1, high);
  }
}
int main()
{
  int data[] = {-10, 100, 12, 0, 12, 2, 1};
  int size = sizeof(data) / sizeof(data[0]);
  quickSort(data, 0, size);
  cout << "Sorted array in ascending order: " << endl;
  printArray(data, size);
}