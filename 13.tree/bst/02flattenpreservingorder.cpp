void solve(Node* root,Node* &pre,Node* &ans)
{
    if(!root)return;
    
    solve(root->left,pre,ans);
    if(!pre){
        pre=root;
        ans=root;
    }
    else{
        pre->right=root;
        root->left=nullptr;
        pre=root;
    }
    solve(root->right,pre,ans);
}

Node *flattenBST(Node *root)
{
    Node* ans=nullptr;
    Node* pre=nullptr;
    solve(root,pre,ans);
    return ans;
}