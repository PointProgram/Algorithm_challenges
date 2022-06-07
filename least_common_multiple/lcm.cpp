#include <iostream>

unsigned long long lcm_naive(int a, int b) {
  for (unsigned long long l = 1; l <= (unsigned long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (unsigned long long) a * b;
}


int gcd(int a, int b) {
  int a_t;
  while (b != 0) {
    a_t = b;
    b = a % b;
    a = a_t;
  }
  return a;
}

unsigned long long lcm(int a, int b) {
  unsigned long long num = (unsigned long long) a * b, num_temp;

  int denom = gcd(a, b);
  while (num % a == 0 && num % b == 0) {
    num_temp = num;
    num /= denom;
    if(num == num_temp) 
      break;
  }

  return num_temp;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;

  std::cout << lcm(a, b) << std::endl;
  return 0;
}
