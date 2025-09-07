
#include<iostream>
#include<string>
using namespace std;


int main(){
  string input;
  cout<<"Enter the string"<<endl;
  cin>>input;
  
  string temp = input + input;

  cout<<"Enter the string to compare: ";
  string newString;
  cin>>newString;

  int windowLen = input.length();

  for(int i = 0;i<windowLen;i++){
    if(newString == temp.substr(i,windowLen))
    {
      cout<<"Yayy!";
      break;
    }
  }

  return 0;
}
