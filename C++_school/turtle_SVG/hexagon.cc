//--------------------------------
// NAME: Radoslav Hubenov
// CLASS: XIa
// NUMBER: 22
// PROBLEM: 1
// FILE NAME: hexagon.cc
// FILE PURPOSE:
// Draw the hexagon shape with either SVG or PostScript
//--------------------------------

#include "turtle.hh"
#include "turtleSVG.hh"

#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    //The commands that will draw the hexagon with either SVG or PostScript
    if(argc == 2 && !strcmp(argv[1], "svg")){
        SVGTurtle t(1000.0, 1000.0, std::cout);
        t.setup();

        t.pencolor(Color(1,0,0)).pensize(6).moveto(Point(900, 500)).pendown()
        .moveto(Point(700,153.59)).moveto(Point(300, 153.59))
        .moveto(Point(100, 500)).moveto(Point(300,846.41))
        .moveto(Point(700, 846.41)).moveto(Point(900, 500));
    }
    else if(argc == 2 && !strcmp(argv[1], "eps")){
        PSTurtle t(1000.0, 1000.0);
        t.setup();

        t.pencolor(Color(1,0,0)).pensize(6).moveto(Point(900, 500)).pendown()
        .moveto(Point(700,153.59)).moveto(Point(300, 153.59))
        .moveto(Point(100, 500)).moveto(Point(300,846.41))
        .moveto(Point(700, 846.41)).moveto(Point(900, 500));
    }
    else{
        cout << "Not a valid option, please choose 'svg' or 'eps'" << endl;
    }
    return 0;
}