#ifndef CALCULATOR_HH_
#define CALCULATOR_HH_

#include <vector>
#include <string>
#include <iostream>

class Operation;

class Calculator{
    std::list<Operation*> operations_;
    std::vector<double> stack_;

    public:
    void add_operation(Operation* op);
    Operation* get_operation(const std::string& name);

    void push(double val);
    int size() const;
    bool empty() const;
    double pop();

    void run(std::istream& in);

};

#endif