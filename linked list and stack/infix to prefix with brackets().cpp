#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#include<stack>
void swap(char *a,char *b)
{
    char c=*a;
    *a=*b;
    *b=c;
}
int operand(char optr)
{
    if(optr=='-' || optr=='/' || optr=='*' || optr=='+')
        return 1;
    return 0;
}
int operatr(char oprnd)
{
    if((oprnd>='a' && oprnd <='z') || (oprnd >='A' && oprnd  <='Z') || (oprnd >='0' && oprnd<='9'))
        return 1;
    else
        return 0;
    
}
int calcWeight(char op)
{
	int weight;
	switch(op)
	{
		case '-':
			weight=1;
			break;
		case '+':
			weight=2;
			break;
		case '*':
			weight=3;
			break;
		case '/':
			weight=4;
			break;
			
	}
	return weight;
}
int highPrecedence(char a,char b)
{
    int a1=calcWeight(a);
    int a2=calcWeight(b);
    return a1-a2;
}
string prefix(string infix,int n)
{
    int i,k=0;
    stack<char> charStack;
    int n1=n;
    //char *result=(char *)malloc(sizeof(char)*n);
    string result="";
    for(i=0;i<n;i++)
    {
        if(infix[i]=='(')   charStack.push(infix[i]);
        else if(operatr(infix[i])) 
        {
            result+= infix[i];
        }
        //(a+b)
        else if(operand(infix[i]))
        {
            while( charStack.empty()!=1 && charStack.top()!='(' && highPrecedence(charStack.top(),infix[i]))
            {
                result+=charStack.top();
                charStack.pop();
                
            }
            charStack.push(infix[i]);
        }
        /*else if(infix[i]=='(')
        {
            charStack.push(infix[i]);
        }*/
        else if(infix[i]==')')
        {
            while(!charStack.empty() && charStack.top()!='(')
            {
                result+=charStack.top();
                charStack.pop();
            }
            charStack.pop();//top pop ( also.
            
        }
       
    }
    while(!charStack.empty())
    {
                result+=charStack.top();
                charStack.pop();
    }
    reverse(result.begin(),result.end());
     return result;
     
}
int main()
{
    string infix="(a+b)+c*d";
    int n=infix.size();
    //for reverse.
   for(int i=0;i<n/2;i++)
    {
        swap(&infix[i],&infix[n-i-1]);
    }
    //cout<<infix<<"\n";
    for(int i=0;i<n;i++)
    {
    	if(infix[i]==')')
    	{
            infix[i]='(';
            i++;
        }
        
        if(infix[i]=='(')
        {
            infix[i]=')';
            i++;
        }
        
		
    }
    //cout<<infix<<"\n";
    string result=prefix(infix,n);
     cout<<result<<"\n";
}

