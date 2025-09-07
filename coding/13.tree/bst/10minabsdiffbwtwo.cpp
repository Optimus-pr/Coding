//first approach is we can do inorder traversal which will give vector in sorted order then we can check diff b/w element and it's nxt so the thing is we only need one value that is current and previous element so instead of storing entire vector we can just store prev value using which we can get the result easily
//the same appraoch can be used in checkBST there also we can get the vector and check with the next element but instead we can use the same i.e store prev when we get cur check if prev< cur if so the update prev=cur and proceed if not return false;
void fun(TreeNode * root,int &prev,int &mn)
    {
       if(root==0)
          return;
        fun(root->left,prev,mn);
        if(prev!=INT_MIN)//here we can skipp this line also but there is chance of int overflow so to overcome that we can prevent sub first time as we don't need that so first time this mn won't be calculated and prev will be set to first node
        mn=min(mn,root->val -prev);
        prev=root->val;
        fun(root->right,prev,mn);
    }

    int minDiffInBST(TreeNode* root) {
        int prev=INT_MIN,mn=INT_MAX;
        fun(root,prev,mn);
        return mn;
    }