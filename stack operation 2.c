#include<iostream>
#include<stack>
// 1=push, 2=pop(), 3=min()
using namespace std;
int main()
{
	stack<int> mainstack;
	int n,opn,data,temp,i,c=0,min,minold;
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
					push(data);
					min=data;
				}
				else 
				{
					minold=min;
					if(data<mainstack.top())
						min=data;
					else{}
					push(data);
					
				}
				break;
			}
			case 2 :
			{
					if(mainstack.top()==min)
					{
						min=minold;
					}
					mainstack.pop();
					break;
			}
			case 3 :
			{
				printf("%d \n",min);
			}
			default :
			{
					
			}
		}
	}
