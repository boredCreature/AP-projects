#ifndef LEINTER_HPP
#define LEINTER_HPP
#include "Box.hpp"


const int TIME_LENGTH_OF_BOX[] = {1, 3, 7, 30};
const int NUM_OF_BOXES = 4;

enum Box_Id{
    daily,
    every_three_days,
    weekly,
    monthly
};

enum move_direction {
    upper = 1,  
    lower = -1,
};


class Leinter{
public:
    Leinter();
    void add_flashcards(Flashcard* flashcard);
    void add_one_day();
    std::vector<Flashcard*> find_flashcards_for_review(int flashcards_number);
    int find_box_id(Flashcard* flashcard);
    void handle_flashcard_move(Flashcard* flashcard, bool answer_correctness);
    std::string to_string();
private:
    void move_flashcard(Flashcard* flashcard, int move_direction);
    void add_flashcards_to_all_reviewed_flashcards_in_day(std::vector<Flashcard*> reviewed_flashcards);
    std::vector<Flashcard*> all_reviewed_flashcards_in_day;
    std::vector<Flashcard*> unreviewed_flashcards_in_day;
    void find_unreviewed_flashcards_in_day();
    void handle_unreviewed_flashcards_move();
    Box* box[NUM_OF_BOXES];
    int day;
};



#endif


