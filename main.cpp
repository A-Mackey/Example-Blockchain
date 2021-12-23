#include <iostream>
#include "./include/sha256.h"
#include "./include/blockchain.h"

#include <climits>

using namespace std;

int nonceLimit = INT_MAX;

int main() {
  blockChain chain;

  block b1(chain.getLatestBlock().hashBlock());
  b1.addTransaction("Aidan", "Aaron", 10);

  for(int i = 0; i < nonceLimit; i++) {
    if(b1.validateBlock(i, chain.getDifficulty())) {b1.setNonce(i); chain.addBlock(b1); break;};
  }

  block b2(chain.getLatestBlock().hashBlock());
  b2.addTransaction("Aaron", "Aidan", 50);
  b2.addTransaction("Nick", "Kevin", 500);

  for(int i = 0; i < nonceLimit; i++) {
    if(b2.validateBlock(i, chain.getDifficulty())) {b2.setNonce(i); chain.addBlock(b2); break;};
  }

  block b3(chain.getLatestBlock().hashBlock());
  b3.addTransaction("Aaron", "Aidan", 51);
  b3.addTransaction("Nick", "Kevin", 500);

  for(int i = 0; i < nonceLimit; i++) {
    if(b3.validateBlock(i, chain.getDifficulty())) {b3.setNonce(i); chain.addBlock(b3); break;};
  }

  b3 = block(chain.getLatestBlock().hashBlock());
  b3.addTransaction("Aaron", "Aidan", 51);
  b3.addTransaction("Nick", "Kevin", 500);

  for(int i = 0; i < nonceLimit; i++) {
    if(b3.validateBlock(i, chain.getDifficulty())) {b3.setNonce(i); chain.addBlock(b3); break;};
  }

  chain.printBlockChain();
}
