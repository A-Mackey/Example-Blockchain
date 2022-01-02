#include <iostream>
#include <string>
#include <vector>
#include "../../crypto/headers/sha256.h"

using namespace std;

/*
  Takes in a vector of any type and returns a new vector of strings
  that are hashed using the SHA256 hashing function.
*/
template<typename T>
vector<string> hashVector(vector<T> items) {
  vector<string> r = vector<string>();
  for(int i = 0; i < items.size(); i++) {
    r.push_back(sha256(items[i]));
  }

  return r;
}

template<typename T>
void printVector(vector<T> arr) {
  cout << "Vector Size: " << arr.size() << endl;
  for(int i = 0; i < arr.size(); i++) {
    cout<<arr[i]<<endl;
  }
}

/*
  A merkle tree data structure used for compressing trees into one single
  hash. This merkle tree implements the SHA256 hashing function.
*/
template<typename T>
class merkle_tree {
public:
  // Constructor
  merkletree() {items = new vector<T>();}

  // Mutators
  void insert(T newItem) {items.push_back(newItem);}

  // Getters
  // Returns merkle root
  string hash();

private:
  // Recursively hashes the tree to the merkle root
  string recursiveHash(vector<T> arr);
  // Simply hashes two strings together by appending them and hashing
  string twoHash(string one, string two) {
    return sha256(one + two);
  }

  // The vector that stores all the items in the merkle tree
  vector<T> items;
};

// Algorithm that hashes the tree to the merkle root
template<typename T>
string merkle_tree<T>::hash() {
  if (items.capacity() == 0) {return sha256("\0");}
  if (items.capacity() == 1) {return sha256(items[0]);}

  vector<T> hashedItems = hashVector(items);
  if (items.capacity() > 1) {return recursiveHash(hashedItems);}
  return "";
}

/*
    When a tree is larger than 1, a recursive algorithm is used to compress
    to a merkle root
*/
template<typename T>
string merkle_tree<T>::recursiveHash(vector<T> arr) {
  if (arr.capacity() == 2) {return twoHash(arr[0], arr[1]);}

  vector<T> temp = vector<T>();
  for(int i = 0; i < arr.capacity(); i+=2) {
    if (i + 1 < arr.size())
      temp.push_back(twoHash(arr[i],arr[i + 1]));
    else {
      if (i < arr.size()) {temp.push_back(twoHash(arr[i], ""));}
      else {temp.push_back("");}
    }
  }

  return recursiveHash(temp);
}
