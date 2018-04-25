#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> chars;
    unordered_map<char, char> map = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };

    for (char i : s) {
      if (map.find(i) != map.end()) {
        chars.push(i);
      } else if (chars.empty() || map.find(chars.top())->second != i) {
        return false;
      } else {
        chars.pop();
      }
    }

    return chars.empty();
  }
};

int main() {
  cout << Solution().isValid("()") << endl;
  cout << Solution().isValid("()[]{}") << endl;
  cout << Solution().isValid("(]") << endl;
  cout << Solution().isValid("([)]") << endl;
  cout << Solution().isValid("{[]}") << endl;
  cout << Solution().isValid("") << endl;
  cout << Solution().isValid("(([]}[]))") << endl;
  cout << Solution().isValid("[") << endl;

  return 0;
}

