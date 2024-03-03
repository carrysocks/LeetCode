/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isBalanced(TreeNode root) {
        ba=true;
        postOrder(root);
        return ba;
    }
    boolean ba;
    int postOrder(TreeNode node){
        if(node==null) return 0;
        int left=postOrder(node.left), right=postOrder(node.right);
        if(Math.abs(left-right)>1){
            ba=false;
        }
        return Math.max(left, right)+1;
    }
}