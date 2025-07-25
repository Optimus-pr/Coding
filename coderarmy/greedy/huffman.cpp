//huffman encoding - used in compression algo
    // a-5,b-9,c-12,d-13,e-16,f-45 total 100 characters 
    // so if we sent this with normal way then it will take 100*8(ascii) i.e 800 bits need to be transfered so if we are smart what we can do is here we can see 6 char so max we need 3 bits to represent all of them but receiver should also decode the same right as we are not using ascii we are creating our encoding so 100*3 bits + map(6*3)=318 bits

    // we can be more creative and think like here f is repeated 45 times so what if we give f a code 0 like wise e=1 d-10 c-11 b-100 a-101 along with this we need to send a map also but here lies a problem i.e if 11 is sent receiver will be confused to treat it as ee or c 

    // so what huffman thought was somewhat the same i.e high freq char should take less bit but the approach was bit diff that approach is noted below take 2 smaller freq char and form a node out of that with char $ and freq=combined freq of these 2 [note smaller node will be on the left] and add this to the queue like wise repeat the same until only one element is left which is the root of the tree for encoding now for each left traversal append 0 bit and for every right traversal 1
    // in the final tree f will be on left of the root so it will have code 0 unlike other approach we won't face the difficulty that other char may get 00 then receiver will be confused 
    
    class Node{
        public:
        int freq;
        char c;
        Node * left,*right;
        
        Node(int f,char ch)
        {
            freq=f;
            c=ch;
            left=right=0;
        }
    };
    
    class comp{
        public:
        bool operator()(Node *a,Node *b)
        {
            return a->freq > b->freq;
        }
    };
    
    
    void preorder(Node *root,vector<string> &ans,string &s)
    {
        if(root==0)
            return;
        if(root->left==0 && root->right==0){
            ans.push_back(s);
            return;
        }
        
        s.push_back('0');
        preorder(root->left,ans,s);
        s.pop_back();
        
        s.push_back('1');
        preorder(root->right,ans,s);
        s.pop_back();
        
    }
        
    vector<string> huffmanCodes(string s, vector<int> f, int N) {
        // Code here
        priority_queue<Node*,vector<Node *>,comp> q;
        for(int i=0;i<s.size();i++)
            q.push(new Node(f[i],s[i]));
            
        while(q.size()>1)
        {
            Node *first=q.top();q.pop();
            Node *second=q.top();q.pop();
            
            Node * root=new Node (first->freq+second->freq,'$');
            root->left=first;
            root->right=second;
            
            q.push(root);
        }
        
        Node *root=q.top();
        vector<string> ans;
        string temp="";
        preorder(root,ans,temp);
        return ans;
    }