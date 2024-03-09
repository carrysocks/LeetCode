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
    int recur(TreeNode* root, int val){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            val = val * 10 + root->val;
            return val;
        }

        int ans = 0;
        ans += recur(root->left, val*10 + root->val);
        ans += recur(root->right, val*10 + root->val);
        return ans;
    }

    int sumNumbers(TreeNode* root) {    
        return recur(root, 0);
    }
};