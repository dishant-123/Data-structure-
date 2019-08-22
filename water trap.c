#include<stdio.h>
int main()
{
	int n,i,g=0,c=0,p=0;
	scanf("%d",&n);
	int arr[n];	
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=1;i<n;i++)
	{
		if(arr[p]>arr[i])
		{
		
			c=c+arr[p]-arr[i];
		}
		else
		{
			g++;
			p=i;
		}
	}
	if(g==0)
		printf("No water trap");
	else
		printf("%d",c);
}
