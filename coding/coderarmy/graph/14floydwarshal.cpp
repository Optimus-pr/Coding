// this algo is used to find multi src shortest path this is applicable only for directed graph it way contain -ve wts and -ve wtd cycle also 
//this algo takes each vertex as intermediary and tries to find the shortest path kind of transitive property
//don't be under impression that a-c => taking d as intermidiary that doesn't mean a-d-c there may or may not be some xtra verticies meaning a-b-d-c meaning a-d =>a-b-d 
//the order of vertcies in which we take intermediary doesn't matter
//we can also do dijikstra for all vertex and compute distance but -ve wts are one issue

int n=dis.size();
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dis[i][k]!=1e8 && dis[k][j]!=1e8)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);