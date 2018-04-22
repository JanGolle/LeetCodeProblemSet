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
    string input = to_string(abs(x));
    string res;

    for (int i = input.size() - 1; i >= 0; i--) {
      if (input[i] != '0' || !res.empty() || input.size() == 1) {
        res += input[i];
      }
    }

    try {
      return x < 0 ? -1 * stoi(res) : stoi(res);
    } catch (out_of_range& exception) {
      return 0;
    }
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

  return 0;
}
