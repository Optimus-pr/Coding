
//here the question dosen't state to keep the complete tree property for the tree to be heap so we can violate that 
class Solution {
  public:
    
    void inorder(vector<int> &v,Node * root)
    {
        if(root==0)
            return;
        inorder(v,root->left);
        v.push_back(root->data);
        inorder(v,root->right);
    }
    
    void build(vector<int> &v,Node * root,int &i)
    {
        if(root==0)
            return;
        build(v,root->left,i);
        build(v,root->right,i);
        root->data=v[i++];
    }
  
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int> v;
        inorder(v,root);
        int i=0;
        build(v,root,i);
    }
};