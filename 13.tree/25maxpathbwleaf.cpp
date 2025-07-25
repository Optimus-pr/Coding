class Solution {
    int mx;
  public:
    Solution(){
        mx=INT_MIN;
    }
    
    int fun(Node *root)
    {
        if(root==0)
            return 0;
        if(root->left==0 && root->right ==0)
            return root->data;
            
        int l=fun(root->left);
        int r=fun(root->right);
        
        if(root->left && root->right)
        {
            mx=max(mx,root->data+l+r);
            return root->data+max(l,r);
        }
        
        if(root->left)
            return root->data+l;
        if(root->right)
            return root->data+r;
        
    }
    
    int maxPathSum(Node* root) {
        // code here
        int val=fun(root);
        if(root->left && root->right)
            return mx;
        return max(mx,val);
    }
};