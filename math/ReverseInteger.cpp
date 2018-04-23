#include <iostream>

using namespace std;

/*
 * Problem:
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed
 * integer range: [−2^31,  2^31 − 1].
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
 public:
  int reverse(int x) {
    long res = 0;

    while (x != 0) {
      res = res * 10 + x % 10;
      x /= 10;
    }

    return res > INT32_MAX || res < INT32_MIN ? 0 : res;
  }
};

int main() {
  cout << to_string(Solution().reverse(123)) << endl;
  cout << to_string(Solution().reverse(-123)) << endl;
  cout << to_string(Solution().reverse(-120)) << endl;
  cout << to_string(Solution().reverse(901000)) << endl;
  cout << to_string(Solution().reverse(-901000)) << endl;
  cout << to_string(Solution().reverse(120)) << endl;
  cout << to_string(Solution().reverse(0)) << endl;
  cout << to_string(Solution().reverse(1534236469)) << endl;
  cout << to_string(Solution().reverse(-2147483648)) << endl;

  return 0;
}
