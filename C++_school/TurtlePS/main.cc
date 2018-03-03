#include "turtle.hh"

#include <iostream>
using namespace std;

class Hilbert_Curve {

	int order_;
	Turtle* turtle_;

	void draw(int order) {
		
	}

	void up() {

	}

	void down() {

	}

	void left() {

	}

	void right() {

	}

	public:

	Hilbert_Curve(int order, Turtle* turtle): order_(order), turtle_(turtle)
	{}

	void draw() {

	}
};

int main() {
	PSTurtle t(500,500);
	t.setup();

	t.pendown().forward(100)
	.left(90).forward(100)
	.left(90).forward(100)
	.left(90).forward(100)
	.left(90).forward(100);
	

	return 0;
}