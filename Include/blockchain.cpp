#include "blockchain.h"

using namespace std;

block::block(string previousHash) {
  prevHash = previousHash;
  vector<transaction> emptyVector;
  transactions = emptyVector;
}

void block::addTransaction(string p1, string p2, int ammount) {
  transactions.push_back((transaction){p1,p2, ammount});
}

bool block::validateBlock(int n, int difficulty) {
  int prevNonce = nonce;
  nonce = n;
  string hash = sha256(stringifyBlock());

  if (difficulty > hash.length()) {return false;}
  for(int i = 0; i < difficulty; ++i) {
    if (hash[i] != '0') {return false;}
  }

  nonce = prevNonce;
  return true;
}

string block::stringifyBlock() {
  string r = "<";
  r.append(prevHash);
  r.append("||");

  for (int i = 0; i < transactions.size(); i++) {
    r.append(transactions[i].from);
    r.append("|");
    r.append(transactions[i].to);
    r.append("|");
    r.append(to_string(transactions[i].ammount));
    r.append("||");
  }

  r.append(to_string(nonce));
  r.append(">");

  return r;
}

// ------------------------------------------------

blockChain::blockChain() {
  chain.push_back(block("Hello World!"));
}

bool blockChain::addBlock(block proposal) {
  if(isValidHash(proposal)) {
    chain.push_back(proposal);
  }
}

bool blockChain::isValidHash(block blck) {
  string hash = sha256(blck.stringifyBlock());

  if (difficulty > hash.length()) {return false;}
  for(int i = 0; i < difficulty; ++i) {
    if (hash[i] != '0') {return false;}
  }
  return true;
}

void blockChain::printBlockChain() {
  for(int i = 0; i < chain.size(); i++) {
    cout<<"Previous Hash:\t"<<chain[i].getPrevHash()<<endl;
    cout<<"Transactions:"<<chain[i].getTransactions().size()<<endl;

    for(int o = 0; o < chain[i].getTransactions().size(); o++) {
      cout<<chain[i].getTransactions()[o].from<<" --> "
        <<chain[i].getTransactions()[o].to<<"\t:\t"
        <<chain[i].getTransactions()[o].ammount<<endl;
    }

    cout<<"Nonce:\t"<<chain[i].getNonce()<<endl<<endl;
  }
}
