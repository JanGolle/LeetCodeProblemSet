#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Problem:
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

class Solution {
 public:
  vector<int> twoSum(vector<int> const &nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      int number_to_find = target - nums[i];

      if (map.find(number_to_find) != map.end()) {
        return {map[number_to_find], i};
      }

      map[nums[i]] = i;
    }

    return {};
  }
};

string int_vector_to_string(vector<int> list) {
  if (list.empty()) {
    return "[]";
  }

  string out;
  out += "[";

  for (int i = 1; i < list.size(); i++) {
    out += to_string(list[i - 1]) + ", ";
  }
  out += to_string(list[list.size() - 1]);

  out += "]";

  return out;
}

int main() {
  cout << int_vector_to_string(Solution().twoSum({2, 7, 11, 15}, 9)) << endl;
  cout << int_vector_to_string(Solution().twoSum({3, 16, 2, 14, 52, 19, 34}, 21)) << endl;
  cout << int_vector_to_string(Solution().twoSum({4, 8, 15, 16, 23, 42}, 31)) << endl;

  return 0;
}
