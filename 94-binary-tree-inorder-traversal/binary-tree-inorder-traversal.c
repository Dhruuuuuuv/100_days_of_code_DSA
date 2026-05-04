void traverse(struct TreeNode* root, int* returnSize, int* result) {
    if (root == NULL) return;
    
    traverse(root->left, returnSize, result);
    result[(*returnSize)++] = root->val;
    traverse(root->right, returnSize, result);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    traverse(root, returnSize, result);
    return result;
}