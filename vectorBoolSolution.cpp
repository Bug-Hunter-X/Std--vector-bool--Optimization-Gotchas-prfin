#include <iostream>
#include <vector>
#include <bitset>

int main() {
  // Problematic usage
  std::vector<bool> vecBool(10);
  vecBool[0] = true; 
  std::cout << "vecBool[0]: " << vecBool[0] << std::endl; // this may be optimized away
  // std::vector<bool> uses optimization that may not be intuitive. 
  for (size_t i = 0; i < vecBool.size(); ++i) {
    // This loop is inefficient and may not behave as expected 
    // due to the internal bitset implementation.  
    vecBool[i] = (i % 2 == 0); 
  }
  // Safer alternative: use a std::vector<int> or std::bitset
  std::vector<int> vecInt(10);
  for (size_t i = 0; i < vecInt.size(); ++i) {
    vecInt[i] = (i % 2 == 0);
  }
  std::cout << "vecInt[0]: " << vecInt[0] << std::endl; 
  std::bitset<10> bitset10;
  for (size_t i = 0; i < bitset10.size(); ++i) {
    bitset10[i] = (i % 2 == 0);
  }
  std::cout << "bitset10: " << bitset10 << std::endl; 
  return 0;
}