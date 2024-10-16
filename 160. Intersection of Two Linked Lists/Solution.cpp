/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=1,lenB=1;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1->next!=NULL){
            temp1=temp1->next;
            lenA++;
        }
        while(temp2->next!=NULL){
            temp2=temp2->next;
            lenB++;
        }
        cout<<lenA<<"-"<<lenB<<endl;

        if(lenA>lenB){
            int diff= lenA-lenB;
            temp1=headA;
            while(diff--){
                temp1= temp1->next;
            }
            temp2=headB;
            while(temp1 && temp2 && temp1!=temp2){
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return temp2;
        } else {
            int diff= lenB-lenA;
            temp2=headB;
            while(diff--){
                temp2=temp2->next;
            }
            temp1=headA;
            while(temp1 && temp2 && temp1!=temp2){
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return temp1;
        }
        return NULL;
    }
};