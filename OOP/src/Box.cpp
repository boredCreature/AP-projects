#include "Box.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;

void Box::add_flashcard(Flashcard* new_flashcard) {
    flashcards.push_back(new_flashcard);
}

void Box::delete_flashcard(Flashcard* flashcard) {
    auto it = find(flashcards.begin(), flashcards.end(), flashcard);
    flashcards.erase(it);
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

bool Box::does_include_flashcard(Flashcard* flashcard) {
    for (auto it = flashcards.begin(); it != flashcards.end(); ++it) {
        if (*it == flashcard)
            return true;
    }
    return false;
}

vector<Flashcard*> Box::handle_unreviewed_flashcards(vector<Flashcard*> all_reviewed_flashcards_in_day) {
    vector<Flashcard*> unreviewed_flashcards;
    for (auto flashcard : flashcards) {
        for (auto reviewed_flashcard : all_reviewed_flashcards_in_day) {
            if (flashcard != reviewed_flashcard) {
                unreviewed_flashcards.push_back(flashcard);
            }
        }
    }
    return unreviewed_flashcards;
}


string Box::to_string() {
    stringstream os;
    for (auto flashcard : flashcards) {
        os << flashcard->to_string();
    }
    return os.str();
}

