#include "operation.hh"
#include "calculator.hh"
#include <string>
#include <vector>

using namespace std;

Calculator::Calculator() {

}

void Calculator::add_operation(Operation* op){
    Operation* check = get_operation(op->get_name());
    if(check != 0) {
        cout << "operation " << op->get_name() << "already added..."
        << endl;
    } else {
        operations_.push_back(op);
    }
}

Operation* Calculator::get_operation(const string& name) {
    for(vector<Operation*>::iterator it = operations_.begin();
    it != operations_.end(); ++it)
}