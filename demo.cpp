#include<bits/stdc++.h>
using namespace std;

bool safe(int r,int c,vector<vector<int> > &ch)
{
    for(int i=r-1,j=c;i>=0;i--)
        if(ch[i][j]==1)
            return false;
    for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
        if(ch[i][j]==1)
            return false;
    for(int i=r-1,j=c+1;i>=0 && j<ch.size();i--,j++)
        if(ch[i][j]==1)
            return false;
    return true;
}

void rec(int i,vector<vector<int> > &c,string s)
{
    if(i==c.size())
    {
        cout<<s<<endl;
        return;
    }

    for(int j=0;j<c.size();j++)
    {
        if(safe(i,j,c))
        {
            c[i][j]=1;
            rec(i+1,c,s+to_string(i)+"-"+to_string(j)+",");
            c[i][j]=0;
        }
    }
}

int main()
{
    vector<vector<int> > chess(2,vector<int> (2,0));
    rec(0,chess,"");
    return 0;
}