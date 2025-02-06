#ifndef LEINTER_HPP
#define LEINTER_HPP
#include "Box.hpp"


const int time_length_of_box[] = {1, 3, 7, 30};
const int num_of_boxes = 4;

enum Box_Id{
    daily,
    every_three_days,
    weekly,
    monthly
};


class Leinter{
public:
    Leinter();
    void add_flashcards(Flashcard* flashcard);
    void add_one_day();
    std::vector<Flashcard*> find_flashcards_for_review(int flashcards_number);
    bool check_user_answer(std::string flashcard_answer, std::string user_answer);
    std::string to_string();
private:
    Box box[num_of_boxes];
    int day;
};



#endif
