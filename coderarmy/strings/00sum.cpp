string addStrings(string a, string b) {
        int i=a.size()-1,j=b.size()-1,sum,carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry)
        {
            int x=i>=0?a[i]-'0':0;
            int y=j>=0?b[j]-'0':0;

            int sum=x+y+carry;
            char c=sum%10+'0';
            ans=c+ans;
            carry=sum/10;
            i--;j--;
        }
        return ans;
}