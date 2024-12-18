#include "Leinter.hpp"
#include <sstream>
#include <iostream>

using namespace std;

Leinter::Leinter() : day(1) {}

void Leinter::add_flashcards(Flashcard* flashcard) {
    box[daily].add_flashcard(flashcard);
}

void Leinter::add_one_day() {
    day += 1;
}

vector<Flashcard*> Leinter::find_flashcards_for_review(int flashcards_number) {
    vector<Flashcard*> flashcards_for_review;
    int remaining_flashcards = flashcards_number;
    for (int i = remaining_flashcards; i > 0; i --) {
        for (int box_id = monthly; box_id >= daily; box_id --) {
            if (day % time_length_of_box[box_id] == 0) {
                remaining_flashcards = box[box_id].find_flashcards_for_review(remaining_flashcards, flashcards_for_review);
            }
        }
    }
    return flashcards_for_review;
}

bool Leinter::check_user_answer(string flashcard_answer, string user_answer) {
    return (flashcard_answer == user_answer);
}


string Leinter::to_string() {
    stringstream os;
    os << box[daily].to_string();
    os << box[every_three_days].to_string();
    os << box[weekly].to_string();
    os << box[monthly].to_string();
    os << "today is day: " << day << endl; 
    return os.str();
}