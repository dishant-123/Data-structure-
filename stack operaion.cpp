//min element after any number of operation.
#include<iostream>
#include<stack>
// 1=push, 2=pop(), 3=min()
using namespace std;
int main()
{
	stack<int> mainstack;
	stack<int> auxistack;
	int n,opn,data,temp,i,c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&opn);
		switch(opn)
		{
			case 1:
			{
				scanf("%d",&data);
				mainstack.push(data);
				if(auxistack.empty())
					auxistack.push(data);
				else
				{
					if(data<auxistack.top())
						auxistack.push(data);
					else{}
				}
				break;
				c++;
			}
			case 2 :
			{
				temp=mainstack.top();
				mainstack.pop();
				if(temp==auxistack.top())
				{
					auxistack.pop();
				}
				break;
			}
			case 3 :
			{
				printf("%d \n",auxistack.top());
				break;
			}
			default :
			{
					
			}
		}
	}
