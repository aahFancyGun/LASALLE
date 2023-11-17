#include "slist.h"
#include <iostream>
using namespace std;
// Constructor

Node *next;
void *data;
Node ::Node() {
  next = nullptr;
  data = nullptr;
}
Node::Node(void *data) {
  this->data = data;
  next = nullptr;
}
// constructor function
linkedList::linkedList() { head = nullptr; }
void linkedList::add(void *data) {
  Node *newNode = new Node(data);
  if (head == nullptr) {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = newNode;
}
// inserts a node before the index
void linkedList::insert(int index, void *data) {
  Node *newNode = new Node(data);
  if (index == 0) {
    Node *temp = head;
  } else {
    Node *temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    newNode = temp->next;
    temp->next = newNode;
  }
}
// removes the specified node
void linkedList::remove(int index) {
  if (index == 0) {
    Node *temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
  } else {
  }
  Node *temp = head;
  Node *temp2 = head;
  for (int i = 0; i < index; i++) {
    if (i < index - 1) {
      temp2 = temp2->next;
    }
    temp = temp->next;
  }
  if (temp->next != NULL) {
    temp2->next = temp->next;
    delete temp;
    temp = nullptr;
  }
}
// gets data from the specified index.
void *linkedList::get(int index) {
  if (index == 0) {
    return head->data;
  } else {
    Node *temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp->data;
  }
}

Node *linkedList::getNode(int index) {
  if (index == 0) {
    return head;
  } else {
    Node *temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp;
  }
}
// returns size of the linked list
int linkedList::size() {
  int count = 0;
  Node *temp = head;
  while (temp != nullptr) {
    temp = temp->next;
    count++;
  }
  return count;
}

// returns true if the linked list is equal to the second linked list false
// otherwise
bool linkedList::equals(linkedList slist2) {
  Node *temp = head;
  Node *temp2 = slist2.head;
  if (size() != slist2.size()) {
    return false;
  }
  while (temp != nullptr && temp2 != nullptr) {
    if (temp->data != temp2->data) {
      return false;
    }
    temp = temp->next;
    temp2 = temp2->next;
  }
  return true;
}
// clears the list (basically a destructor)
void linkedList::clear() {
  Node *temp = head;
  while (temp != nullptr) {
    head = head->next;
    delete temp;
    temp = head;
  }
  temp = nullptr;
}

// exchanges values between two nodes
void linkedList::exchg(int index1, int index2) {
  Node *temp = head;
  Node *temp2 = head;
  for (int i = 0; i < index1; i++) {
    temp = temp->next;
  }
  for (int i = 0; i < index2; i++) {
    temp2 = temp2->next;
  }
  Node *temp3 = new Node(temp->data);
  temp->data = temp2->data;
  temp2->data = temp3->data;
  free(temp3);
}

// swaps node data at specified node (index1) with specified node (index2)
void linkedList::swap(Node *index1, Node *index2) {
  void *temp = index1->data;
  index1->data = index2->data;
  index2->data = temp;
}

bool linkedList::isEmpty() {
  if (head == nullptr) {
    return false;
  }
  return true;
}

// sets specified node's data to that of the new data
void linkedList::set(int index, void *data) {
  Node *temp = head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  temp->data = data;
}

// destructor
linkedList::~linkedList() {
  Node *temp = head;
  while (temp != nullptr) {
    head = head->next;
    delete temp;
    temp = head;
  }
  temp = nullptr;
}
// Destructor

// DO NOT IMPLEMENT >>> subList(start, length)	//Returns a new list containing
// elements from a sub-range of this list.

// DO NOT IMPLEMENT >>> toString()				//Converts the
// list to a printable string representation.