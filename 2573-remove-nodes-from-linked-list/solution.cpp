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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp=head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        ListNode* newHead = nullptr;
        int maxVal = INT_MIN;
        while(!st.empty()){
            ListNode* node=st.top();
            st.pop();
            if(node->val>=maxVal){
                maxVal=node->val;
                node->next=newHead;
                newHead=node;
            }
        }
        return newHead;
    }
};
