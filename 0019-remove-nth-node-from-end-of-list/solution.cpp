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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        temp=head;
        int k=0;
        ListNode* before=nullptr;
        while(k<cnt-n){
            before=temp;
            temp=temp->next;
            k++;
        }
        if (before == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* after=temp->next;
        if(before) before->next=after;
        delete temp;
        return head;
    }
};
