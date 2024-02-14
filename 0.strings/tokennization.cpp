// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	string s;
// 	getline(cin,s);

// 	stringstream ss(s);
// 	string token;

// 	while(getline(ss,token,' ')){
// 		cout<<token<<endl;
// 	}
// 	return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	char a[100];
// 	cin.getline(a,100);

// 	char * token=strtok(a," ");

// 	while(token!=NULL)
// 	{
// 		cout<<token<<endl;
// 		token=strtok(NULL," ");
// 	}

// }

#include<bits/stdc++.h>
using namespace std;

int main()
{
	//reading multi word string
	// string s;
	// getline(cin,s);

	//reading multi word char array;

	char a[1000];
	cin.getline(a,1000);

	//converting string to char array c_str() method this returns a const char * but strtok req only char * so const_cast<char *> will remove const from it 
	// const char * b=s.c_str();
	 
	// char *token=strtok(const_cast<char*>(b)," ");
	// while(token!=NULL)
	// {
	// 	cout<<token<<endl;
	// 	token=strtok(NULL," ");
	// }

	//converting char array into string (string)
	string c=(string)a;
	string token;
	stringstream ss(c);
	while(getline(ss,token,' '))
	{
		cout<<token;
	}
}