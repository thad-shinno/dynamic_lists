// @author Thad Shinno
#ifndef LINKED_H
#define LINKED_H

#include <iostream>
#include "node.h"
using std::cout;
using std::endl;

template <typename T>
class Linked {
  private:
    Node<T> *_head;
    Node<T> *_tail;
    int _size;
  public:
    Linked<T>();
    void add(T);
    void insert(int, T);
    void remove(int);
    T get(int);
    int size();
    void print();
};

// init size 0
template <typename T>
Linked<T>::Linked() {
  _size = 0;
}

// add an item to the end of the list
template <typename T>
void Linked<T>::add(T val) {
  Node<T> *n = new Node<T>(val);
  // if the list is empty, make it head AND tail
  if (_size == 0) {
    _head = n;
    _tail = n;
    // doubly linked
    _head->setNext(_tail);
    _tail->setPrev(_head);
  }
  // else add to tail
  else {
    n->setPrev(_tail);
    _tail->setNext(n);
    _tail = n;
  }
  _size++;
}

// insert a value at a given index
template <typename T>
void Linked<T>::insert(int index, T val) {
  // check index valideity
  if (index < 0 || index > _size) {
    throw "Invalid index";
  }
  // if inserted at tail, just add it
  if (index == _size) {
    add(val);
    return;
  }
  
  Node<T> *n = new Node<T>(val);
  // if insertion is at head, make the head the new node
  if (index == 0) {
    n->setNext(_head);
    _head->setPrev(n);
    _head = n;
  }
  else {
    // get to index
    Node<T> *curr = _head;
    for (int i = 0; i < index - 1; i++) {
      curr = curr->getNext();
    }
    // set previous and next for new node
    n->setPrev(curr);
    n->setNext(curr->getNext());
    // change the prev of next and the next of prev
    n->getNext()->setPrev(n);
    curr->setNext(n);
  }
  _size++;
}

// remove a node at an index
template <typename T>
void Linked<T>::remove(int index) {
  // check index validity
  if (index < 0 || index >= _size) {
    throw "Invalid index";
  }
  // remove head
  if (index == 0) {
    _head = _head->getNext();
  }
  // remove tail
  else if (index == _size - 1) {
    _tail = _tail->getPrev();
  }
  // remove something else
  else {
    // 1 2 3 5 6
    Node<T> *curr = _head;
    for (int i = 0; i < index - 1; i++) {
      curr = curr->getNext();
    }
    // set next to be next next
    curr->setNext(curr->getNext()->getNext());
    curr->getNext()->setPrev(curr);
  }
  _size--;
}

// get item at an index
template <typename T>
T Linked<T>::get(int index) {
  if (index < 0 || index >= _size) {
    throw "Invalid index";
  }

  Node<T> *curr = _head;
  for (int i = 0; i < index; i++) {
    curr = curr->getNext();
  }
  return curr->getVal();
}

template <typename T>
int Linked<T>::size() {
  return _size;
}

// print each item in list
template <typename T>
void Linked<T>::print() {
  Node<T> *curr = _head;
  for (int i = 0; i < _size; i++) {
    cout << curr->getVal() << " ";
    curr = curr->getNext();
  }
  cout << endl;
}

#endif
