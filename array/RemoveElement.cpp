#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int> &nums, int val) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == val) {
        nums.erase(nums.begin() + i);
        i--;
      }
    }

    return nums.size();
  }
};

int main() {
  auto n1 = new vector<int>({1, 1, 2, 1});
  auto n2 = new vector<int>({42});
  auto n3 = new vector<int>({});
  auto n4 = new vector<int>({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});

  cout << Solution().removeElement(*n1, 1) << endl;
  cout << Solution().removeElement(*n2, 2) << endl;
  cout << Solution().removeElement(*n3, 42) << endl;
  cout << Solution().removeElement(*n4, 3) << endl;

  return 0;
}
