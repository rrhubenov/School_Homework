#include <iostream>
#include <list>


class Shape{

public:
    virtual void draw() const = 0;

};

class Point {
    double x_, y_;
    public:
    Point(double x = 0.0, double y = 0.0)
    : x_(x), y_(y){}

    double get_x() const {return x_;}
    double get_y() const {return y_;}
};

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "Point(" << p.get_x() << "," << p.get_y() << ")";
    return out;
}

class Circle : public Shape {
    Point center_;
    double radius_;


public:
    Circle(const Point& p, double radius) : center_(p), radius_(radius){}

    void draw() const {
        std::cout << "Circle(" << center_ << "," << radius_ << ")"
        << std::endl;
    }
};

class Rectangle : public Shape{
    Point ul_, br_;
    static double min_(double a, double b){
        return (a<b)?a:b;
    }
    static double max_(double a, double b){
        return (a>b)?a:b;
    }
    public:
    Rectangle(Point ul, Point br) : ul_(ul), br_(br) {} //TODO: Use min_ and max_ for points
};



int main(){

    std::list<Shape*> shapes;
    //....
    Circle c1(Point(0,0), 3);
    shapes.push_back(&c1);
    Circle c2(Point(1,1), 2);
    shapes.push_back(&c2);

    for(std::list<Shape*>::iterator it = shapes.begin(); it!=shapes.end(); ++it){
        (*it) -> draw();
    }

    return 0;
}