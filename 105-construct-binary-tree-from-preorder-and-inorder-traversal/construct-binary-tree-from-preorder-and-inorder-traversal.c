struct TreeNode* helper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];

    int rootIndex = inStart;
    while (inorder[rootIndex] != root->val) {
        rootIndex++;
    }

    int leftTreeSize = rootIndex - inStart;

    root->left = helper(preorder, preStart + 1, preStart + leftTreeSize, inorder, inStart, rootIndex - 1);
    root->right = helper(preorder, preStart + leftTreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return helper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}