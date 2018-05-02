#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string res = "1";

    for (int i = 1; i < n; ++i) {
      char buffer = res[0];
      int count = 0;
      string temp;
      for (char re : res) {
        if (re == buffer) {
          count++;
        } else {
          temp += to_string(count) + buffer;
          buffer = re;
          count = 1;
        }
      }

      if (count > 0) {
        temp += to_string(count) + buffer;
      }

      res = temp;
    }

    return res;
  }
};

int main() {
  cout << Solution().countAndSay(1) << endl;
  cout << Solution().countAndSay(2) << endl;
  cout << Solution().countAndSay(3) << endl;
  cout << Solution().countAndSay(4) << endl;
  cout << Solution().countAndSay(5) << endl;
  cout << Solution().countAndSay(6) << endl;
  cout << Solution().countAndSay(7) << endl;
  cout << Solution().countAndSay(8) << endl;
  cout << Solution().countAndSay(9) << endl;
  cout << Solution().countAndSay(10) << endl;
}
