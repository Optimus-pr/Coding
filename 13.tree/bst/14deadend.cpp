 // if we can't insert any node to the left and right both of a node without breaking bst property then that node is called dead



 bool fun(Node *root,int l,int r)
    {
        if(root==0)
            return false;
        if(root->left==0 && root->right==0)
        {
            if(root->data-l==1 && r-root->data==1)
                return true;
            else
                return false;
        }
        return fun(root->left,l,root->data) || fun(root->right,root->data,r);
    }
  
    bool isDeadEnd(Node *root) {
        // Code here
        return fun(root,0,INT_MAX);
    }