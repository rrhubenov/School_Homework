//--------------------------------
// NAME: Radoslav Hubenov
// CLASS: XIa
// NUMBER: 22
// PROBLEM: 1
// FILE NAME: star.cc
// FILE PURPOSE:
// Draw the star shape with either SVG or PostScript
//--------------------------------

#include "turtle.hh"
#include "turtleSVG.hh"

#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    //The commands that will draw the star shape with either SVG or PostScript
    if(argc == 2 && !strcmp(argv[1], "svg")){
        SVGTurtle t(1000.0, 1000.0, std::cout);
        t.setup();

        t.pencolor(Color(0,1,0)).pensize(6).moveto(Point(700, 500)).pendown()
        .moveto(Point(800, 326.8)).moveto(Point(600, 326.8)).moveto(Point(500, 153.6))
        .moveto(Point(400, 326.8)).moveto(Point(200, 326.8)).moveto(Point(300, 500))
        .moveto(Point(200, 653.6)).moveto(Point(400,653.6)).moveto(Point(500, 826.8))
        .moveto(Point(600, 653.6)).moveto(Point(800, 653.6)).moveto(Point(700,500));
    }
    else if(argc == 2 && !strcmp(argv[1], "eps")){
        PSTurtle t(1000.0, 1000.0);
        t.setup();

        t.pencolor(Color(0,1,0)).pensize(6).moveto(Point(700, 500)).pendown()
        .moveto(Point(800, 326.8)).moveto(Point(600, 326.8)).moveto(Point(500, 153.6))
        .moveto(Point(400, 326.8)).moveto(Point(200, 326.8)).moveto(Point(300, 500))
        .moveto(Point(200, 653.6)).moveto(Point(400,653.6)).moveto(Point(500, 826.8))
        .moveto(Point(600, 653.6)).moveto(Point(800, 653.6)).moveto(Point(700,500));
    }
    else{
        cout << "Not a valid option, please choose 'svg' or 'eps'" << endl;
    }
    return 0;
}