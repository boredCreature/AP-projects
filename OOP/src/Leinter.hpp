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


struct performance{
    int num_of_correct_answers;
    int num_of_wrong_answers;
    
    performance(int correct = 0, int wrong = 0) : num_of_correct_answers(correct), 
                                                  num_of_wrong_answers(wrong) {};
    int get_total_answers () {
        return num_of_correct_answers + num_of_wrong_answers;
    }    
};

struct Progress {
    int day;
    int streak;
    int num_of_participated_days;
    int num_of_mastered_flashcards;
};


class Leinter{
public:
    Leinter();
    void add_flashcards(Flashcard* flashcard);
    void add_one_day();
    std::vector<Flashcard*> find_flashcards_for_review(int flashcards_number);
    int find_box_id(Flashcard* flashcard);
    void handle_flashcard_move(Flashcard* flashcard, bool answer_correctness);
    std::map<int, performance> get_performance_records() {return performance_records; }
    void update_performance_records(bool correctness);
    void make_performance_record();
    void update_streak();
    int get_streak() {return progress.streak; }
    void add_to_num_of_mastered_flashcards();
    Progress get_progress () {return progress; }
    void add_to_participated_days();
    std::string to_string();
private:
    void move_flashcard(Flashcard* flashcard, int move_direction);
    void add_flashcards_to_all_reviewed_flashcards_in_day(std::vector<Flashcard*> reviewed_flashcards);
    std::vector<Flashcard*> all_reviewed_flashcards_in_day;
    std::vector<Flashcard*> unreviewed_flashcards_in_day;
    void find_unreviewed_flashcards_in_day();
    void handle_unreviewed_flashcards_move();
    Box* box[NUM_OF_BOXES];
    std::map<int, performance> performance_records;
    Progress progress;

};

#endif

