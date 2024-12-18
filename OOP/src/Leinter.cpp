#include "Leinter.hpp"
#include <sstream>
#include <iostream>

using namespace std;

void Leinter::add_flashcards(Flashcard* flashcard) {
    boxes.daily_box.add_flashcard(flashcard);
}

string Leinter::to_string() {
    stringstream os;
    os << boxes.daily_box.to_string();
    os << boxes.three_days_box.to_string();
    os << boxes.weekly_box.to_string();
    os << boxes.monthly_box.to_string();
    return os.str();
}