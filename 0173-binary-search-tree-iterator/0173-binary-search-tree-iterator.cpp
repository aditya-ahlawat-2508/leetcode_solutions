class BSTIterator {
public:

    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    void pushAll(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {

        TreeNode* temp = st.top();
        st.pop();

        pushAll(temp->right);

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};