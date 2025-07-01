#include <iostream>
using namespace std;
class CircularQueue
{
public:
  int front, rear;
  int *queue;
  int size;
  CircularQueue(int size) : queue(new int[size]), front(0), rear(0), size(size) {}
  void enqueue(int x)
  {
    if (front == ((rear + 1) % size))
      cout << "Queue is full" << endl;
    else
    {
      queue[rear] = x;
      rear = (rear + 1) % size;
    }
  }
  void dequeue()
  {
    if (front == rear)
    {
      cout << "Queue is empty" << endl;
      front = rear = 0;
    }
    else
    {
      int item = queue[front];
      front = (front + 1) % size;
    }
  }
  void display()
  {
    if (front == rear)
      cout << "Queue is empty" << endl;
    else
    {
      for (int i = front; i != rear; i = (i + 1) % size)
      {
        cout << queue[i] << "  ";
      }
      cout << endl;
    }
  }
};
int main()
{
  CircularQueue newqueue(5);
  newqueue.enqueue(111);
  newqueue.enqueue(110);
  newqueue.enqueue(11011);
  newqueue.enqueue(11001);
  newqueue.enqueue(100001);
  newqueue.display();
  newqueue.dequeue();
  newqueue.display();
  newqueue.dequeue();
  newqueue.display();
  newqueue.dequeue();
  newqueue.dequeue();
  newqueue.dequeue();
  newqueue.display();
  newqueue.enqueue(10);
  newqueue.display();
  return 0;
}