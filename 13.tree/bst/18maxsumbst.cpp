//this is same as last problem but here we need to find the max sum of all the bst which we can find in the given binary tree

class Nodee{
public:
    bool isBst;
    int sum;
    int mx;
    int mn;
    
    Nodee(){
        isBst=false;
        sum=0;
        mx=INT_MIN;
        mn=INT_MAX;
    }
};

class Solution {
public:
int ans=0;
Nodee fun(TreeNode * root)
    {
        Nodee t;
        if(root==0)
        {
            t.isBst=true;
            t.sum=0;
            t.mx=INT_MIN;
            t.mn=INT_MAX;
            return t;
        }
        
        Nodee l=fun(root->left);
        Nodee r=fun(root->right);
        
        if(l.isBst==true && r.isBst==true)
        {
            if(root->val > l.mx && root->val<r.mn)//if left and right subtree are bst for the tree along with root to be parent root->data should be > max in left sub tree and < than least in right so when we encounter leaf we return mx=INT_MIN and mn=INT_MAX to hold this condition
            {
                t.isBst=true;
                t.sum=root->val+l.ht+r.ht;
                t.mx=max(root->val,r.mx);
                t.mn=min(root->val,l.mn);
                ans=max(t.ht,ans);
            }
            else
                t.sum=max(l.ht,r.ht);
        }
        else
            t.sum=max(l.ht,r.ht);
        return t;
    }
    int maxSumBST(TreeNode* root) {
        Nodee t=fun(root);
        return ans;
    }
};