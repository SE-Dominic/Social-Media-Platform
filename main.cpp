#include "headerfile.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
  Account dom;
  dom.setUsername("dombomb.com");
  dom.setDescription("Just living and vibing in the U.S.A");
  dom.printAccountInfo();
  return 0;
}
