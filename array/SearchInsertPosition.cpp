#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int> &nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    if (nums.size() == 0 || nums[lo] >= target) {
      return 0;
    }

    if (nums[hi] < target) {
      return hi + 1;
    } else if (nums[hi] == target) {
      return hi;
    }

    for (int pivot = (lo + hi) / 2; pivot != lo && pivot != hi; pivot = (lo + hi) / 2) {
      if (nums[pivot] > target) {
        hi = pivot;
      } else if (nums[pivot] < target) {
        lo = pivot;
      } else {
        return pivot;
      }
    }

    return target > nums[lo] ? hi : lo;
  }
};

int main() {
  cout << Solution().searchInsert(*(new vector<int>({1, 3, 5, 6})), 5) << endl;
  cout << Solution().searchInsert(*(new vector<int>({4, 8, 15, 16, 23, 42})), 5) << endl;
  cout << Solution().searchInsert(*(new vector<int>({4, 9})), 9) << endl;
}
