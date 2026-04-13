// Add Two Numbers

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    int carry = 0;

    while (l1 || l2 || carry != 0)
    {
        int sum = carry;

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *result = addTwoNumbers(l1, l2);

    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl; // Output: 7 0 8
    return 0;
}


// Time Complexity: O(max(m, n)), where m and n are the lengths of the two linked lists.
// Space Complexity: O(max(m, n)), for the new linked list that we create to store the result.