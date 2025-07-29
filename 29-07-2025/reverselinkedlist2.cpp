#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* tp = &dummy;

        for (int i = 1; i < left; i++) {
            tp = tp->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = tp->next;
        ListNode* tail = curr;

        for (int i = 0; i <= right - left; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect back
        tp->next = prev;
        tail->next = curr;

        return dummy.next;
    }
};
int main()
{
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* reversedList = solution.reverseBetween(head, 2, 4);

    // Print the reversed list
    ListNode* current = reversedList;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}