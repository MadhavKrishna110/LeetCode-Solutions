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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* mergedList=new ListNode(0);
        ListNode* temp = mergedList;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                ListNode* node = new ListNode(list1->val);
                temp->next = node;
                temp = temp->next;
                list1 = list1->next; 
                cout<<"*"<<temp<<endl;
            } else {
                cout<<"!"<<endl;
                ListNode* node = new ListNode(list2->val);
                temp->next = node;
                temp = temp->next;
                list2= list2->next;
            }
        }
        if(list1!=NULL){
            temp->next = list1;
        }
        if(list2!=NULL){
            temp->next = list2;
        }

        return mergedList->next;
    }
};