#define PI 3.14159
#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>

using namespace std;

int v = 1 ;

class shapes
{
    public :
        virtual void store() = 0 ;
        virtual void display() = 0 ;
        virtual double area() = 0 ;
        virtual double perimeter() = 0 ;
};

class point : public shapes
{
    private :
        int x, y ;
    public :
        void store()
        {
            cout << "\nEnter the co-ordinates of the point(x & y) respectively :- " ;
            cin >> x >> y ;
        }
        void display()
        {
            putpixel(x, y, WHITE) ;
        }
        double area(){ return 0 ; }
        double perimeter(){ return 0 ; }
};

class stline : public shapes
{
    private :
        int x1, y1, x2, y2 ;
    public :
        void store()
        {
            cout << "\nEnter the coordinates of the starting and end point of the line [x1,y1] & [x2,y2] :-  " ;
            cin >> x1 >> y1 >> x2 >> y2 ;
        }
        void display()
        {
            line(x1, y1, x2, y2) ;
        }
        double area(){  return 0 ; }
        double perimeter(){ return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)) ; }
};

class trig : public shapes
{
    protected :
        int x1, y1, x2, y2, x3, y3 ;
    public :
        void store()
        {
            cout << "\nEnter the coordinates of the three vertexes of the triangle [x1 , y1] ,[x2 , y2] & [x3 , y3] :- " ;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
        }
        void display()
        {
            line(x1, y1, x2, y2) ;
            line(x2, y2, x3, y3) ;
            line(x3, y3, x1, y1) ;
        }
        double area(){ return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2 ; }
        double perimeter() { return (sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)) + sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3)) + sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1))) ; }
};

class quadr : public shapes
{
    protected :
        int x1, y1, x2, y2, x3, y3, x4, y4 ;
    public :
        void store()
        {
            cout << "\nEnter the coordinates of the vertexes of the quadrilateral in cyclic order [x1 , y1] , [x2 , y2] , [x3 , y3] & [x4 , y4] :- " ;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 ;
        }
        void display()
        {
            line(x1, y1, x2, y2) ;
            line(x2, y2, x3, y3) ;
            line(x3, y3, x4, y4) ;
            line(x4, y4, x1, y1) ;
        }
        double area(){ return (abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2) + (abs(x1*(y4 - y3) + x4*(y3 - y1) + x3*(y1 - y4)) / 2) ; }
        double perimeter() { return (sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)) + sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3)) + sqrt((x3 - x4)*(x3 - x4) + (y3 - y4)*(y3 - y4)) + sqrt((x4 - x1)*(x4 - x1) + (y4 - y1)*(y4 - y1))) ; }
};

class pgram : public quadr
{
    public :
        void store()
        {
            cout << "\nEnter the coordinates of three vertexes of a rhombus in cyclic order [x1 , y1] , [x2 , y2] & [x3 , y3] :- " ;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
            x4 = x1 + x3 - x2 ;
            y4 = y1 + y3 - y2 ;
        }
        void display()
        {
            line(x1, y1, x2, y2) ;
            line(x2, y2, x3, y3) ;
            line(x3, y3, x4, y4) ;
            line(x4, y4, x1, y1) ;
        }
        double area(){ return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) ; }
        double perimeter(){ return 2*(sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) ) + sqrt( (x4 - x1)*(x4 - x1) + (y4 - y1)*(y4 - y1) )) ; }
};

class rbus : public pgram
{
    public :
        void store()
        {
            cout << "\nEnter the coordinates of three vertexes of a rhombus in cyclic order [x1 , y1] , [x2 , y2] & [x3 , y3] :- " ;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
            if((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) != (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3))
            {
                v = 0 ;
                cout << "The entered coordinates are not of a rhombus" ;
            }
            x4 = x1 + x3 - x2 ;
            y4 = y1 + y3 - y2 ;
        }
        double perimeter(){return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)) + sqrt((x4 - x1)*(x4 - x1) + (y4 - y1)*(y4 - y1)) ; }
};

class rect : public pgram
{
    public :
        void store()
        {
            cout << "\nEnter the coordinates of diagonally opposite points [x1 , y1] & [x2 , y2] :- " ;
            cin >> x1 >> y1 >> x2 >> y2 ;
        }
        void display()
        {
            rectangle(x1, y1, x2, y2) ;
        }
        double area(){ return (x2 - x1) * (y2 - y1) ; }
        double perimeter(){ return 2*(abs(x2 - x1) + abs(y2 - y1)) ; }
};

class sqr : public rect
{
    public :
        void store()
        {
            cout << "\nEnter the coordinates of diagonally opposite points [x1 , y1] & [x2 , y2] :- " ;
            cin >> x1 >> y1 >> x2 >> y2 ;
            if( (x2 - x1)*(x2 - x1) != (y2 - y1)*(y2 - y1))
            {
                cout << "The entered coordinates are not for a square" ;
                v = 0 ;
            }
        }
        double area(){ return (x2 - x1) * (x2 - x1) ; }
        double perimeter(){ return (x2 - x1) * (x2 - x1) ; }
};

class ellip : public shapes
{
    protected :
        int x, y, a, b, p, q ;
    public :
        void store()
        {
            cout << "\nEnter the coordinates of the center of the ellipse [x , y] :- " ;
            cin >> x >> y ;
            cout << "Enter the x-radius(a) & y-radius(b) of the ellipse :- " ;
            cin >> a >> b ;
            p = 0 ;
            q = 360 ;
        }
        void display()
        {
            ellipse(x, y, p, q, a, b) ;
            putpixel(x, y, WHITE) ;
        }
        double area(){ return PI*a*b ; }
        double perimeter(){ return PI*(3*(a + b) - sqrt((3*a + b)*(a + 3*b))) ; }   //approximate value(no exact formula known)
};

class elarc : public ellip
{
    public :
        void store()
        {
            cout << "\nEnter the coordinates of the center of the ellipse [x , y] :- " ;
            cin >> x >> y ;
            cout << "Enter the x-radius(a) & y-radius(b) of the ellipse :- " ;
            cin >> a >> b ;
            cout << "Enter the starting angle and the ending angle for the arc :- " ;
            cin >> p >> q ;
        }
        double area(){ return 0 ; }
        double perimeter(){ return ((abs(q - p))*(PI*(3*(a + b) - sqrt((3*a + b)*(a + 3*b))))) / 360 ; }
};

class cir : public ellip
{
    public :
        void store()
        {
            cout << "\nEnter the coordinates of the center of the circle [x , y] :- " ;
            cin >> x >> y ;
            cout << "Enter the radius of the circle :- " ;
            cin >> a ;
            b = a ;
            p = 0 ;
            q = 360 ;
        }
        double perimeter() { return 2 * PI * a ; }      //accurate formula for circumference
};

class crarc : public cir
{
    public :
        void store()
        {
            cout << "\nEnter the coordinates of the center of the circle [x , y] :- " ;
            cin >> x >> y ;
            cout << "Enter the radius of the circle :- " ;
            cin >> a ;
            b = a ;
            cout << "Enter the starting angle and the ending angle :- " ;
            cin >> p >> q ;
        }
        double area(){ return 0 ; }
        double perimeter(){ return (2 * PI * a *(abs(p - q))/360) ; }
};

int main()
{
    int gd = DETECT, gm, err ;
    initgraph(&gd, &gm, "C:\\TC\\BGI\\");
    err = graphresult() ;
    if(err != grOk)
    {
        cout << "Graphics Error", grapherrormsg(err) ;
        getch() ;
        exit(1) ;
    }
    outtext("Graphics Program") ;
    shapes *ptr ;
    int k ;
    cout << "Press 1 to display a point\nPress 2 to display a line\nPress 3 to display a circle\n" ;
    cout << "Press 4 to display a rectangle\nPress 5 to display a square\nPress 6 to display an ellipse\n" ;
    cout << "Press 7 to display a parallelogram\nPress 8 to display a rhombus\nPress 9 to display triangle\n" ;
    cout << "Press 10 to display a general quadrilateral\nPress 11 to display an elliptical arc\n" ;
    cout << "Press 12 to display a circular arc\n" ;
    cout << endl ;
    cin >> k ;
    if(k == 1)
    {
        point obj ;
        ptr = &obj ;
    }
    else if(k == 2)
    {
        stline obj ;
        ptr = &obj ;
    }
    else if(k == 3)
    {
        cir obj ;
        ptr = &obj ;
    }
    else if(k == 4)
    {
        rect obj ;
        ptr = &obj ;
    }
    else if(k == 5)
    {
        sqr obj ;
        ptr = &obj ;
    }
    else if(k == 6)
    {
        ellip obj ;
        ptr = &obj ;
    }
    else if(k == 7)
    {
        pgram obj ;
        ptr = &obj ;
    }
    else if(k == 8)
    {
        rbus obj ;
        ptr = &obj ;
    }
    else if(k == 9)
    {
        trig obj ;
        ptr = &obj ;
    }
    else if(k == 10)
    {
        quadr obj ;
        ptr = &obj ;
    }
    else if(k == 11)
    {
        elarc obj ;
        ptr = &obj ;
    }
    else if(k == 12)
    {
        crarc obj ;
        ptr = &obj ;
    }
    ptr->store() ;
    if(v == 1)
    {
        cout << "Perimeter is :- " << ptr->perimeter() << endl ;
        cout << "Area is :- " << ptr->area() << endl ;
        ptr->display() ;
    }
    getch() ;
    closegraph() ;
    return 0 ;
}
