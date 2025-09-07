//design a stack which can do push pop and give minele at the moment

// this is simple because we know the consept of storing 2 values in a single var by which we can store the number and also store min in the same element but the thing is we should be knowing the range i.e if 1-100 is the range of the element givent then while pushing we can do ele*101+min while retriving if we do s.top()/101 we get the top element and s.top%101 will give the min element 
//if range is not given then we can't do that because this will lead to int overflow we also know one more approach i.e eg if 5 comes store 5 min is 5 nxt 3 comes store 2*3-5 in stack and min will be 3 while poping check if top<min => we have stored something else to retrieve that we can do 2*min-top i.e 2*3-1=5 wil be the new min

// Get min at pop i.e we need to push all the elements and then when pop is called return min this is simpler version of the above 
// stack<int> _push(int arr[], int n) {
//     // your code here
//     stack<int> s;
//     if(n==0)
//         return s;
//     s.push(arr[0]);
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]<s.top())
//             s.push(arr[i]);
//         else
//             s.push(s.top());
//     }
    
// }

// // Function to print minimum value in stack each time while popping.
// void _getMinAtPop(stack<int> s) {
//     while(!s.empty())
//     {
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     // your code here
// }