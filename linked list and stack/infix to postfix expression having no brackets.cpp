#include<iostream>
#include<stack>
//A+B*C=AB*+ //assume no brackets in expression
using namespace std;
bool isOperand(char c)
{
	if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
		return true;
	return false;
}
bool isOperator(char c)
{
	if(c=='*' || c=='/' || c=='+' || c=='-')
		return true;
	return false;
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
			weight=1;
			break;
		case '*':
			weight=3;
			break;
		case '/':
			weight=3;
			break;
		case '^':
			weight=4;
			break;
			
	}
	return weight;
}
bool highPrecedence(char op1,char op2)
{
	int weight1=calcWeight(op1);
	int weight2=calcWeight(op2);
	return weight1>=weight2?true:false;
}
int main()
{
	stack<char> s;
	int n,i;
	string exp,postfix="";
	cin>>exp;
	cout<<"Infix exp. is ="<<exp<<"\n";
	for(i=0;i<exp.length();i++)
	{
		if(exp[i]==' ' || exp[i]==',')
			continue;
		else if(isOperand(exp[i]))
		{
			postfix+=exp[i];
		}
		else if(isOperator(exp[i]))
		{
			while(!s.empty() && highPrecedence(s.top(),exp[i]))
			{
				postfix+=s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
	}
	while(s.empty()!=1)
	{
		postfix+=s.top();
		s.pop();
	}
	cout<<"postfix exp. is ="<<postfix<<"\n";
	
}
