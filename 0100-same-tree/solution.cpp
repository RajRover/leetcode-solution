/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //1
        if(p==NULL && q==NULL) return true;
        //2
        if(p==NULL || q==NULL) return false;
        //3
        if(p->val!=q->val) return false;
        //4
        bool r1=isSameTree(p->left,q->left);
        bool r2=isSameTree(p->right,q->right);
        if(r1&&r2) return true;
        return false;
    }
};
