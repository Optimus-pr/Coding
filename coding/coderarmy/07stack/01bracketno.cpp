//here don't go with using stack<pair<char,int> > n all just think

vector<int> bracketNumbers(string str) {
        // Your code goes here
        stack<int> s;
        vector<int> v;
        int cnt=1;
        for(auto &val:str)
        {
            if(val=='('){
                v.push_back(cnt);
                s.push(cnt++);
            }
            else if(val==')'){
                v.push_back(s.top());
                s.pop();
            }
        }
        return v;
    }