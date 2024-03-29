#include <iostream>
#include "inf2pstf.h"
#include "d_tnodel.h"
#include "d_tnode.h"
#include "d_expsym.h"
#include "d_except.h"

using namespace std;

// build an expression tree from a postfix expression.
// the operands are single letter identifiers in the range from
// 'a' .. 'z' and the operators are selected from the characters
// '+', '-', '*' and '/'
tnode<char> *buildExpTree(const string& exp)
{
	// newnode is the address of the root of subtrees we build
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	// subtrees go into and off the stack
	stack<tnode<char> *> s;
	int i = 0;


	// loop until i reaches the end of the string
	while(i != exp.length())
	{
		// skip blanks and tabs in the expression
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		// if the expression has trailing whitespace, we could
		// be at the end of the string
		if (i == exp.length())
			break;

		// extract the current token and increment i
		token = exp[i];
		i++;

		// see if the token is an operator or an operand
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// current token is an operator. pop two subtrees off
			// the stack.
			rptr = s.top();
			s.pop();
			lptr = s.top();
			s.pop();
		
			// create a new subtree with token as root and subtees
			// lptr and rptr and push it onto the stack
			newnode = new tnode<char>(token,lptr,rptr);
			s.push(newnode);
		}
		else // must be an operand
		{
			// create a leaf node and push it onto the stack
			newnode = new tnode<char>(token);
			s.push(newnode);
		}
	}

	// if the expression was not empty, the root of the expression
	// tree is on the top of the stack
	if (!s.empty())
		return s.top();
	else
		return NULL;
}

void prefixoutput(tnode<char> *exp)
{
    cout << exp->nodeValue << "  ";
    if(exp->left != NULL)
        prefixoutput(exp->left);
    if(exp->right != NULL)
        prefixoutput(exp->right);
}


int main()
{
    string exp;
    cout << "Enter the expression ";
    cin >> exp;
    infix2Postfix newExp(exp);
    string postFix = newExp.postfix();
    tnode<char> *binaryTree = buildExpTree(postFix);
    cout << "Prefix form: ";
    prefixoutput(binaryTree);
    cout << endl;
    cout << "Postfix form: ";
    postorderOutput(binaryTree);
    cout << endl;
    cout << "Expression tree: " << endl;
    displayTree(binaryTree, exp.length());
    return 0;
}