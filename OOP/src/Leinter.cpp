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


// vector<Flashcard*> Leinter::find_flashcards_for_review(int flashcards_number) {
//     vector<Flashcard*> flashcards_for_review;
//     int remaining_flashcards = flashcards_number;
//     for (int i = flashcards_number; i > 0; i --) {
//         if (day % Month_length == 0 && !boxes.monthly_box.check_empty())
//             remaining_flashcards = boxes.monthly_box.find_flashcards_for_review(remaining_flashcards, flashcards_for_review);
//         if (day % Week_length == 0 && !boxes.weekly_box.check_empty()) {
//             remaining_flashcards = boxes.monthly_box.find_flashcards_for_review(remaining_flashcards, flashcards_for_review);
//         }

//     }   
// }

string Leinter::to_string() {
    stringstream os;
    os << box[daily].to_string();
    os << box[every_three_days].to_string();
    os << box[weekly].to_string();
    os << box[monthly].to_string();
    os << "today is day: " << day << endl; 
    return os.str();
}