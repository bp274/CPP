#include <iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int main()
{
    int y ;
    float i = 0 ;
    int n = -25, x = 0 ;
    int gd = DETECT, gm, err ;
    initgraph(&gd, &gm, "C:\\TC\\BGI\\");
    err = graphresult() ;
    if(err != grOk)
    {
        cout << "Graphics Error", grapherrormsg(err) ;
        getch() ;
        exit(1) ;
    }
    for(y = 0; y < 10000; y++)
    {
        outtext("Graphics Program") ;
        setfillstyle(SOLID_FILL, YELLOW) ;
        circle(550, 320, 100) ;         //sun
        fillellipse(550, 320, 100, 100) ;       //color of sun
        ellipse(650, 320, 0, 360, 400, 200);        //Orbit of earth
        ellipse(650 + 400*cos(i), 320 + 200*sin(i),0, 180, 70, 30) ;        //half of orbit of moon
        setfillstyle(SOLID_FILL, BLUE) ;
        fillellipse(650 + 400*cos(i), 320 + 200*sin(i), 50, 50 ) ;      //color of earth
        circle(650 + 400*cos(i), 320 + 200*sin(i), 50) ;            //earth
        setfillstyle(SOLID_FILL, GREEN) ;
        ellipse(650 + 400*cos(i), 320 + 200*sin(i), 0, 360, n, 50) ;        //rotation of earth
        fillellipse(650 + 400*cos(i), 320 + 200*sin(i), n, 50) ;
        ellipse(650 + 400*cos(i), 320 + 200*sin(i), 180, 360, 70, 30) ;         //other half of orbit of moon
        setfillstyle(SOLID_FILL, WHITE) ;
        if(x<65 || x>92)
        {
            circle(650 + 400*cos(i) + 70*cos(12*i), 320 + 200*sin(i) + 30*sin(12*i), 10) ;      //moon
            fillellipse(650 + 400*cos(i) + 70*cos(12*i), 320 + 200*sin(i) + 30*sin(12*i), 10, 10) ;     //color of moon
        }
        if(x == 104){ x = 0 ; }
        if(n == 50){ n = -50 ; }
        n++ ;
        x++ ;
        cout << i*100000 << ",,, " ;
        if(i == 0.5)
        {
            cout << "i is 0.5" ;
        }
        i = i + 0.005 ;
        delay(40) ;
        cleardevice();
    }
    getch() ;
    closegraph() ;
    return 0;
}
