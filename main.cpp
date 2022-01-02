#include <iostream>
#include "./include/sha256.h"
#include "./include/blockchain2.h"

#include <climits>

using namespace std;

int nonceLimit = INT_MAX;

int main() {
  blockChain chain;

  block b1(chain.getLatestBlockHash());
  b1.addTransaction("Aidan", "Aaron", 10);

  for(int i = 0; i < nonceLimit; i++) {
    if(b1.validateBlock(i, chain.getDifficulty())) {b1.setNonce(i); chain.addBlock(b1); break;};
  }

  chain.printBlockChain();
}
