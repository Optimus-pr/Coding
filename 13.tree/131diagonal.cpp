 void fun(Node *root,int l,map<int,vector<int> > &m)
    {
        if(root==0)
            return;
        m[l].push_back(root->data);
        
        fun(root->left,l+1,m);
        fun(root->right,l,m);
    }
  
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> ans;
        map<int,vector<int> > m;
        fun(root,0,m);
        for(auto &val:m)
            for(auto info:val.second)
                ans.push_back(info);
        return ans;
    }