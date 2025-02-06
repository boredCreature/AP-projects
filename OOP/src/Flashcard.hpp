#ifndef FLASHCARD_HPP
#define FLASHCARD_HPP
#include <iostream>
#include <string>
#include <vector>

class Flashcard {
public:
    Flashcard(std::string questoin_, std::string answer_) {question = questoin_, answer = answer_;}
    std::string get_quesetion();
    std::string get_answer();
    std::string to_string();
private:
    std::string question;
    std::string answer;
};


#endif