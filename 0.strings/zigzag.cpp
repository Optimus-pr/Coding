#include<bits/stdc++.h>
using namespace std;



string convert(string s, int n) {
    //code
    string st="";
    if(n==1)
        return s;
    
    int cnt=(n-1)*2;
    
    for(int i=0;i<n;i++)
    {
        if(i==0 || i==n-1)
        {
            for(int t=i;t<s.size();t+=cnt)
                st.push_back(s[t]);
            // cout<<i<<"above "<<st<<endl;
        }
        else
        {
            for(int t=i;t<s.size();t+=cnt)
            {
                int cnt1=cnt -2*i;
                st.push_back(s[t]);
                if(t+cnt1<s.size())
                st.push_back(s[t+cnt1]);
            }
            // cout<<i<<"below "<<st<<endl;
        }
    }
    return st;
}

int main()
{
    string s;
    int n;
    cin>>s>>n;

    cout<<convert(s,n);
    return 0;
}