#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode();
        ListNode *current = dummyHead;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            int digit = sum % 10;

            current->next = new ListNode(digit);
            current = current->next;

            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
int main()
{
    Solution solution;

    // Create first linked list: 2 -> 4 -> 3 (represents the number 342)
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second linked list: 5 -> 6 -> 4 (represents the number 465)
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // Print the result linked list
    while (result != nullptr)
    {
        cout << result->val;
        if (result->next != nullptr)
        {
            cout << " -> ";
        }
        result = result->next;
    }
    cout << endl;

    // Clean up memory
    delete l1->next->next;
    delete l1->next;
    delete l1;
    
    delete l2->next->next;
    delete l2->next;
    delete l2;

    return 0;
}