#include <iostream>
#include <string>

#include "./datastructures/headers/binarynode.h"
#include "./datastructures/headers/merkletree.h"
#include "./crypto/headers/sha256.h"

int main() {

  // binary_node<std::string> n = binary_node<std::string>("Root");
  // binary_node<std::string> l = binary_node<std::string>("Left");
  // binary_node<std::string> r = binary_node<std::string>("Right");
  //
  //
  // binary_node<std::string> ll = binary_node<std::string>("LeftLeft");
  // binary_node<std::string> lr = binary_node<std::string>("LeftRight");
  //
  // l.insert(ll, lr);
  // n.insert(l, r);
  // n.print();

  merkle_tree<std::string> mt = merkle_tree<std::string>();

  for(int i = 1; i <= 99999 ; i++) {
    mt.insert(to_string(i));
  }

  cout<<mt.hash()<<endl;

  return 0;
}
