#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *left, ListNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;  
            slow = slow->next;        
            
            if (fast == slow) {      
                return true;
            }
        }
        return false;
    }
};
int main() {
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head; // Creating a cycle for testing

    Solution solution;
    bool hasCycle = solution.hasCycle(head);
    cout << "Does the linked list have a cycle? " << (hasCycle ? "Yes" : "No") << endl;

    // Clean up memory (not shown here for brevity)
    return 0;
}