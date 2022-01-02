#ifndef BINARY_NODE
#define BINARY_NODE

#include <string>
#include <iostream>

template <class T>
class binary_node {
public:
  binary_node() {left = nullptr; right = nullptr;};
  binary_node(T newValue) {value = newValue; left = nullptr; right = nullptr;}
  binary_node(T newValue, binary_node<T>* l, binary_node<T>* r)
    {value = newValue; left = l; right = r;}

  void insert(binary_node<T> newLeft, binary_node<T> newRight);
  void print();

  binary_node<T>* getLeft() {return left;}
  binary_node<T>* getRight() {return right;}
  T getValue() {return value;}
private:
  T value;
  binary_node<T>* left;
  binary_node<T>* right;
};

/* FUNCTIONS */

template <class T>
void binary_node<T>::insert(binary_node<T> newLeft, binary_node<T> newRight) {
  left = new binary_node<T>(newLeft.getValue(), newLeft.getLeft(), newLeft.getRight());
  right = new binary_node<T>(newRight.getValue(), newRight.getLeft(), newRight.getRight());
}

template <typename T>
void binary_node<T>::print() {
  if (left != nullptr) {left->print();}
  std::cout<<value<<std::endl;
  if (right != nullptr) {right->print();}
}

#endif
