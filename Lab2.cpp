#include<cstdlib>
#include<iostream>
#include<string>
#include<stack>

using namespace std;


int priority(char);

void main(void)
{
    stack <char> tokens;
    string input, output;
    int k=0;

    cout<<"enter expression: ";
    cin>>input;

    while (input[k] != '\0')
    {
        if (input[k] == ')')
        {
            while (true) 
            {
                if (tokens.top() == '(') break;
                output += tokens.top();
                output += ' ';
                tokens.pop();
            }
            tokens.pop();
        }
        if (input[k] >= '0' && input[k] <= '9') {
            output+=input[k];
            output += ' ';
    
        }
        if (input[k] == '(') 
        {
            tokens.push('(');
        }
        if (input[k] == '+' || input[k] == '-' || input[k] == '/' || input[k] == '*')
        {
            if (tokens.empty()) {
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
        output += tokens.top();
        output += ' ';
        tokens.pop();
    }
    output += '\0';
    cout << output;
    
}



int priority(char a)
{
    switch (a)
    {
    case '*':
    case '/':
        return 3;

    case '-':
    case '+':
        return 2;

    case '(':
        return 1;
    }
}