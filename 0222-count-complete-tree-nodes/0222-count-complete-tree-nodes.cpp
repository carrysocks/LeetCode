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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        TreeNode *le = root, *ri = root;

        int l = 0, r = 0;
        while(le){
            l++;
            le = le->left;
        }
        while(ri){
            r++;
            ri = ri->right;
        }

        if(l==r) return pow(2, l) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};