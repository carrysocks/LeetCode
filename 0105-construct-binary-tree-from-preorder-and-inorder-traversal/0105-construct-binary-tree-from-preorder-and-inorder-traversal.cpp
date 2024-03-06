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
    TreeNode* recur(int preIndex, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preIndex >= preorder.size() || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(0);
        int cur = preorder[preIndex];
        int inIndex = 0;
        for(int i=inStart;i<=inEnd;i++){
            if(cur == inorder[i])
                inIndex = i;
        }

        root->val = cur;
        root->left = recur(preIndex + 1, inStart, inIndex - 1, preorder, inorder);
        root->right = recur(preIndex + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recur(0, 0, inorder.size()-1, preorder, inorder);
    }
};