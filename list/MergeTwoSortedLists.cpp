#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
      return l2;
    }

    if (!l2) {
      return l1;
    }

    ListNode* res = nullptr;

    if (l1->val < l2->val) {
      res = l1;
      l1 = l1->next;
    } else {
      res = l2;
      l2 = l2->next;
    }

    ListNode* pres = res;

    while (true) {
      if (!l1) {
        pres->next = l2;
        break;
      }

      if (!l2) {
        pres->next = l1;
        break;
      }

      if (l1->val < l2->val) {
        pres->next = l1;
        l1 = l1->next;
      } else {
        pres->next = l2;
        l2 = l2->next;
      }
      pres = pres->next;
    }

    return res;
  }
};

int main() {
  //[1,2,4], [1,3,4]
  auto* l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  auto* l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode* m1 = Solution().mergeTwoLists(l1, l2);

  while (m1) {
    cout << m1->val << endl;
    m1 = m1->next;
  }

  //[4,8,15], [23,42]
  auto* l3 = new ListNode(4);
  l3->next = new ListNode(8);
  l3->next->next = new ListNode(23);

  auto* l4 = new ListNode(15);
  l4->next = new ListNode(42);

  ListNode* m2 = Solution().mergeTwoLists(l3, l4);

  while (m2) {
    cout << m2->val << endl;
    m2 = m2->next;
  }

  return 0;
}
