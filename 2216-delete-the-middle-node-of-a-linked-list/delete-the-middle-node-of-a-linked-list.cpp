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
    ListNode* deleteMiddle(ListNode* head) {
        //brute force
        // ListNode* temp =head;
        // int cnt =0;
        // while(temp!=NULL){
        //     cnt++;
        //     temp=temp->next;
            
        // }

        // int mid  = cnt/2;
        // temp = head;
        // while(temp!=NULL){
        //     mid--;
        //     if(mid == 0){
        //         ListNode* middle = temp->next;
        //         temp->next = temp->next->next;
        //         delete middle;

        //     }
        //     temp=temp->next;

        // }
        // return head;


        //optimal approach is tortoise and hare 
        if(head == NULL || head->next == NULL) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next->next;
        while(fast!=NULL  && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            
        }

        slow->next=slow->next->next;
        return head;


        
    }
};