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
        if(!head) return head;
        ListNode* last=head;
        int n=1;
        while(last->next){
            n++;
            last=last->next;
        }
        if(last==head) return head;
        k=k%n;
        if(k==0) return head;
        int c=n-k;
        int cnt=1;
        ListNode* temp=head;
        while(temp){
            if(cnt==c){
                break;
            }
            cnt++;
            temp=temp->next;
        }
        ListNode* res=temp->next;
        last->next=head;
        temp->next=NULL;
        head=res;
        return head;
    }
};
