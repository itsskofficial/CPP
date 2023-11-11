// https://leetcode.com/problems/add-two-numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* l3 = NULL;
        int sum = 0, rem = 0, carry = 0;

        while(l1 && l2)
        {
            sum = l1 -> val + l2 -> val + carry;
            rem = sum % 10;
            carry = sum / 10;
            insertAtTail(l3, rem);
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1)
        {
            sum = l1 -> val + carry;
            rem = sum % 10;
            carry = sum / 10;
            insertAtTail(l3, rem);
            l1 = l1 -> next;
        }

        while(l2)
        {
            sum = l2 -> val + carry;
            rem = sum % 10;
            carry = sum / 10;
            insertAtTail(l3, rem);
            l2 = l2 -> next;
        }

        if(carry != 0)
            insertAtTail(l3, carry);
            
        return l3;
    }

    void insertAtTail(ListNode* &head, int val)
    {
        ListNode* temp = head;

        if(!head)
        {
            head = new ListNode(val);
            return;
        }

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = new ListNode(val);
    }
};