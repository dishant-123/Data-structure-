/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

#include<stack>
using namespace std;
void deleteMid(stack<int> &s,int n,int curr)
{
    if(curr==n/2+1 || s.empty())
        return ;
    int x=s.top();
    s.pop();
    deleteMid(s,n,curr+1);
    if(curr!=n/2)
        s.push(x);
}
int main()
{
    stack<int> stack;
    int arr[]={1,2,3,4},i;
    for(i=0;i<4;i++)    stack.push(arr[i]);
    deleteMid(stack,4,0);
    while(stack.empty()!=1)
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
}

