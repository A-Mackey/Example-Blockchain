#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "./sha256.h"

// TRANSACTION STRUCT
struct transaction {
  std::string from;
  std::string to;
  int ammount;
};

// BLOCK 
class block {
public:
  block(std::string previousHash);

  bool validateBlock(int n, int difficulty);
  void setNonce(int n) {nonce = n;}
  void addTransaction(std::string p1, std::string p2, int amount);
  std::string stringifyBlock();
  std::string hashBlock() {return sha256(stringifyBlock());}

  // GETTERS
  std::string getPrevHash() {return prevHash;}
  std::vector<transaction> getTransactions()
    {return transactions;}
  int getNonce() {return nonce;}

private:
  std::string prevHash;
  std::vector<transaction> transactions;
  int nonce = 0;
};

// BLOCKCHAIN
class blockChain {
public:
  blockChain();

  bool addBlock(block proposal);
  std::string getLatestBlockHash() {return bestBlockhash;}
  int getDifficulty() {return difficulty;}
  void printBlockChain();

private:
  bool isValidHash(block blck);

  int difficulty = 4;
  std::map<std::string, block> chain;
  std::string bestBlockhash;
};


#endif
