#include "Box.hpp"
#include <sstream>
#include <iostream>


using namespace std;

void Box::add_flashcard(Flashcard* new_flashcard) {
    flashcards.push_back(new_flashcard);
} 

bool Box::check_empty() {
    return (flashcards.size() == 0);
}

int Box::find_flashcards_for_review(int remaining_flashcards, vector<Flashcard* >& flashcards_for_review) {
    
    if (remaining_flashcards > 0) {
        for (auto flashcard : flashcards) {
            flashcards_for_review.push_back(flashcard);
            remaining_flashcards =- 1;
        }
    }
    return remaining_flashcards;
}

string Box::to_string() {
    stringstream os;
    for (auto flashcard : flashcards) {
        os << flashcard->to_string();
    }
    return os.str();
}

