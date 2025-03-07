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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* prevHead = NULL;

        while(temp!=NULL){
            ListNode* node = temp;
            temp = temp->next;
            node->next = prevHead;
            prevHead = node;
        }

        return prevHead;
    }
};