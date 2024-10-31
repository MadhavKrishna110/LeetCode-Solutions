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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* resultList = new ListNode(0);
        ListNode* resultTemp = resultList;
        ListNode* reverseList = new ListNode(0);
        ListNode* reverseTemp = reverseList;
        
        ListNode* headTemp = head;
        while( headTemp!=NULL){
            
            ListNode* temp = headTemp;
            int count=1;
            while(count<=k && temp!=NULL){
                temp = temp->next;
                count++;
            }
            if(count>k){
                ListNode* prev=NULL;
                ListNode* toBeLastNode = headTemp;
                int x=k;
                while(x-- && headTemp!=NULL){
                    ListNode* node = headTemp->next;
                    headTemp->next = prev;
                    prev = headTemp;
                    headTemp = node;
                }
                reverseTemp->next = prev;
                reverseTemp = toBeLastNode;
            } else {
                reverseTemp->next = headTemp;
                break;
            }
           
        }
        return reverseList->next;
    }
};