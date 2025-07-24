#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; 
            curr->next = prev;               
            prev = curr;                     
            curr = nextNode;                 
        }

        return prev; 
    }
};
int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    cout << "Original list: ";
    for (ListNode* node = head; node != nullptr; node = node->next) {
        cout << node->val << " ";
    }
    cout << endl;

    ListNode* reversedHead = solution.reverseList(head);
    
    cout << "Reversed list: ";
    for (ListNode* node = reversedHead; node != nullptr; node = node->next) {
        cout << node->val << " ";
    }
    cout << endl;

    // Clean up memory
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
