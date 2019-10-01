#include <iostream>
#include <stack>
using namespace std;
bool balParenthesis(string exp)
{
    int r=2;
	stack<char> stack;
	for (int i = 0; i < exp.length(); i++)
	{
	    r=0;
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
			stack.push(exp[i]);
		}
        else
        {
    		if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
    		{
    			if(stack.empty()) {
    				return r=0;
    				break;
    			}
    
                else
                {
        			char top = stack.top();
        			stack.pop();
        			if ((top == '(' && exp[i] != ')') || 
        				(top == '{' && exp[i] != '}') ||
        				(top == '[' && exp[i] != ']')) {
        			
        				r=0;
        				break;
        			}
                }
	    	}
    	}
    }
    printf("%d %d \n",r,stack.empty());
	if(stack.empty()==1)
	{
	    r=1;
	}
	if(r==0)
	        return false;
	  if(r==1)
	        return true;
	 
}
int main()
{
	string exp = "{[";

	if (balParenthesis(exp))
		cout << "The expression is balanced";
	else
		cout << "The expression is not balanced";

	return 0;
}