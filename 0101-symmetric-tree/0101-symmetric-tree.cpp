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
    bool iter(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr || left->val != right->val) return false;
        return iter(left->left, right->right) && iter(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return iter(root->left, root->right);
    }
};