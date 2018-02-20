/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> bst_stck;
    BSTIterator(TreeNode *root) {
        root = root;
        TreeNode *temp = root; 
        while(temp){
            bst_stck.push(temp);
            temp = temp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !bst_stck.empty();
        // if(bst_stck.size())
        //     return true;
        // else
        //     return false;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = bst_stck.top();
        bst_stck.pop();
        int next_smallest_number = top->val;
        top = top->right;
        while(top){
            bst_stck.push(top);
            top = top->left;
        }
        return next_smallest_number;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */