#include "Box.hpp"
#include <sstream>
#include <iostream>


using namespace std;

void Box::add_flashcard(Flashcard* new_flashcard) {
    flashcards.push_back(new_flashcard);
} 

string Box::to_string() {
    stringstream os;
    for (auto flashcard : flashcards) {
        os << flashcard->to_string();
    }
    return os.str();
}

