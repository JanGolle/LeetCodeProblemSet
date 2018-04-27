#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }

    int count = 0;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i-1]) {
        count++;
      } else {
        nums[count-i] = nums[i];
      }
    }

    return count - nums.size();
  }
};

int main() {
  auto n1 = new vector<int>({1, 1, 2});
  auto n2 = new vector<int>({42});
  auto n3 = new vector<int>({});
  auto n4 = new vector<int>({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});

  cout << Solution().removeDuplicates(*n1) << endl;
  cout << Solution().removeDuplicates(*n2) << endl;
  cout << Solution().removeDuplicates(*n3) << endl;
  cout << Solution().removeDuplicates(*n4) << endl;

  return 0;
}
