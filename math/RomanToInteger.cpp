#include <iostream>
#include <unordered_map>

using namespace std;

struct RomanToIntMap {
  static unordered_map<string, int> create_map() {
    unordered_map<string, int> map = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}
    };

    return map;
  }

  static const unordered_map<string, int> map;
};

const unordered_map<string, int> RomanToIntMap::map = RomanToIntMap::create_map();

class Solution {
 public:
  int romanToInt(string s) {
    const unordered_map<string, int> *map = &RomanToIntMap::map;
    int res = 0;
    string buffer;

    for (int i = 0; i < s.size(); ++i) {
      buffer = s.substr(i, 2);
      auto it = map->find(buffer);

      if (it != map->end()) {
        res += it->second;
        i++;
      } else {
        res += map->find(buffer.substr(0, 1))->second;
      }
    }

    return res;
  }
};

int main() {
  cout << Solution().romanToInt("III") << endl;
  cout << Solution().romanToInt("IV") << endl;
  cout << Solution().romanToInt("IX") << endl;
  cout << Solution().romanToInt("LVIII") << endl;
  cout << Solution().romanToInt("MCMXCIV") << endl;
  cout << Solution().romanToInt("XXXIX") << endl;

  return 0;
}

