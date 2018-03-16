#define NIL -1
#define MAX 1000
#include <iostream>

using namespace std;

unsigned long long int fibonacci(unsigned long long int) ;

unsigned long long int n ;
unsigned long long int lookup[MAX] ;

int main()
{
    cout << "Enter the place at which the fibonacci number is to be found :- " ;
    cin >> n ;
    for(unsigned long long int i = 0 ; i < n ; i++)
    {
        lookup[i] = NIL ;
    }
    cout << "\nThe fibonacci number at place " << n << " is " <<  fibonacci(n - 1) << endl ;
    return 0;
}

unsigned long long int fibonacci(unsigned long long int n)
{
    if(lookup[n] == NIL)
    {
        if(n <= 1)
        {
            lookup[n] = n ;
        }
        else
        {
            lookup[n] = fibonacci(n - 1) + fibonacci(n - 2) ;
        }
    }
    return lookup[n] ;
}
