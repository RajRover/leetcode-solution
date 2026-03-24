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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int leftToRight=1;
        queue<TreeNode*> q;
        if(!root) return {};
        q.push(root);
        vector<vector<int>> res;
        int L2R=1;
        while(!q.empty()){
            int lvlsize=q.size();       
            int first=0;
            int last=lvlsize-1;
            vector<int> temp(lvlsize);
            while(lvlsize--){
                TreeNode* t=q.front();
                q.pop();
                if(L2R==1 ){
                    temp[first]=t->val;
                    first++;
                }
                if(L2R==0){
                    temp[last]=t->val;
                    last--;
                }
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                
            }
            L2R=1-L2R;
            res.push_back(temp);
        }
        return res;
    }
};
