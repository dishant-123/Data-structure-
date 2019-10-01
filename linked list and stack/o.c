#include<stdio.h>
int main()
{
	//int i=1<<31;
	 int i1 = sizeof(unsigned long long int) * 8 - 1;
	 int i=i1<<i;
	int j=1,c=0,l,r,c1=0;
	int num=4;
	while(j<i)
	{
		r=j&num;
		l=i&num;
		if(r!=0)
			r=1;
		else
			r=0;
		if(l!=0)
			l=1;
		else
			l=0;
	//	printf("%d %d \n",l,r);
		if(r!=l)
		{
			num=num^j;
			num=num^i;
			c1++;
		}
		i=i>>1;
		j=j<<1;
		c++;
	}
	printf("%d",num);
	
}
