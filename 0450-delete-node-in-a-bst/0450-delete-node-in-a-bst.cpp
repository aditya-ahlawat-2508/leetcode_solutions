class Solution {
public:

    // Find the rightmost node
    // in a subtree
    TreeNode* findRightmost(TreeNode* root) {

        while (root->right != nullptr) {
            root = root->right;
        }

        return root;
    }


    // Delete a node that has two children
    TreeNode* helper(TreeNode* root) {

        // No right subtree
        if (root->right == nullptr) {
            return root->left;
        }

        // No left subtree
        if (root->left == nullptr) {
            return root->right;
        }

        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;

        // Find the largest node
        // in the left subtree
        TreeNode* rightmost = findRightmost(leftSubtree);

        // Attach right subtree
        // to the rightmost node
        rightmost->right = rightSubtree;

        return leftSubtree;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == nullptr) {
            return nullptr;
        }

        // If root itself is the node to delete
        if (root->val == key) {
            return helper(root);
        }

        TreeNode* curr = root;

        while (curr != nullptr) {

            // Go to LEFT subtree
            if (key < curr->val) {

                if (curr->left != nullptr &&
                    curr->left->val == key) {

                    curr->left = helper(curr->left);
                    break;
                }

                curr = curr->left;
            }

            // Go to RIGHT subtree
            else {

                if (curr->right != nullptr &&
                    curr->right->val == key) {

                    curr->right = helper(curr->right);
                    break;
                }

                curr = curr->right;
            }
        }

        return root;
    }
};