//inculding iostream only for testing and to_string() funciton

#include <iostream>
#include <sstream>
#include "Flashcard.hpp"
using namespace std;

string Flashcard::get_quesetion() {return question; }
string Flashcard::get_answer() {return answer; }

int Flashcard::get_num_of_wrong_answers() {return num_of_wrong_answer; }

void Flashcard::add_one_to_wrong_answers() {
    num_of_wrong_answer += 1;
}

void Flashcard::reset_wrong_answers() {
    num_of_wrong_answer = 0;
}

string Flashcard::to_string() {
    stringstream os;
    os << question << "\t" << answer << endl;
    return os.str();    
}