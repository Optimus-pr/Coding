#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * next;

    Node(int d)
    {
        data=d;
        next=0;
    }
};

Node * insertrear(int * a,int n)
{
    Node * head,*t,*tp;
    for(int i=0;i<n;i++)
    {
        t=new Node(a[i]);
        if(i==0)
        {
            tp=t;
            head=t;
        }
        else
        {
            tp->next=t;
            tp=tp->next;
        }
    }
    return head;
}

void display(Node * &head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

string convertTostring(Node * head1)
{
    string s="";
    while(head1)
    {
        s+=('0'+head1->data);
        head1=head1->next;
    }
    return s;
}
    
string trimZeroes(string &s)
{
    int i=0;
    while(s[i]=='0')
        i++;
    return s.substr(i);
}

void findGreater(string &a,string &b)
{
    if(b.size()>a.size())
        swap(a,b);
    else if(a.size()==b.size())
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[i])
                continue;
            else if(a[i]<b[i])
                swap(a,b);
            return;
        }
    }
}
    
string sub(string a,string b)
{
    string s="";

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    // cout<<a<<" "<<b;

    int i=0;

    for(i=0;i<b.size();i++)
    {
        int t=(a[i]-'0')-(b[i]-'0');
        if(t>=0)
            s+=(t+'0');
        else
        {
            s+=(((a[i]-'0')+10)-(b[i]-'0'))+'0';
            if(a[i+1]!='0')
                a[i+1]=(a[i+1]-1);
            else
            {
                a[i+1]='9';
                for(int j=i+2;j<a.size();j++)
                    if(a[j]!='0')
                    {
                        a[j]=a[j]-1;
                        break;
                    }
            }
        }
        cout<<a<<" "<<b<<endl;
    }

    for(;i<a.size();i++)
    {
        if(a[i]!='0')
            s+=a[i];
    }
    reverse(s.begin(),s.end());
    trimZeroes(s);
    return s;
}

int main()
{
    int ar1[]={4,5};
    int ar2[]={3,1};

    Node * h1=insertrear(ar1,2);
    Node * h2=insertrear(ar2,2);

    string sa,sb;
    sa=convertTostring(h1);
    sb=convertTostring(h2);
    //cout<<sa<<" "<<sb;

    sa=trimZeroes(sa);
    sb=trimZeroes(sb);
    // cout<<sa<<" "<<sb;
    
    if(sa==sb)
        // return new Node(0);
        cout<<"hi";
    
    findGreater(sa,sb);

    cout<<sub(sa,sb);

    // cout<<sa<<" "<<sb;   
}