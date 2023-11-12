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
class Solution 
{
    public:
        ListNode* swapPairs(ListNode* head) 
        {
            ListNode* dummy = new ListNode(0, head);
            ListNode* current = head;
            ListNode* previous = dummy;
            ListNode* nextCurrent;
            ListNode* second;

            while (current != NULL && current -> next != NULL)
            {
                nextCurrent = current -> next -> next;
                second = current -> next;

                second -> next = current;
                current -> next = nextCurrent;
                previous -> next = second;

                previous = current;
                current = nextCurrent;
            }

            return dummy -> next;
        }
};