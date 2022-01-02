#include <iostream>
#include <string>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

// secp256k1 domain parameters
int32_t Pcurve = pow(2, 256) - pow(2, 32) - pow(2, 9) - pow(2, 8) - pow(2, 7)
  - pow(2, 6) - pow(2, 4) - 1;
double Acurve = 0;
double Bcurve = 7;
double Gx = 0x79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798;
double Gy = 0x483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8;
double n = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141;
double h = 1;

double modinv(int a, int n = Pcurve) {
  int lm = 1;
  int hm = 0;
  double low = a % n;
  double high = n;

  while(low > 1) {
    double ratio = high/low;
    double nm = hm - lm * ratio;
    double neww = high-low * ratio;
    lm = nm;
    low = neww;
    hm = lm;
    high = low;
  }

  return lm % n;
}



int main() {
  return 0;
}
