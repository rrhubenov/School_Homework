#include <iostream>
#include <string>

class Employee {
protected:
    std::string name_;
    long id_;
public:
    Employee() : name_("default"){}

    Employee(const std::string& name, long id) : name_(name) , id_(id){}

    const std::string& get_name() const{
        return name_;
    }
};

class Manager : public Employee {
    int level_;
public:

    Manager(const std::string& name, long id, int level) : Employee(name, id),  level_(level)
    {}

    int get_level(){
        return level_;
    }

};

int main(){
Manager m("tonkata", 1, 40);

    return 0;
}