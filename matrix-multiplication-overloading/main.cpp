#include <iostream>

using namespace std;

class matrix
{

    private:

        int M[20][20],n,m,i,j,k;

    public:

        void store();
        void display();
        void transpose();
        void multiply();
        matrix operator*(matrix b);

};

void matrix :: store()
{
    cout << "\n\nEnter the number of rows and columns of the matrix :-\n\n" ;
    cin >> n >> m ;
    cout << endl << endl ;
    cout << "\n\nEnter the elements of the matrix :-\n\n" ;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cout << "[" << i+1 << "," << j+1 << "] = " ;
            cin >> M[i][j];
        }
    }
}

void matrix :: display()
{
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cout << M[i][j] << "\t" ;
        }
        cout << endl << endl ;
    }
}

void matrix :: transpose()
{
    matrix trans;
    trans.store();
    cout << "The matrix is :-\n\n" ;
    trans.display();
    cout << "\n\nThe transpose matrix is :- \n\n" ;
    for(i=0; i<trans.m; i++)
    {
        for(j=0; j<trans.n; j++)
        {
            cout << trans.M[j][i] << "\t" ;
        }
        cout << endl << endl ;
    }
}

void matrix :: multiply()
{
    matrix a,b,c;
    cout << "\n\nFor first matrix :-\n\n" ;
    a.store();
    cout << "\n\nFor second matrix :-\n\n" ;
    b.store();
    cout << "\n\nThe matrix A is :-\n\n" ;
    a.display();
    cout << "\n\nThe matrix B is :-\n\n" ;
    b.display();
    if(a.m != b.n)
    {
        cout << "\n\nThe multiplication of matrices AXB is not possible\n\n" ;
        return;
    }
    cout << "\n\nThe product matrix is :-\n\n" ;
    c = a * b ;
    c.display();
}

matrix matrix :: operator*(matrix b){
    matrix temp;
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<b.m ; j++)
        {
            temp.M[i][j]=0;
            for(k=0 ; k<b.n ; k++)
            {
                temp.M[i][j]+=M[i][k]*b.M[k][j];
            }
        }
    }
    temp.n = n ;
    temp.m = b.m ;
    return temp;
}

int main()
{
    int Y=1,Z;
    matrix X,A,B;
    cout << "-----Program to find the transpose of a matrix and to find the product of two matrices by operator overloading ------" ;
    while(Y==1)
    {
        cout << "\n\nPress 1 to find the transpose of a matrix\nPress 2 to find the product of two matrices\n\n" ;
        cin >> Z ;
        if(Z==1)
        {
            X.transpose();
        }
        else if(Z==2)
        {
            X.multiply();
        }
        else
        {
            cout << "\n\nInvalid Command\n\n" ;
        }
        cout << "Press 1 to enter command again\nPress any other key to exit the program\n\n" ;
        cin >> Y ;
    }
    return 0;
}
