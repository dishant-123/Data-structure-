// C++ program to find maximum rectangular area in 
// linear time 
#include<iostream> 
#include<stack> 
using namespace std; 

// The main function to find the maximum rectangular 
// area under given histogram with n bars 
int getMaxArea(int arr[], int n) 
{ 
	int max_area=0,left,right,i,area,c=0;
  	for(i=0;i<n;i++)
    {
     	left = i;
     	right =i;
      	while(left>=0 && right<n){
          c = 0;
          if(arr[left-1] >= arr[i])
          {
            left  = left - 1;
            c=1;
          }
          if(arr[right+1] >= arr[i])
          {
           	right = right + 1;
            c=1;
          }
          if(c==0)
            break;
        }
      	area = (right - left + 1 )*arr[i];
      	if(area > max_area)
          	max_area = area;
    }
  	return max_area;
} 

// Driver program to test above function 
int main() 
{ 
	int hist[] = {6, 2, 5, 4, 5, 1, 6}; 
	int n = sizeof(hist)/sizeof(hist[0]); 
	cout << "Maximum area is " << getMaxArea(hist, n); 
	return 0; 
} 
