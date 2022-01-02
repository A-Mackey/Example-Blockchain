#include <iostream>
#include <string>
#include "./include/sha256.h"
#include <climits>

using namespace std;

bool validWork(int length, string s) {
  if (length > s.length()) {return false;}
  for(int i = 0; i < length; i++) {
    if (s[i] != '0') {return false;}
  }
  return true;
}

int main() {
  int difficulty = 4;
  string toHash = "Hello World! : ";

  cout<<toHash<<"\t"<<sha256(toHash)<<endl;

  for(int i = 0; i < INT_MAX; i++) {
    if (validWork(difficulty, sha256(toHash + to_string(i)))) {
      cout<<toHash<<i<<endl;
      cout<<sha256(toHash + to_string(i))<<endl;
      break;
    }
  }

  return 0;
}
