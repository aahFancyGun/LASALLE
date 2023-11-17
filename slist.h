/*

Header file for single linked list class library

*/
// Constructor
class Node {
public:
  Node *next;
  void *data;
  Node();
  Node(void *data);
};

class linkedList {
  Node *head;

public:
  linkedList();
  void add(void *data);
  void insert(int index, void *data);
  void remove(int index);
  void *get(int index);
  Node *getNode(int index);
  int size();
  bool equals(linkedList slist2);
  void clear();
  void exchg(int index1, int index2);
  void swap(Node *index1, Node *index2);
  bool isEmpty();
  void set(int index, void *data);
  ~linkedList();
};

// Destructor

// DO NOT IMPLEMENT >>> subList(start, length)	//Returns a new list containing
// elements from a sub-range of this list.

// DO NOT IMPLEMENT >>> toString()				//Converts the
// list to a printable string representation.

// subList(start, length)	//Returns a new list containing elements from a
// sub-range of this list.

// toString()				//Converts the list to a printable
// string representation.