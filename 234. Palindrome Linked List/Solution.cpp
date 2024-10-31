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
    ListNode* reverseList(ListNode* head){
        ListNode* prev= NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* rabbit = head;
        ListNode* hare = head;

        while( hare->next!=NULL && hare->next->next!=NULL){
            rabbit= rabbit->next;
            hare = hare->next->next;
        }

        ListNode* latter = rabbit->next;
        rabbit->next = NULL;
        ListNode* reversed = reverseList(latter);
        rabbit = head;
        while(rabbit && reversed ){
            cout<<rabbit->val<<"-"<<reversed->val<<endl;
            if(rabbit->val!=reversed->val){
                return false;
            }
            rabbit = rabbit->next;
            reversed = reversed->next;
        }

        if(reversed ) return false;

        return true;

    }
};