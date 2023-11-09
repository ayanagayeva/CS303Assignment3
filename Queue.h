#ifndef QUEUE_H
#define QUEUE_H
// queue class
class Queue {
public:
  // constructor initialize the empty queue
  Queue();
  // destructor destory + free memory
  ~Queue();
  // enqueue insert element @ rear of queue
  void enqueue(int value);
  // dequeue remove front element of queue + return value
  int dequeue();
  // return value @ front w/p removing
  int front();
  // check if queue == empty
  bool isEmpty();
  // total num o f elemnts in the queue
  int size();

private:
  // elements in the queue
  struct Node {
    int data;   // data of the node
    Node *next; // pointer to the next node in the queue
    // initializes a new node w/ data and nullptr as the next node
    Node(int val) : data(val), next(nullptr) {}
  };
  Node *frontPtr; // pointer to front
  Node *rearPtr;  // pointer to rear
  int count;      // num elements in queue
};
#endif
