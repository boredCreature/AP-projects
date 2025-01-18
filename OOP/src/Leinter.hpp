#ifndef LEINTER_HPP
#define LEINTER_HPP
#include "Box.hpp"

const int DAY = 1;
const int THREE_DAYS = 3;
const int WEEK = 7;
const int MONTH = 30;

const int TIME_LENGTH_OF_BOX[] = {DAY, THREE_DAYS, WEEK, MONTH};
const int NUM_OF_BOXES = 4;
const int FLASHCARD_MAX_WRONG_ANSWER = 2;

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
    std::vector<Flashcard*> find_flashcards_for_review(int num_of_flashcards);
    bool is_flashcard_answer_correct(Flashcard* flashcard, std::string answer_by_user);
    std::string to_string();
private:
    int find_box_id(Flashcard* flashcard);
    void move_flashcard(Flashcard* flashcard);
    void go_to_next_box(Flashcard* flashcard);
    void go_to_previous_box(Flashcard* flashcard);
    void handle_correct_flashcard_move(Flashcard* flashcard);
    void handle_not_correct_flashcard_move(Flashcard* flashcard);
    bool should_end_flashcard_lifecycle(Flashcard* flashcard);
    Box* box[NUM_OF_BOXES];
    int day;
};



#endif
