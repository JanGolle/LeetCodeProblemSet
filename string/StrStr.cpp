#include <iostream>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    string& rh = haystack;
    string& rn = needle;

    if (rn.empty()) {
      return 0;
    }

    if (rh.length() < rn.length()) {
      return -1;
    }

    for (auto it=rh.begin(); it < rh.end() - rn.length() + 1; ++it) {
      if (equal(rn.begin(), rn.end(), it)) {
        return it - rh.begin();
      }
    }

    return -1;
  }
};

int main() {
  cout << Solution().strStr("hello", "ll") << endl;
  cout << Solution().strStr("aaaaa", "bba") << endl;
  cout << Solution().strStr("world", "") << endl;
  cout << Solution().strStr("helolollo", "ll") << endl;
  cout << Solution().strStr("ll", "ll") << endl;
  cout << Solution().strStr("ll", "l") << endl;
  cout << Solution().strStr("l", "ll") << endl;

  return 0;
}

