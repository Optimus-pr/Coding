#include<bits/stdc++.h>
int fun(int day,int task,vector<vector<int>> &points,vector<vector<int>> &t)
{
    if(day==0)
    {
        int maxi=0;
        for(int i=0;i<3;i++)
            if(i!=task)
                maxi=max(maxi,points[0][i]);
        return maxi;
    }

    if(t[day][task]!=-1)
        return t[day][task];

    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=task)
        {
            maxi=max(maxi,points[day][i]+fun(day-1,i,points,t)); 
        }
            
    }
    return t[day][task]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int> > t(n,vector<int> (4,-1));
    return fun(n-1,3,points,t);

}