#include <bits/stdc++.h>
#include <cstdint>
constexpr int N = 9901;
int getNPower(int& a, int k) {
  int ans = 0;
  while(a >= k  && (a % k == 0)) {
    ++ans;
    a = a / k;
  }
  return ans;
}

int calcPower(int a, int n) {
  int ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans = ((uint64_t) ans * a) % N;
    } 
    a = ((uint64_t) a * a) % N;
    n = n / 2;
  }
  return ans;
  
}

int calcSumPowerSeq(int a, int n) {
  if (n == 0) {
    return 1;
  } 
  if (n % 2 == 1) {
    int k = n / 2;
    int v1 = calcPower(a, k + 1);
    int v2 = calcSumPowerSeq(a, k);
    int v3 = (uint64_t) v1 * v2 %N;
    return ((uint64_t) v3 + v2) % N; 
  } else {
    int k = n / 2;
    int v1 = calcSumPowerSeq(a, k - 1);
    int v2 = calcPower(a, k);
    int v3 = calcPower(a, n);
    int v4 = (uint64_t) v1 * v2 % N;
    return (((uint64_t) v3 + v1 + v4) % N);
  } 

}
int calcSumDiv(int A, int B) {
  int ans = 1;
  for(int k = 2; k <= A; ++k) {
    int n = getNPower(A, k);
    if (n == 0) {
      continue;
    }
    int v1 = calcSumPowerSeq(k, n * B);
    ans = ((uint64_t) ans * v1) % N;
  }
  return ans;

}



int main() {
  int A, B;
  std::cin >> A >> B;
  if (A == 0) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << calcSumDiv(A, B) << std::endl;
  }

}