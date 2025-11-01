// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        // If tree is empty, create new node
        if (root == null) {
            return new TreeNode(val);
        }

        // Go to left subtree if value is smaller
        if (val < root.val) {
            root.left = insertIntoBST(root.left, val);
        }
        // Go to right subtree if value is larger
        else if (val > root.val) {
            root.right = insertIntoBST(root.right, val);
        }

        return root;  // return unchanged root
    }
}
