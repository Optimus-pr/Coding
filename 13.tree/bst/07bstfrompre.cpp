   //this is o(n) approach other normal approach will take o(n2)
    TreeNode * fun(vector<int> &v,int l,int r,int &i)
    {
        if(i==v.size() || v[i]<l || v[i]>r)
            return NULL;

        TreeNode * root= new TreeNode(v[i++]);
        root->left=fun(v,l,root->val,i);
        root->right=fun(v,root->val,r,i);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return fun(preorder,INT_MIN,INT_MAX,ind);
    }



//construct from postorder same as above but start with index n-1 and right left
    TreeNode * fun(vector<int> &v,int l,int r,int &i)
    {
        if(i<0 || v[i]<l || v[i]>r)
            return NULL;

        TreeNode * root= new TreeNode(v[i--]);
        root->right=fun(v,root->val,r,i);
        root->left=fun(v,l,root->val,i);
        

        return root;
    }

    TreeNode* bstFromPostorder(vector<int>& postorder) {
        int ind=postorder.size()-1;
        return fun(postorder,INT_MIN,INT_MAX,ind);
    }



//check if we can create a bst from pre

    void fun(int *arr,int l,int r,int &i,int &N)
    {
        if(i==N || arr[i]<l || arr[i]>r)
            return;
        
        int val=arr[i++];
        fun(arr,l,val,i,N);
        fun(arr,val,r,i,N);
    }
  
    int canRepresentBST(int arr[], int N) {
        // code here
        int i=0;
        fun(arr,INT_MIN,INT_MAX,i,N);
        return i==N;
    }

    // this problem in gfg was giving seg fault for N= 1lakh eventhought the TC is o(n) and this approach takes o(n) but if we solve the same using iterativa approach it was passing the reason is recursion uses stack in memeory which will be limited in  memeory it was gfg's responsibility to make that much space available but when we try to solve iteratively we use stl's stack which will be created in heap which will have more memeory so no fault

//this is the iterative version of the above code 
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<pair<int,int> > s;
        s.push({INT_MIN,INT_MAX});
        int i=0;
        while(i<N && !s.empty())// it is must to add i<N or else at one stage stack becomes empty and all the elements would not been checked but it goes out of the loop
        {
            pair<int,int> p=s.top();
            s.pop();
            
            if(arr[i]<p.first || arr[i]>p.second)
                continue;
            
            int val=arr[i++];
            s.push({val,p.second});//right
            s.push({p.first,val});//left
            
        }
        return i==N;
        
    }