//--------------------------------
// NAME: Radoslav Hubenov
// CLASS: XIa
// NUMBER: 22
// PROBLEM: 1
// FILE NAME: turtleSVG.cc
// FILE PURPOSE:
// CC file for the class SVGTurtle
// All the bodies for the methods
//--------------------------------


#include "turtle.hh"
#include "turtleSVG.hh"
#include <iostream>

using namespace std;

SVGTurtle::SVGTurtle(double width, double height, std::ostream& out):
                Turtle(width, height), out_(out){

                }

//Destructor that will be called after the lifetime of the object ends
SVGTurtle::~SVGTurtle(){
    out_ << "</svg>" << endl;
    out_ << "</body>" << endl;
    out_ << "</html>" << endl;    
}

//Setup that should be run before everything else
Turtle& SVGTurtle::setup(){
    out_ << "<html>" << endl;
    out_ << "<body>" << endl;
    out_ << "<h1>SVG Turtle Graphics</h1>" << endl;
    out_ << "<svg width=\"" << get_width() << "\" height=\"" << get_height() << "\">";
    Turtle::setup();
    return *this; 
}

//Moveto - choose where the turtle should move (if the pen is down it will draw)
Turtle& SVGTurtle::moveto(const Point& next_pos) {
    //Asserts if the setup has been run and if the next position is within the canvas
	assert(is_setup());
	assert(inside(next_pos));
    if(is_pendown()){
        out_ << "<line x1=\"" << get_pos().get_x() << "\" y1=\"" << get_pos().get_y() <<
        "\" x2=\"" << next_pos.get_x() << "\" y2=\"" << next_pos.get_y() << "\""
        << "style=\"stroke:rgb(" << get_color().red()*255 << "," << get_color().green()*255 << 
        "," << get_color().blue()*255 << ");stroke-width:" << get_pensize() << "\" />";
    }
	Turtle::moveto(next_pos);
	return *this;
}