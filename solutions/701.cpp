// best time: 51 ms (99th percentile), 57.23MB (35th percentile)

/* explanation:
 * we'll move down the BST and either go to the left or the right depending on whether the integer given (val) is less than or greater than the current node's value
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    auto node = root;
    if (node == nullptr)
        return new TreeNode(val);

    while (true)
        if (auto& next = node->val > val ? node->left : node->right; next != nullptr)
            node = next;
        else {
            next = new TreeNode(val);
            return root;
        }

    return root;
}
