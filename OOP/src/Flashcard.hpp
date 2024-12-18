#ifndef FLASHCARD_HPP
#define FLASHCARD_HPP
#include <string>

class Flashcard {
public:
    Flashcard(std::string questoin_, std::string answer_) {question = questoin_, answer = answer_;}
    std::string to_string();
private:
    std::string question;
    std::string answer;
};


#endif