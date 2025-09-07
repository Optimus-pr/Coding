//we will be give a binary tree we need to return the max size of the bst which can be obtained from the tree

class Nodee{
public:
    bool isBst;
    int ht;
    int mx;
    int mn;
    
    Nodee(){
        isBst=false;
        ht=0;
        mx=mn=0;
    }
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Nodee fun(Node * root)
    {
        Nodee t;
        if(root==0)
        {
            t.isBst=true;
            t.ht=0;
            t.mx=INT_MIN;
            t.mn=INT_MAX;
            return t;
        }
        
        Nodee l=fun(root->left);
        Nodee r=fun(root->right);
        
        if(l.isBst==true && r.isBst==true)
        {
            if(root->data > l.mx && root->data<r.mn)
            {
                t.isBst=true;
                t.ht=1+l.ht+r.ht;
                t.mx=max(root->data,r.mx);
                t.mn=min(root->data,l.mn);
            }
            else
                t.ht=max(l.ht,r.ht);
        }
        else
            t.ht=max(l.ht,r.ht);
        return t;
    }
    
    int largestBst(Node *root) {
        // Your code here
        Nodee t=fun(root);
        return t.ht;
    }
}