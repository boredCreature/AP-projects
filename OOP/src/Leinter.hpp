#ifndef LEINTER_HPP
#define LEINTER_HPP
#include <map>
#include "Box.hpp"

enum Time_Periods{
    day,
    three_days,
    week,
    month
};

const int time_length_of[] = {1, 3, 7, 30};
const int num_of_boxes = 4;

enum Box_Time_Id {
    daily,
    every_three_days,
    weekly,
    monthly
};


// a class for my top-level object
class Leinter{
public:
    Leinter();
    void add_flashcards(Flashcard* flashcard);
    void add_one_day();
    //vector<Flashcard*> find_flashcards_for_review(int flashcards_number);
    std::string to_string();
private:
    Box box[num_of_boxes];
    int day;
};



#endif
