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
    ListNode* rotateRight(ListNode* head, int k) {
        int len =0;
        ListNode* temp = head;
        ListNode* lastNode=NULL;
        while(temp){
            lastNode = temp;
            temp = temp->next;
            len++;
        }
        if(len==0) return NULL;
        k = k%len;
        if(k==0) return head;
        int x = len-k;
        temp = head;
        while(--x){
            temp = temp->next;
        }
        ListNode* latter = temp->next;
        temp->next = NULL;

        ListNode* newHead = latter;
        lastNode->next = head;
        return newHead;

    }
};