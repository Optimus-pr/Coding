void fun(TreeNode * root,int &prev,int &mn)//note here passing by ref is very imp
{
   if(root==0)
      return;
    fun(root->left,prev,mn);
    mn=min(mn,root->val -prev);
    prev=root->val;
    fun(root->right,prev,mn);
}

int minDiffInBST(TreeNode* root) {
    int prev=-1000000,mn=INT_MAX;
    fun(root,prev,mn);
    return mn;
}