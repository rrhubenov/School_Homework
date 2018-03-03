//--------------------------------
// NAME: Radoslav Hubenov
// CLASS: XIa
// NUMBER: 22
// PROBLEM: 1
// FILE NAME: turtleSVG.hh
// FILE PURPOSE:
// Header file for the class SVGTurtle
//--------------------------------

#include "turtle.hh"
#include <string.h>

class SVGTurtle: public Turtle {
    std::ostream& out_;

public:
    SVGTurtle(double width, double height,
                std::ostream& out);

    virtual ~SVGTurtle();

    virtual Turtle& setup();

    virtual Turtle& moveto(const Point& p);
};
