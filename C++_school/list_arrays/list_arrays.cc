#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

class ListError{
    public:
    ListError(){}

    void end_of_itt(){
        cout << "ERROR: End of iteration" << endl;
    }

    void index_outof_bounds(){
        cout << "ERROR: Index out of bounds" << endl;
    }

    void unknown(){
        cout << "ERROR: Unknown operation" << endl;
    }
} error;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

int take_int(string command){
    string temp;
    int number = 0;
    for (unsigned int i=0; i < command.size(); i++)
    {
        if (isdigit(command[i]))
        {
            for (unsigned int a = i; a < command.size(); a++)
            {
                temp += command[a];               
            }
          break;
        }    
    }
    istringstream stream(temp);
    stream >> number;
    return number;
}

class ListOfArrays {

    class ArrayNode {

        public:

        int* data_;
        int size_;
        ArrayNode* prev_;
        ArrayNode* next_;

        ArrayNode(int* data, int size)
            : data_(data), size_(size),  prev_(0), next_(0) {}

        ~ArrayNode() {
            delete [] data_;
        }

    };

    ArrayNode* head_;
    int size_;

    public:

    class Iterator {

        friend class ListOfArrays;

        ListOfArrays& list_;
        ArrayNode* current_;

        public:

        Iterator(ListOfArrays& list, ArrayNode* current)
            : list_(list), current_(current) {}

        bool operator==(const Iterator& other);

        bool operator!=(const Iterator& other);

        Iterator& operator++(){
            current_ = current_->next_;
            return *this;
        }

        Iterator operator++(int){
            Iterator res(list_, current_);
			current_ = current_->next_;
            return res;
        }

        int& operator[](const int& index){
            return current_->data_[index];
        }

        int size(){
            return current_->size_;
        }

        void show(){
            for(int i = 0; i < current_->size_; i++){
                if(i == current_->size_-1) cout << current_->data_[i];
                else cout << current_->data_[i] << " "; 
            }
        }
        
        double average(){
            double sum = 0;
            for(int i = 0; i < current_->size_; i++){
                sum = sum + current_->data_[i];
            }
            return sum / current_->size_;
        }
        
        double median(){
            double median;
            this->ordered();
            int array[current_->size_];
            for(int j = 0; j < current_->size_; j++){
                array[j] = current_->data_[j];
            }
            int size = this->size();
            if(this->size() % 2 == 0){
                median = (array[size / 2] + array[(size / 2 ) + 1] - 2) / 2.0;
            }else {
                median = array[(size/2)];
            }
            return median;
        }
        
        int sum(){
            int sum = 0;
            for(int i = 0; i < current_->size_; i++){
                sum = sum +current_->data_[i];
            }
            return sum;
        }
        
        Iterator& ordered(bool ascending = true){
            if(ascending == true)
            sort(this->current_->data_, this->current_->data_+this->current_->size_);
            else sort(this->current_->data_, this->current_->data_+this->current_->size_, greater<int>());
            return *this;
        }
    };

    ListOfArrays()
            : head_(new ArrayNode(0, 0)), size_(0) {
        head_->next_ = head_;
        head_->prev_ = head_;
    }

    ~ListOfArrays(){
        delete head_;
    }

    ListOfArrays(ListOfArrays& other) : head_(new ArrayNode(0, 0)), size_(0) {
        head_->next_ = head_;
        head_->prev_ = head_;     
        ArrayNode* other_ptr = other.head_->next_;
        int* array = new int[other_ptr->size_]; 
        for(int i = 0; i < other.size_; i++){
            for(int j = 0; j < other_ptr->size_; j++){
                array[j] = other_ptr->data_[j];
            }
            this->push(array, 0,other_ptr->size_);
            
            other_ptr = other_ptr->next_;
            array = new int[other_ptr->size_];
        }
    }

	ListOfArrays& operator=(const ListOfArrays& other);

    int size(){
        return size_;
    }

    void push(int array[], int position, int length){
        ArrayNode* ptr = new ArrayNode(array, length);
        ArrayNode* back = head_ -> prev_;

        back->next_ = ptr;
        ptr -> next_ = head_;

        head_ -> prev_ = ptr;
        ptr -> prev_ = back;
        size_++;
    }

    void averages(double averages[]){
        Iterator it = this->begin();
        for(int i = 0; i < size_; i++){
            averages[i] = it.average();
            it++;
        }
    }

    void medians(double medians[]){
        Iterator it = this->begin();
        for(int i = 0; i < size_; i++){
            medians[i] = it.median();
            it++;
        }
    }
  
    void sizes(int sizes[]){
        Iterator it = this->begin();
        for(int i = 0; i < size_; i++){
            sizes[i] = it.size();
            it++;
        }
    }
    
    void sums(int sums[]){
        Iterator it = this->begin();
        for(int i = 0; i < size_; i++){
            sums[i] = it.sum();
            it++;
        }
    }

    Iterator begin(){
        return Iterator(*this, head_ -> next_);
    }

    Iterator end(){
        return Iterator(*this, head_);
    }

    ListOfArrays& ordered(bool ascending = true){
        ListOfArrays::Iterator it = this->begin();
            if(ascending == true){
                for(int i = 0; i < this->size(); i++){
                    it.ordered();
                    it++;
                }
            }
            return *this;
    }

    ListOfArrays& operator*=(const int& coef);

    ListOfArrays& operator+=(const int& value);

    void show(){
        Iterator it = this->begin();
        for(int i = 0; i < size_; i++){
            it.show();
            if(i != size_-1)cout << "; ";
            else cout << endl;
            it++;
        }
    }
};

int main(){
    cout << "> ";
    ListOfArrays list;

    std::string commands;

    std::stringstream ss; 
    int int_string;
    int* array = new int[100];
    int array_size = 0;
    char garbage;

    getline(std::cin, commands);

    char back_element = commands.back();

    if(back_element == ' ')commands.pop_back();
   
    ss << commands;


    while(!ss.eof()){
        if(ss >> int_string){
             array[array_size] = int_string;
             array_size++;
        } 
        else {
             ss.clear();
             ss >> garbage;
             list.push(array, 0, array_size);
             array = new int[100];
             array_size = 0;
        }
    }
    list.push(array, 0, array_size);
    cout << "> ";
  
        
    while(getline(std::cin, commands) && commands != "quit"){
        commands.erase(std::remove(commands.begin(), commands.end(), ' '), commands.end());
        vector<string> input = split(commands, '.');
        ListOfArrays copy_list(list);
        int node_index = 0;
        while(!input.empty()){ //Find and run current command
            string command = input.front();
            input.erase(input.begin());
            if(command == "show"){
                copy_list.show();
            }

            else if(command == "size"){
                cout << copy_list.size() << endl;
            }

            else if(command == "sizes"){
                int sizes[list.size()];
                copy_list.sizes(sizes);
                for(int i = 0; i < copy_list.size(); i++){
                    cout << sizes[i] << " ";
                }
                cout << endl;
            }

            else if(command == "averages"){
                double averages[list.size()];
                copy_list.averages(averages);
                for(int i = 0; i < copy_list.size(); i++){
                    cout << averages[i] << " ";
                }
                cout << endl;
            }

            else if(command == "sums"){
                int sums[list.size()];
                copy_list.sums(sums);
                for(int i = 0; i < copy_list.size(); i++){
                    cout << sums[i] << " ";
                }
                cout << endl;
            }

            else if(command == "medians"){
                double medians[list.size()];
                copy_list.medians(medians);
                for(int i = 0; i < copy_list.size(); i++){
                    cout << medians[i] << " ";
                }
                cout << endl;
            }

            else if(command.find("mul:") != std::string::npos){
                int multiplier = take_int(command);
                ListOfArrays::Iterator it = copy_list.begin();
                for(int i = 0; i < copy_list.size(); i++){
                    for(int b = 0; b < it.size(); b++){
                        it[b] = it[b] * multiplier;
                    }
                    it++;
                }
            }

            else if(command.find("add:") != std::string::npos){
                int sum;
                sum = take_int(command);
                ListOfArrays::Iterator it = copy_list.begin();
                for(int i = 0; i < copy_list.size(); i++){
                    for(int b = 0; b < it.size(); b++){
                        it[b] = it[b] + sum;
                    }
                    it++;
                }
            }

            else if(command.find("ordered:") != std::string::npos){
                copy_list.ordered();
            }

            else if(command == "begin"){
                ListOfArrays::Iterator it = copy_list.begin();
                while(!input.empty()){
                    command = input.front();
                    if(command == "next"){
                        try{
                        if(node_index >= copy_list.size() - 1){
                            throw error;
                        }
                        else it++;
                        node_index++;
                        }catch(ListError& e){
                            e.end_of_itt();break;
                        }
                    }

                    else if(command == "show"){
                        it.show();
                        cout << endl;
                    }

                    else if(command.find("at:") != std::string::npos){
                        int index = take_int(command);
                        try{
                        if(index > it.size() || index < 0)throw error;
                        else cout << it[index] << endl;
                        }catch(ListError& e){
                            e.index_outof_bounds();
                        }
                    }

                    else if(command == "size"){
                        cout << it.size() << endl;
                    }

                    else if(command == "average"){
                        cout << it.average() << endl;
                    }

                    else if(command == "sum"){
                        cout << it.sum() << endl;
                    }

                    else if(command.find("ordered") != std::string::npos){
                        if(command.find("false"))it.ordered(false);
                        else it.ordered();
                    }

                    else if(command == "median"){
                        cout << it.median() << endl;
                    }
                    else {
                        try{
                        throw error;
                        }catch(ListError& e){
                            e.unknown();
                        }
                         break;
                        }
                    input.erase(input.begin());                    
                }
                break;
            }            
            else {
                try{
                    throw error;
                }catch(ListError& e){
                    e.unknown();
                }
                break;
            }
        }//End of current command
        cout << "> ";

    }

    return 0;
}