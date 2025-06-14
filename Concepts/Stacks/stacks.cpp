#include <iostream>
using namespace std;
class Stack
{
private:
  int top;
  int *arr;
  int capacity;

public:
  Stack(int size)
  {
    top = -1;
    this->capacity = size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++)
    {
      arr[i] = 0;
    }
  }
  bool isEmpty()
  {
    if (top == -1)
    {
      return true;
    }
    return false;
  }
  bool isFull()
  {
    if (top + 1 == capacity)
    {
      return true;
    }
    return false;
  }
  void push(int data)
  {
    if (isFull())
    {
      cout << "Stack overflow!!!" << endl;
    }
    else
    {
      top++;
      arr[top] = data;
    }
  }
  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack underflow!!!" << endl;
      return 0;
    }
    int popItem = arr[top];
    arr[top] = 0;
    top--;
    return popItem;
  }
  int count()
  {
    return top + 1;
  }
  int peek(int position)
  {
    if (isEmpty())
    {
      cout << "Stack underflow!!!" << endl;
      return 0;
    }
    return arr[position];
  }
  void change(int position, int value)
  {
    if (isEmpty())
    {
      cout << "Stack underflow!!!" << endl;
    }
    else
    {
      arr[position] = value;
      cout << "Value changed at index" << position << endl;
    }
  }
  void display()
  {
    if (isEmpty())
    {
      cout << "Stack underflow!!!" << endl;
    }
    else
    {
      for (int i = 0; i < top + 1; i++)
      {
        cout << arr[i] << endl;
      }
    }
  }
};
int main()
{
  Stack data(10);
  data.push(1);
  data.push(11);
  data.push(111);
  data.push(1111);
  data.push(11111);
  data.push(111111);
  cout << data.pop() << endl;
  cout << data.isEmpty() << endl;
  cout << data.isFull() << endl;
  cout << data.count() << endl;  
  data.change(2, 100);
  data.display();
cout << data.peek(2) << endl;
  return 0;
}