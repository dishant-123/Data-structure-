#include<stdio.h>
//int invCount=0;
int merge(int arr[],int l,int m,int r)
{
	int s1=m-l+1,inv=0;
	int s2=r-m;
	int i,j,k;
	//int *lArray=(int *)malloc(sizeof(s1));
	//int *rArray=(int *)malloc(sizeof(s2));
	int lArray[s1];
	int rArray[s2];
	for(i=0;i<s1;i++)
		lArray[i]=arr[l+i];
	for(j=0;j<s2;j++)
		rArray[j]=arr[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<s1 && j<s2)
	{
		if(lArray[i]<=rArray[j])
		{
			arr[k]=lArray[i];
			i++;
		}
		else{
			arr[k]=rArray[j];
			inv+=(m-i);
			//printf("%d \n",invCount);
			j++;
		}
		k++;	
	}
	while(i<s1)
	{
		arr[k]=lArray[i];
		k++;i++;
	}
	while(j<s2)
	{
		arr[k]=rArray[j];
		k++;j++;
	}
	return inv;		
}
void print(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
int mergeSort(int arr[],int l,int r)
{
	int inv=0;
	if(l<r)
	{
		int mid=(l+r)/2;
		inv+=mergeSort(arr,l,mid);
		inv+=mergeSort(arr,mid+1,r);
		inv+=merge(arr,l,mid,r);
	}
	return inv;
}
int main()
{
	int arr[]={ 38,37,43,3,9,82,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int inv=mergeSort(arr,0,n-1);
	print(arr,n);
	printf("\n%d \n",inv);
	//print("\n%d\n",invCount);
}
