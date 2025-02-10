#ifndef FLASHCARD_HPP
#define FLASHCARD_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>


class Flashcard {
public:
    Flashcard(std::string questoin_, std::string answer_) {question = questoin_, answer = answer_;}
    bool is_answer_correct(std::string user_answer);
    void reset_num_of_wrong_answers();
    bool should_move_to_next_box_because_of_wrong_answer();
    std::string get_quesetion();
    std::string get_answer();
    std::string to_string();
private:
    void add_one_to_wrong_answers();
    std::string question;
    std::string answer;
    int num_of_wrong_answers;
};

#endif
