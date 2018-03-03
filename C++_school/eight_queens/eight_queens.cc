#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool checkDiagonal(int row, int col, vector<int> table, int tableSize){
    int diffToCheck = std::abs(row-col);
    for(int i = 0; i < tableSize; i++){
        int diff = std::abs(x-y);
        if(diff == diffToCheck){
            return false;
        }
    }
    return true;
}
void placeQs(int tableSize, vector<int> table){
    for(int colomn = 0; colomn < tableSize; colomn++){
        //Iterating trough colomns
        for(int row = 0; row < tableSize; row++){
         //Iterating trough rows
             if(find(table.begin(),table.end(), i) == table.end() && checkDiagonal(row, colomn, table, tableSize)){
                 //Row and diagonal is not taken
                 table.push_back(row);
             }
         
        }
    }
}

int main(){

    return 0;
}