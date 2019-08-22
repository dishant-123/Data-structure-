#include<iostream>
#include<stack>
// 1=push, 2=pop(), 3=min()
using namespace std;
int main()
{
	stack<int> mainstack;
	int n,opn,data,temp,i,c=0,min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&opn);
		switch(opn)
		{
			case 1:
			{
				scanf("%d",&data);
				if(mainstack.empty())
				{
					mainstack.push(data);
					min=data;
				}
				else if(data>min)
				{
					mainstack.push(data);
				}
				else
				{
					mainstack.push(2*data-min);
					min=data;
				}
				break;
			}
			case 2 :
			{
				if(mainstack.top()<min)
				{
					min=2*min-mainstack.top();
				}
				mainstack.pop();
			}
			case 3 :
			{
				printf("%d \n",min);
			}
		}
	}
}
