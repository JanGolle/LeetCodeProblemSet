#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix;

    if (strs.empty()) {
      return prefix;
    }

    for (int i = 0; i < strs[0].size(); ++i) {
      char current = strs[0][i];
      for (auto &str : strs) {
        if (i == str.size() || str[i] != current) {
          return prefix;
        }
      }
      prefix += current;
    }

    return prefix;
  }
};

int main() {
  vector<string> v1 = {"flower", "flow", "flight"};
  vector<string> v2 = {"dog", "racecar", "car"};
  vector<string> v3 = {"d", "doll", "dull"};
  vector<string> v4 = {"", "doll", "dull"};
  vector<string> v5 = {"d", "", "dull"};
  vector<string> v6 = {"single"};
  vector<string> v7 = {};

  cout << Solution().longestCommonPrefix(v1) << endl;
  cout << Solution().longestCommonPrefix(v2) << endl;
  cout << Solution().longestCommonPrefix(v3) << endl;
  cout << Solution().longestCommonPrefix(v4) << endl;
  cout << Solution().longestCommonPrefix(v5) << endl;
  cout << Solution().longestCommonPrefix(v6) << endl;
  cout << Solution().longestCommonPrefix(v7) << endl;

  return 0;
}

