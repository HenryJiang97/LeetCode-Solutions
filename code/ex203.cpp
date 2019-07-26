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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        
        //If head->val == val
        while(head->val == val){
            head = head->next;
            
            if(head == NULL)
                break;
        }

        
        ListNode* p = head;

        
        while(p != NULL){
            //If p points to the last node in the chain list
            if(p->next == NULL)
                return head;
            
            if(p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        
        return head;
    }
};