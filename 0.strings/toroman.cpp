
class Solution{
  public:
    string convertToRoman(int n) {
        // code here
      
       vector<pair<string,int> > v={{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
        
       string s="";
       for(auto &val:v)
       {
           string a=val.first;
           int b=val.second;
           
           int N=n/b;
          
           for(int i=0;i<N;i++)
            s.append(a);
           n=n%b;
           
           
       }
        return s;
    
    }
};