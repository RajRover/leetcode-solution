class Solution {
public:
    // helper returns {node, depth}
    pair<TreeNode*, int> solve(TreeNode* root) {
        if (!root) return {nullptr, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.second == right.second) {
            return {root, left.second + 1};
        } else if (left.second > right.second) {
            return {left.first, left.second + 1};
        } else {
            return {right.first, right.second + 1};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).first;
    }
};

