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
    void deleteNode(ListNode* node) {
        // we are given access only to node to be deleted
        // so we overwrite given nodes value with next nodes value 

        ListNode* p =node;
        while(node->next){
            node->val =node->next->val;
            p=node;
            node=node->next;
        }        
        p->next = NULL;
        return ;
    }
};