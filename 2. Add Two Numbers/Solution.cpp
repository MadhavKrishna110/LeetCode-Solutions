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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tempHead = new ListNode(0);
        ListNode* temp = tempHead;
        int carry =0;
        while(l1 && l2){
            int sum = l1->val+l2->val+carry;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            carry = sum/10;
            l1= l1->next;
            l2= l2->next;
        }
        while(l1){

            int sum= l1->val+carry;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            carry = sum/10;
            l1= l1->next;
        }
        while(l2){
            int sum= l2->val+carry;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            carry = sum/10;
            l2= l2->next;
        }
        if(carry){
           ListNode* node = new ListNode(carry);
           temp->next = node;
        temp = temp->next;

        }
        return tempHead->next;
    }
};