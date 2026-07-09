class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        // Flag to track alternating directions: true = left-to-right, false = right-to-left
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            // Allocate a vector with fixed memory slots matching the level size
            vector<int> row(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Determine the exact index position where this element belongs on-the-fly
                int index = leftToRight ? i : (size - 1 - i);
                row[index] = node->val; // Direct memory slot assignment
                
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // Invert the directional flag for the next horizontal row layer
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        
        return result;
    }
};