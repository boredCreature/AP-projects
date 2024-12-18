#include "Leinter.hpp"
#include <sstream>
#include <iostream>

using namespace std;

Leinter::Leinter() : day(1) {}


void Leinter::add_flashcards(Flashcard* flashcard) {
    boxes.daily_box.add_flashcard(flashcard);
}

void Leinter::add_one_day() {
    day += 1;
}

string Leinter::to_string() {
    stringstream os;
    os << boxes.daily_box.to_string();
    os << boxes.three_days_box.to_string();
    os << boxes.weekly_box.to_string();
    os << boxes.monthly_box.to_string();
    os << "today is day: " << day << endl; 
    return os.str();
}