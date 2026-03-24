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
    bool ismirror(TreeNode* p, TreeNode* q) {
        //1
        if(p==NULL && q==NULL) return true;
        //2
        if(p==NULL || q==NULL) return false;
        //3
        if(p->val!=q->val) return false;
        //4
        bool r1=ismirror(p->left,q->right);
        bool r2=ismirror(p->right,q->left);
        if(r1&&r2) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return ismirror(root->left,root->right);
    }
};
