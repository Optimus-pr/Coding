// You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.

// You must find the minimum number of months needed to complete all the courses following these rules:

// You may start taking a course at any time if the prerequisites are met.
// Any number of courses can be taken at the same time.
// Return the minimum number of months needed to complete all the courses.

// Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).



int minimumTime(int n, vector<vector<int>>& r, vector<int>& t)   { 
        vector<int> * g=new vector<int>[n];
        vector<int> p(n,0);
        // vector<int> g(n);
        vector<int> in(n,0);
        for(auto &val:r){
            g[val[0]-1].push_back(val[1]-1);
            in[val[1]-1]++;
        }

        queue<int> q;
        int mx=INT_MIN,ans=0,ver,tp;
        for(int i=0;i<n;i++){
            // p[i]=t[i];
            if(in[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            ver=q.front();
            q.pop();
            for(auto &child:g[ver]){
                if(--in[child]==0)
                    q.push(child);
                p[child]=max(p[child],p[ver]+t[ver]);
            }
            
        }
        for(int i=0;i<n;i++)
        {
            mx=max(mx,p[i]+t[i]);
        }
            cout<<endl;
        return mx;
    }