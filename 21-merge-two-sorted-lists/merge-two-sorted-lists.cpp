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
        ListNode* dummy=new ListNode(-1);
        ListNode* nNode = dummy;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while(t1 !=NULL && t2!=NULL){
            if(t1->val > t2->val){
                nNode->next = t2;
                nNode = t2;
                t2=t2->next;
            }else{
                nNode->next=t1;
                nNode=t1;
                t1=t1->next;
            }
        }
        if(t1) nNode->next = t1;
        if(t2)nNode->next = t2;
        return dummy->next;
    }
};