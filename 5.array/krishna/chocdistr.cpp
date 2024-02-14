//array containing n packets where each packet contains any number of chocolates you have 2 distribute those packets among m students such that the difference between 1 with max chocolate and 1 with minimum chocolate shoudl be minimum;


sortA
min=a[n-1];
for(int i=0;i<=n-m;i++)
{
	if(a[i+m-1]-a[i]<min)
		min=a[i+m-1]-a[i];

}