//we will be given a bst where 2 nodes will be swapped we need to find those 2 and swap their value again

//first and easy approach is to do inorder traversal and store it in a vector
//then traverse that vector there are 2 poss i.e 1 2 3 4 should be the ideal bst if 2 and 3 are swapped then 1 3 2 4 we fill find only one gadbad i.e first=3 second=2 but if 1 and 4 were swapped i.e 4 2 3 1 here 4<2 false so first =4 second=2 later 3<1 false so just update second=1 i.e when we get the first mismatch update both first and second because we don't know if we get 1 mismatch or 2 mismatch if we don't get 2 mismatch then just swap first and second value but if second mismatch is obtained the update just second value 
//this approach is fine but we take o(n) space also the below approach is o(1) approach => no recursion => no stack space also we can achieve O(1) space by using morris traversal 
//first write code for morris inorder traversal later where even i have print statement replace with
                // p=c;
                // c=root;
                // if(p && p->data>c->data)
                // {
                //     if(!f)
                //         f=p;
                //     s=c;
                // }

void correctBST(Node* root) {
        // add code here.
        Node * p=NULL,*c=NULL,*f=NULL,*s=NULL;
        
        while(root)
        {
            if(root->left==0)
            {
                p=c;
                c=root;
                if(p && p->data>c->data)
                {
                    if(!f)
                        f=p;
                    s=c;
                }
                root=root->right;
            }
            else
            {
                Node * t=root->left;
                while(t->right && t->right!=root)
                    t=t->right;
                if(t->right==0)
                {
                    t->right=root;
                    root=root->left;
                }
                else
                {
                    t->right=0;
                    p=c;
                    c=root;
                    if(p && p->data>c->data)
                    {
                        if(!f)
                            f=p;
                        s=c;
                    }
                    root=root->right;
                }
            }
        }
        swap(f->data,s->data);
    }