// circular queue 

#include <iostream>
using namespace std;

class CircularQueue {
public:
  int front, rear;
  int *queue;
  int size;

  CircularQueue(int size) : queue(new int[size]), front(0), rear(0), size(size) {}

  void enqueue(int x) {
    if (front == ((rear + 1) % size))
      cout << "Queue is full" << endl;
    else {
      queue[rear] = x;
      rear = (rear + 1) % size;
    }
  }

  void dequeue() {
    if (front == rear)
      cout << "Queue is empty" << endl;
    else
      front = (front + 1) % size;
  }
};

int main() {
  CircularQueue q(5);
  q.enqueue(1);
  q.enqueue(2);
  q.dequeue();
  q.enqueue(3);
  q.dequeue();
  q.dequeue();
  return 0;
}
