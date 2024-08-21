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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head ->next == NULL) return head;

        ListNode* temp = head;
        ListNode* tempNext = head->next;
        ListNode* result = new ListNode(0);
        ListNode* ans = result;
        while(tempNext!=NULL) {
            if(temp->val != tempNext->val){
                cout<<tempNext->val<<"-"<<temp->val<<endl;
                ListNode* node = new ListNode(temp->val);
                ans->next = node;
                ans = ans->next;
            } else {
                cout<<tempNext->val<<"*"<<temp->val<<endl;
                while(tempNext!=NULL && tempNext->val == temp->val){
                    tempNext = tempNext->next;
                }
            }
                temp = tempNext;
                if(tempNext!=NULL) { 
                    tempNext = tempNext->next;
                }
        }
        ans->next = temp;

        return result->next;
    }
};