//inculding iostream only for testing and to_string() funciton

#include <iostream>
#include <sstream>
#include "Flashcard.hpp"
using namespace std;

bool Flashcard::is_answer_correct(string user_answer) {
    if (user_answer != answer) {
        add_one_to_wrong_answers();
        return false;
    }
    return true;
}

void Flashcard::add_one_to_wrong_answers() {
    num_of_wrong_answers += 1;
}

void Flashcard::reset_num_of_wrong_answers() {
    num_of_wrong_answers = 0;
}

bool Flashcard::should_move_to_next_box_because_of_wrong_answer() {
    return (num_of_wrong_answers > 1);
}

string Flashcard::get_quesetion() {return question; }
string Flashcard::get_answer() {return answer; }

string Flashcard::to_string() {
    stringstream os;
    os << question << "\t" << answer << endl;
    return os.str();    
}