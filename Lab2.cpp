#include<cstdlib>
#include<iostream>
#include<string>
#include<stack>

using namespace std;


int priority(char);

int main()
{
    stack <char> tokens;
    string input, output;
    int k=0;

    cout<<"enter expression: ";
    getline(cin, input);

    while (input[k] != '\0')
    {
        if (input[k] == ')')
        {
            while (true) 
            {
                if (tokens.top() == '(') break;
                output += ' ';
                output += tokens.top();
                tokens.pop();
            }
            tokens.pop();
        }
        if (isdigit(input[k])) 
        {
            output+=input[k];
        }
        if (input[k] == '(') 
        {
            tokens.push('(');
        }
        if (input[k] == '+' || input[k] == '-' || input[k] == '/' || input[k] == '*')
        {
        	output+=' ';

        	if (input[k]=='-' && (k==0 || !isdigit(input[k-1])))
        		input[k]='~'; // унарный минус записывается как ~

            if (tokens.empty()) 
            {
                tokens.push(input[k]);
            }
            else 
            {
                if (priority(tokens.top()) < priority(input[k])) 
                {
                    tokens.push(input[k]);
                }
                else
                {
                    while (!tokens.empty() && priority(tokens.top()) >= priority(input[k])) 
                    {
                    	
                        output += tokens.top();
                        output += ' ';
                        tokens.pop();
                    }
                    tokens.push(input[k]);
                }

            }
        }
        k++;
    }

    while (!tokens.empty()) {
    	output+=' ';
        output += tokens.top();
        
        tokens.pop();
    }
    output += '\0';
    cout << output;
    return 0;
}



int priority(char a)
{
    switch (a)
    {
    case '~':
    	return 4;
    case '*':
    case '/':
        return 3;

    case '-':
    case '+':
        return 2;

    case '(':
        return 1;
    }
    return 0;
}