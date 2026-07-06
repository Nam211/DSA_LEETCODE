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
    int maxDepth(TreeNode* root) {
        // Base Case: If we step onto a null pointer slot, its height contribution is 0
        if (root == nullptr) return 0;
        
        // Step 1: Dive down and discover the height of the left sub-branch
        int lh = maxDepth(root->left);
        
        // Step 2: Dive down and discover the height of the right sub-branch
        int rh = maxDepth(root->right);
        
        // Step 3: Compute bottom-up logic: 1 (current node) + max height among paths
        return 1 + max(lh, rh);
    }
};