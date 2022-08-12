class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;

        
        int leftmax = diameterOfBinaryTree(root.left);
        int rightmax = diameterOfBinaryTree(root.right);
        return Math.max(getHeight(root.left) + getHeight(root.right), Math.max(leftmax, rightmax));
    }
    
    private int getHeight(TreeNode root) {
        if (root == null) return 0;
        
        return Math.max(getHeight(root.left), getHeight(root.right)) + 1;
    }
}