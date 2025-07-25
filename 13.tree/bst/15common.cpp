//we can solve this problem using inorder traversal on both trees and then compare which n all are matching another approach is this

//different way to inorder traversal
// a. first push all the left nodes i.e init stage
// b.pop the first element print it then check if there is any right node for that if so push all the left child of that right nodes
// c.repeat the same until stack is empty you will get your inorder traveral


// so using the above logic we can keep 2 stacks and each time check if the top of the nodes are same if so push that to the ans if one is smaller then pop it and push all the left childs of the right child 
void insertL(Node * root,stack<Node *> &s)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
    }
    
    vector<int> findCommon(Node *r1, Node *r2) {
        // Your code here
        vector<int> ans;
        stack<Node *> s1,s2;
        insertL(r1,s1);
        insertL(r2,s2);
        
        while(!s1.empty() && !s2.empty())
        {
            int one=s1.top()->data,two=s2.top()->data;
            if(one==two)
            {
                ans.push_back(one);
                Node *t1=s1.top();
                Node *t2=s2.top();
                s1.pop();
                s2.pop();
                
                if(t1->right)
                    insertL(t1->right,s1);
                if(t2->right)
                    insertL(t2->right,s2);
                
            }
            else if(one<two)
            {
                Node *t=s1.top();
                s1.pop();
                if(t->right)
                    insertL(t->right,s1);
            }
            else
            {
                Node * t=s2.top();
                s2.pop();
                if(t->right)
                    insertL(t->right,s2);
            }
        }
        return ans;
    }