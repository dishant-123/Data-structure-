#include<iostream>
#include<stack>
#include<string>
//13+3*=12 only for digit not for char
using namespace std;
bool isOperand(char c)
{
	//if((c>='a' && c<='z') || (c>='A' && c<='Z') || 
	if((c>='0' && c<='9'))
	
		return true;
	return false;
}
bool isOperator(char c)
{
	if(c=='*' || c=='/' || c=='+' || c=='-')
		return true;
	return false;
}
int evalResult(int a,int b,char c)
{
	switch(c)
	{
		case '*':
			return a*b;
			break;
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '/':
			return a/b;
			break;
	}
}
int main()
{
	stack<int> s;
	int n,i,c,a,b;
	string exp,postfix="";
	cin>>exp;
	cout<<"postfix exp. is ="<<exp<<"\n";
	for(i=0;i<exp.length();i++)
	{
		if(exp[i]==' ' || exp[i]==',')
			continue;
		else if(isOperand(exp[i]))
		{
				c=(int)exp[i]-'0';
				s.push(c);
			
		}
		else if(isOperator(exp[i]))
		{
			int a=s.top();s.pop();
			int b=s.top();s.pop();
			int result=evalResult(b,a,exp[i]);
			s.push(result);
		}
	}
	cout<<"after evaluting "<<s.top();
	
}
