#ifndef FLASHCARD_HPP
#define FLASHCARD_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Flashcard {
public:
    Flashcard(std::string questoin_, std::string answer_) {question = questoin_, answer = answer_, num_of_wrong_answer = 0; }
    std::string get_quesetion();
    std::string get_answer();
    int get_num_of_wrong_answers();
    void add_one_to_wrong_answers();
    void reset_wrong_answers();
    std::string to_string();
private:
    std::string question;
    std::string answer;
    int num_of_wrong_answer;
};


#endif