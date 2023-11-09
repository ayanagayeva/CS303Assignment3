#include "Queue.h"
// constructor initialize the empty queue
Queue::Queue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}
// destructor delete all
Queue::~Queue() {
  // dequeue until the queue == empty
  while (!isEmpty()) {
    dequeue();
  }
}
// enqueue insert element @ rear of queue
void Queue::enqueue(int value) {
  // new node w/ the given value
  Node *newNode = new Node(value);
  // if the queue is empty both front and rear = the new node
  if (isEmpty()) {
    frontPtr = newNode;
  } else {
    // else the current rear is to the new node
    rearPtr->next = newNode;
  }
  // update rear to the new node and count++
  rearPtr = newNode;
  count++;
}
// dequeue remove front element of queue + return value
int Queue::dequeue() {
  // check if queue == empty
  if (isEmpty()) {
    return -1;
  }
  // val of front node
  int frontValue = frontPtr->data;
  // save the front node momentarily
  Node *temp = frontPtr;
  // frontPtr = next node
  frontPtr = frontPtr->next;
  // delete the temporary node + count--
  delete temp;
  count--;
  // if the queue == empty then rearPtr is nullptr
  if (isEmpty()) {
    rearPtr = nullptr;
  }
  // value dequeued element
  return frontValue;
}
// value @ front
int Queue::front() {
  // queue == empty
  if (isEmpty()) {
    return -1;
  }
  // value @ front node
  return frontPtr->data;
}
// queue == empty.
bool Queue::isEmpty() { return count == 0; }
// num of vals
int Queue::size() { return count; }