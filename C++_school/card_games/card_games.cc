#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int ConvertS(string suit){
    if(suit == "C")return 1;
    if(suit == "D")return 2;
    if(suit == "H")return 3;
    if(suit == "S")return 4;
    else cerr << "ERROR: Not a valid suit";
    return 0;
}

int ConvertR(string rank){
    if(rank == "2")return 1;
    if(rank == "3")return 2;
    if(rank == "4")return 3;
    if(rank == "5")return 4;
    if(rank == "6")return 5;
    if(rank == "7")return 6;
    if(rank == "8")return 7;
    if(rank == "9")return 8;
    if(rank == "10")return 9;
    if(rank == "J")return 10;
    if(rank == "Q")return 11;
    if(rank == "K")return 12;
    if(rank == "A")return 13;
    else cerr << "ERROR: Not a valid rank";
    return 0;
}

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

template <class T>
void remove_duplicate(std::vector<T> & vec)
{
    set<T> values;
    vec.erase(std::remove_if(vec.begin(), vec.end(), [&](const T & value) { return !values.insert(value).second; }), vec.end());
}

class Card{
        const string suit_; //clubs , diamonds, hearts and spades
        const string rank_; //2 - 10, Jack, Queen, King, Ace
    public:
        Card(string suit, string rank) : suit_(suit), rank_(rank){}
        const string get_card() const{
            return suit_ + rank_;
        }
        const string get_rank() const{
            return rank_;
        }
        const string get_suit() const{
            return suit_;
        }
        bool operator>(Card card){
            if(rank_ == card.get_rank())return ConvertS(suit_) > ConvertS(card.get_suit());
            else return ConvertR(rank_) > ConvertR(card.get_rank());
        }
};



bool Sorting(Card* a, Card* b){
    return *a > *b;
}


//Base class
class Deck {
        const int hand_size_;
        int deck_size_;
        const int lowest_card_;
    protected:
        vector<Card*> deck_;
    public:
        Deck(vector<Card*> deck, int hand_size, int deck_size, int lowest_card) : hand_size_(hand_size),
         deck_size_(deck_size), lowest_card_(lowest_card), deck_(filter(deck)){}
    
        void print_deck() const{
            for(auto it = deck_.begin(); it != deck_.end(); it++){
                cout << (*it)->get_card() << " ";
            }
            cout << endl;
        }

        int size() const {
            return deck_size_;
        }

        string draw_top_card()  {
            if(deck_size_ < 1){
                return "ERROR: Not enough cards in deck";
            }
            string front = deck_.front()->get_card();
            deck_.erase(deck_.begin());
            deck_size_--;
            return front;
        }

        string draw_bottom_card()  {
            if(deck_size_ < 1){
                return "ERROR: Not enough cards in deck";
            }
            string back = deck_.back()->get_card();
            deck_.pop_back();
            deck_size_--;
            return back;
        }

        string top_card() const {
            if(deck_size_ < 1){
                return "ERROR: Not enough cards in deck";
            }
            else return deck_.front()->get_card();
        }

        string bottom_card()const {
            if(deck_size_ < 1){
                return "ERROR: Not enough cards in deck";
            }
            else return deck_.back()->get_card();
        }

        void shuffle(vector <string> deck);

        virtual void sort() = 0;

        int deal(){
            if(deck_size_ < hand_size_){
                cout << "ERROR: Not enough cards in deck" << endl;
                return -1;
            }
            else for(int i = 0; i < hand_size_; i++){
                cout << deck_.front()->get_card() << " ";
                deck_.erase(deck_.begin());
            }
            deck_size_ -= hand_size_;
            cout << endl;
            return 1;
        }

        vector<Card*> filter(vector <Card*> deck){
            for(auto it = deck.begin(); it != deck.end(); it++){
                if(ConvertR((*it)->get_rank()) < lowest_card_){
                    deck.erase(it);
                    it--;
                }   
                
            }
            return deck;
        }

};
//Derived classes
class War : public Deck {
    public:
        War(vector<Card*> deck) : Deck(deck, 26, 52, 1){}
        virtual void sort(){
            cout << "Hello?";
            std::sort(deck_.begin(), deck_.end(), Sorting);
        }
};

class Belote : public Deck {
    public:
        Belote(vector<Card*> deck) : Deck(deck, 8, 32, 6){}
        virtual void sort(){
            
        }
};

class Santase : public Deck {
    public:
        Santase(vector<Card*> deck) : Deck(deck, 6, 24, 8){}
        virtual void sort(){
            
        }
};

int main(){
    string input;
    bool object_constructed = false;
    
    cout <<  "> ";
    getline(std::cin, input);
    vector<string> cards = split(input, ' ');
    remove_duplicate(cards);
    vector<Card*> card_objects;

    for(auto it = cards.begin(); it != cards.end(); it++){ //Filling the vector of cards with cards
        string suit(1, it[0][0]);
        it[0].erase(it[0].begin());
        string rank = *it;
        card_objects.push_back(new Card(suit, rank));
    }

    Deck* deck;
    /*
    for(auto it = cards.begin(); it != cards.end(); it++){
        cout << *it << " ";
    }
    */
    cout << "> ";
    while(getline(std::cin, input) && input != "quit"){
        if(input == "War"){
            if(cards.size() < 52)cout << "ERROR: Not enough cards for War" << endl;
            else deck = new War(card_objects);
            object_constructed = true;
        }
        else if(input == "Belote"){
            if(cards.size() < 32)cout << "ERROR: Not enough cards for Belote" << endl;
            else deck = new Belote(card_objects);
            object_constructed = true;            
        }
        else if(input == "Santase"){
            if(cards.size() < 24)cout << "ERROR: Not enough cards for Santase" << endl;
            else deck = new Santase(card_objects);
            object_constructed = true;            
        }
        else if(!object_constructed){
            cout << "ERROR: No deck" << endl << "> ";
            continue;
        }
        else if(input == "deal"){
            deck->deal();
        }
        else if(input == "draw_top_card"){
            cout << deck->draw_top_card() << endl;
        }
        else if(input == "draw_bottom_card"){
            cout << deck->draw_bottom_card() << endl;
        }
        else if(input == "top_card"){
            cout << deck->top_card() << endl;
        }
        else if(input == "bottom_card"){
            cout << deck->bottom_card() << endl;
        }
        else if(input == "size"){
            cout << deck->size() << endl;
        }
        else if(input == "sort"){
            //deck->sort();
            deck->print_deck();
            
        }
        else cout << "ERROR: Unknown operation" << endl;
        cout << "> ";
    }


    return 0;
}