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
    long SUM=0;
    long maxp=0;
    int totalsum(TreeNode* root){
        if(root==NULL) return 0;
        int leftsum=totalsum(root->left);
        int rightsum=totalsum(root->right);
        long subtree_sum=root->val+leftsum+rightsum;
        long rem_sum=SUM-subtree_sum;
        maxp=max(maxp,subtree_sum*rem_sum);
        return subtree_sum;
    }
    int maxProduct(TreeNode* root) {
        SUM=totalsum(root);
        totalsum(root);
        return maxp%(1000000007);
    }
};
