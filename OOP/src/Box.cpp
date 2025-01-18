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
    
    for (auto it = flashcards.begin() ; it != flashcards.end() && remaining_flashcards > 0; it++) {
        flashcards_for_review.push_back(*it);
        remaining_flashcards -= 1;
    }
    return remaining_flashcards;
}

bool Box::includes_flashcard(Flashcard* flashcard) {
    for (auto current_flashcard : flashcards) {
        if (current_flashcard == flashcard) 
            return true;
    }
    return false;
}

void Box::remove_flashcard(Flashcard* flashcard) {
    auto it = find(flashcards.begin(), flashcards.end(), flashcard);
    flashcards.erase(it);
}

int Box::get_num_of_flashcards() {return flashcards.size(); }

string Box::to_string() {
    stringstream os;
    for (auto flashcard : flashcards) {
        os << flashcard->to_string();
    }
    return os.str();
}

