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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* i=head;
        ListNode* j=i->next;
        ListNode* k=i->next;
        while(k){
            k=j;
            if(j==NULL) break;
            j=j->next;
            if(k->val==i->val){
                i->next=j;
            }
            else{
                i=i->next;
            }
        }
        return head;

    }
};
