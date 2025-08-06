#include <iostream>
#include <vector>
using namespace std;
// T.C->O(nlogn)
// S.C->O(n)
void merge(int array[], int low, int high, int mid)
{
  vector<int> result;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high)
  {
    if (array[left] <= array[right])
    {
      result.push_back(array[left]);
      left++;
    }
    else
    {
      result.push_back(array[right]);
      right++;
    }
  }
  while (left <= mid)
  {
    result.push_back(array[left]);
    left++;
  }
  while (right <= high)
  {
    result.push_back(array[right]);
    right++;
  }
  for (int i = low; i <= high; i++)
  {
    array[i] = result[i - low];
  }
}
void mergeSort(int array[], int low, int high)
{
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  mergeSort(array, low, mid);
  mergeSort(array, mid + 1, high);
  merge(array, low, high, mid);
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    cout << " " << array[i];
  }
  cout << endl;
}
int main()
{
  int data[] = {100, 0, -10, 29, 2312, 21, 12};
  int size = sizeof(data) / sizeof(data[0]);
  mergeSort(data, 0, size - 1);
  cout << "Sorted Array in Ascending Order: " << endl;
  printArray(data, size);
}