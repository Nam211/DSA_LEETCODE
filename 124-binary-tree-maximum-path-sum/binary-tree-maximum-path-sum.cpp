class Solution {
private:
    int calculateMaxPath(TreeNode* node, int& maxi) {
        if (node == nullptr) return 0;
        
        
        int leftMaxPath = max(0, calculateMaxPath(node->left, maxi));
        
       
        int rightMaxPath = max(0, calculateMaxPath(node->right, maxi));
        
        
        int localPathSum = node->val + leftMaxPath + rightMaxPath;
        
        // Step 4: Update our global tracker if this local curve is the best found so far
        maxi = max(maxi, localPathSum);
        
        
        return node->val + max(leftMaxPath, rightMaxPath);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; 
        calculateMaxPath(root, maxi);
        return maxi;
    }
};