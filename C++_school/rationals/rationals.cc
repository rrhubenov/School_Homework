#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <numeric>
#include <cstdlib>

using namespace std;

int gcd(int a, int b){
          return b == 0 ? a : gcd(b, a % b);
     }

class Rational{
    int numerator_;
    int denominator_;
public:
    Rational(): numerator_(0), denominator_(0){}

    void set_num(int num){
        numerator_ = num;
    }

     void set_den(int den){
         denominator_ = den;
     }
     int get_num(){
         return numerator_;
     }

     int get_den(){
         return denominator_;
     }

     void rationalize(){
       int gcd_num = gcd(numerator_, denominator_);
       numerator_ = numerator_/gcd_num;
       denominator_ = denominator_/gcd_num;
     }


    Rational operator+(Rational a)  {
        a.set_num((a.get_num()*this->get_den()) + (a.get_den()*this->get_num()));
        a.set_den(a.get_den()*this->get_den());
        return a;
    }
    
    Rational operator-(Rational a)  {
        a.set_num(a.get_den()*this->get_num() - a.get_num()*this->get_den());
        a.set_den(a.get_den()*this->get_den());
        return a;
    }

    Rational operator*(Rational a)  {
        a.set_num(this->get_num()*a.get_num());
        a.set_den(a.get_den()*this->get_den());
        return a;
    }

    Rational operator/(Rational a)  {
        this->rationalize();
        int old_num = a.get_num();
        a.set_num(a.get_den());
        a.set_den(old_num);
        a = a*(*this);
        return a;
    }
};


ostream& operator<<(ostream& out, Rational& a){
    out << a.get_num() << "/" << a.get_den();
    return out;
}

istream& operator>>(istream& in, Rational& a){
    char ch=0;
	int num=0, den=0;
		
	in >> ch; 

    if(ch == 'q'){
        exit(0);   
    }

	if(ch!='(') {
		in.clear(ios_base::badbit);
		return in;
	}
	in >> num;
	in >> ch; 
	if(ch!='/') {
		in.clear(ios_base::badbit);
		return in;
	}
	in >> den;
	in >> ch; 
	if(ch!=')') {
		in.clear(ios_base::badbit);
		return in;
	}
	
	if(in.good()) {
		a.set_num(num);
        a.set_den(den);
	}
	return in;
}



int main(){
    cout << "> ";
    Rational input, result;
    char sign;
    bool more_inputs = false;

    while(cin.good()){
        cin >> input;
        input.rationalize();
        cin >> sign;
        cin >> result;
        result.rationalize();
        while(true){
            if(more_inputs){
                cin >> input;
            }
            switch (sign){
                case '+':
                result = input + result;
                break;

                case '-':
                if(more_inputs){
                    result = result - input;
                    break;
                }
                result = input - result;
                break;

                case '*':
                result = input*result;
                break;

                case '/':
                if(more_inputs){
                    result = result/input;
                    break;
                }
                result = input/result;
                break;
            }
        
            cin >> sign;
            if(sign == '='){
                result.rationalize();

                cout << "(" << result << ")" << endl;
                break;
            }
            else more_inputs = true;
        }
        cout << "> ";
    }
    return 0;
}