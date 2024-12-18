#ifndef LEINTER_HPP
#define LEINTER_HPP
#include <map>
#include "Box.hpp"

enum box_time_periods{
    day_length = 1,
    every_three_days_length = 3,
    week_legnth = 7,
    month_length = 30
};

struct boxes {
    Box daily_box;
    Box three_days_box;
    Box weekly_box;
    Box monthly_box;
};



// a class for my top-level object
class Leinter{
public:
    Leinter();
    void add_flashcards(Flashcard* flashcard);
    void add_one_day();
    vector<Flashcard*> find_flashcards_for_review(int flashcards_number);
    std::string to_string();
private:
    // boxes boxes;
    int day;
};



#endif



