#include <iostream>

using namespace std ;

class Stack
{
    private :
        char* stack ;
        int top ;
    public :
        Stack(int) ;
        void push(char) ;
        char pop() ;
        char peek() ;
        bool isEmpty() ;
        bool isValid(string) ;
        bool isOperand(char) ;
        bool isOperator(char) ;
        int precedence(char) ;
        void infixToPostfix(string) ;
};

Stack :: Stack(int size)
{
    stack = new char[size] ;
    top = -1 ;
}

void Stack :: push(char ch)
{
    stack[++top] = ch ;
}

char Stack :: pop()
{
    if(!isEmpty())
    {
        return stack[top--] ;
    }
    else
    {
        cout << "Underflow\nInvalid expression" << endl ;
    }
}

char Stack :: peek()
{
    if(!isEmpty())
    {
        return stack[top] ;
    }
    else
    {
        cout << "Stack is empty" << endl ;
    }
}

bool Stack :: isEmpty()
{
    if(top == -1)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

bool Stack :: isOperand(char ch)
{
    int x = (int)ch ;
    return x > 64 && x < 91 || x > 96 && x < 123 || x > 47 && x < 58 ;

}

bool Stack :: isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ;
}

int Stack :: precedence(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1 ;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2 ;
    }
    else if(ch == '^')
    {
        return 3 ;
    }
    else
    {
        return -1 ;
    }
}

void Stack :: infixToPostfix(string infix)
{
    int k = -1 ;
    char* postfix = new char[infix.length()] ;
    for(int i = 0 ; i < infix.length() ; i++)
    {
        char ch = infix[i] ;
        if(isOperand(ch))
        {
            postfix[++k] = ch ;
        }
        else if(ch == '(')
        {
            push(ch) ;
        }
        else if(ch == ')')
        {
            while(!isEmpty() && peek() != '(')
            {
                postfix[++k] = pop() ;
            }
            if(!isEmpty())
            {
                pop() ;
            }
            else
            {
                cout << "\nInvalid String" << endl ;
                return ;
            }
        }
        else
        {
            while(!isEmpty() && precedence(ch) <= precedence(peek()))
            {
                postfix[++k] = pop() ;
            }
            push(ch) ;
        }
    }
    while(!isEmpty())
    {
        if(peek() != '(')
        {
            postfix[++k] = pop() ;
        }
        else
        {
            cout << "Invalid Expression\nBrackets not balanced" << endl ;
            return ;
        }
    }
    postfix[++k] = '\0' ;
    cout << "\nThe postfix expression is " << postfix << "\n" << endl ;
}

bool Stack :: isValid(string infix)
{
    int brackets = 0 ;
    bool prevOperator = false, prevOperand = false ;
    if(!isOperand(infix[0]) || !isOperand(infix[infix.length() - 1]))
    {
        return false ;
    }
    for(int i = 0 ; i < infix.length() ; i++)
    {
        char ch = infix[i] ;
        if(ch == '(')
        {
            brackets++ ;
        }
        else if(ch == ')')
        {
            brackets-- ;
        }
        else if(isOperand(ch))
        {
            prevOperator = false ;
            if(prevOperand)
            {
                return false ;
            }
            else
            {
                prevOperand = true ;
            }
        }
        else if(isOperator(ch))
        {
            prevOperand = false ;
            if(prevOperator)
            {
                return false ;
            }
            else
            {
                prevOperator = true ;
            }
        }
    }
    if(brackets == 0)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

int main()
{
    while(true)
    {
        char ch ;
        string str ;
        cout << "\nEnter the infix expression :- " ;
        cin >> str ;
        Stack object(str.length()) ;
        if(object.isValid(str))
        {
            object.infixToPostfix(str) ;
        }
        else
        {
            cout << "\nInvalid infix expression\n" << endl ;
            continue ;
        }
        cout << "Do you want to convert another string (Press 'Y'/'y' else press any other key to exit) :- " ;
        cin >> ch ;
        if(ch != 'Y' && ch != 'y')
        {
            break ;
        }
    }
    return 0 ;
}
