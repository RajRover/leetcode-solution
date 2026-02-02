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
    void reverse(ListNode*left,int size){
        ListNode* curr=left;
        ListNode* prev=NULL;
        while(size--){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        ListNode* left=head;
        ListNode* right;
        ListNode* prevleft=NULL;
        ListNode* res=nullptr;
        while(true){
            right=left;
            for(int i=0;i<1;i++){
                if(right==NULL) break;
                right=right->next;
            }
            if(right){
                ListNode* nextleft=right->next;
                reverse(left,2);
                if(prevleft){
                    prevleft->next=right;
                }
                prevleft=left;
                if(res==NULL) res=right;
                left=nextleft;
            }
            else{
                if(prevleft){
                    prevleft->next=left;
                }
                //1node
                if(res==NULL){
                    res=left;
                }
                break;
            }

        }
        return res;
    }
};
