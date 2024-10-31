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
    ListNode *detectCycle(ListNode *head) {
        ListNode* hare = head;
        ListNode* rabbit = head;
        while(hare && hare->next ){
            hare = hare->next->next;
            rabbit = rabbit ->next;
            if(hare==rabbit){
                break;
            }
        }
        if(!hare || !hare->next){
            return NULL;
        } else {
            hare = head;
            while(rabbit!=hare){
                rabbit = rabbit->next;
                hare = hare->next;
            }
            return rabbit;
        }
    }
};