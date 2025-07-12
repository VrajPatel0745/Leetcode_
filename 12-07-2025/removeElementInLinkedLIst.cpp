#include <iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int vala) {
        ListNode * tp=head;
         while (head != nullptr && head->val == vala) {
            head = head->next;
        }
        ListNode *current=head;
       while (current != nullptr && current->next != nullptr) {
            if (current->next->val == vala) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
    void printList(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
        
};
int main() {
    Solution solution;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    int vala = 6;

    cout << "Original list: ";
    solution.printList(head);

    head = solution.removeElements(head, vala);

    cout << "List after removing elements with value " << vala << ": ";
    solution.printList(head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}