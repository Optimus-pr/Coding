#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;
//     *
//    **
//   ***
//  ****
// *****
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<"*";
        cout<<endl;
    }
//     1
//    22
//   333
//  4444
// 55555
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<i;
        cout<<endl;
    }
//     1
//    12
//   123
//  1234
// 12345
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<j;
        cout<<endl;
    }
//     a
//    ab
//   abc
//  abcd
// abcde
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<char('a'+(j-1));
        cout<<endl;
    }
//     1
//    21
//   321
//  4321
// 54321
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=i;j>=1;j--)
            cout<<j;
        cout<<endl;
    }
//     *
//    ***
//   *****
//  *******
// *********
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=1;j<=2*i-1;j++)
            cout<<"*";
        cout<<endl;
    }
//     1
//    121
//   12321
//  1234321
// 123454321
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        int cnt=2*i-1;
        for(int j=1;j<=i;j++)
            cout<<j;
        for(int j=cnt-i;j>=1;j--)
            cout<<j;
        cout<<endl;

    }
    //or
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<j;
        for(int j=i-1;j>=1;j--)
            cout<<j;
    cout<<endl;
    }

// *********
//  *******
//   *****
//    ***
//     *
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
            cout<<" ";
        for(int j=(n-(i-1))*2-1;j>=1;j--)
            cout<<"*";
        cout<<endl;
    }
    // or
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=1;j<=2*i-1;j++)
            cout<<"*";
        cout<<endl;
    }

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// **      **
// ***    ***
// ****  ****
// **********

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
            cout<<"*";
        for(int j=1;j<=2*(n-i);j++)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<"*";
        cout<<endl;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cout<<"*";
        for(int j=1;j<=2*(n-i);j++)
            cout<<" ";

        for(int j=1;j<=i;j++)
            cout<<"*";
        cout<<endl;
    }
cout<<endl;
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cout<<"*";
        for(int j=1;j<=2*(n-i);j++)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<"*";
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
            cout<<"*";
        for(int j=1;j<=2*(n-i);j++)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<"*";
        cout<<endl;
    }
    cout<<endl;
 //     * 
 //    * * 
 //   * * * 
 //  * * * * 
 // * * * * * 
 //  * * * * 
 //   * * * 
 //    * * 
 //     * 
    for(int i=1;i<=n;i++)
    {
        for(int j=n-(i-1);j>=1;j--)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<"* ";
        cout<<endl;
    }

    for(int i=n-1;i>=1;i--)
    {
        for(int j=n-(i-1);j>=1;j--)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<"* ";
        cout<<endl;
    }