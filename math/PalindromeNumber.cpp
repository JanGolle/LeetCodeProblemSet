#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    } else {
      int revX = 0;
      int tempX = x;

      while (tempX != 0) {
        revX = revX * 10 + tempX % 10;
        tempX /= 10;
      }

      return x == revX;
    }
  }
};

int main() {
  cout << Solution().isPalindrome(121) << endl;
  cout << Solution().isPalindrome(-121) << endl;
  cout << Solution().isPalindrome(10) << endl;
  cout << Solution().isPalindrome(123) << endl;
  cout << Solution().isPalindrome(1111) << endl;
  cout << Solution().isPalindrome(13344331) << endl;
  cout << Solution().isPalindrome(0) << endl;
  cout << Solution().isPalindrome(10101) << endl;
  cout << Solution().isPalindrome(12345) << endl;
  cout << Solution().isPalindrome(901000) << endl;
  cout << Solution().isPalindrome(-901000) << endl;
  cout << Solution().isPalindrome(120) << endl;
  cout << Solution().isPalindrome(1534236469) << endl;
  cout << Solution().isPalindrome(-2147483648) << endl;

  return 0;
}
