    void fun(Node * root,int l,int h,vector<int> &v)
    {
        if(root==0)
            return;
        
        if(root->data>l && root->data > h)
            fun(root->left,l,h,v);
        else if(root->data<l && root->data<h)
            fun(root->right,l,h,v);
        else
        {
            fun(root->left,l,h,v);
            v.push_back(root->data);
            fun(root->right,l,h,v);
        }
    }
  
    vector<int> printNearNodes(Node *root, int low, int high) {
        // code here
        vector<int> v;
        fun(root,low,high,v);
        return v;
    }