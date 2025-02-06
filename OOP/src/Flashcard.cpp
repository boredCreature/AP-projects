//inculding iostream only for testing and to_string() funciton

#include <iostream>
#include <sstream>
#include "Flashcard.hpp"
using namespace std;

string Flashcard::get_quesetion() {return question; }
string Flashcard::get_answer() {return answer; }

string Flashcard::to_string() {
    stringstream os;
    os << question << "\t" << answer << endl;
    return os.str();    
}