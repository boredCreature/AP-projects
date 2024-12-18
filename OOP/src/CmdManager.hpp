#ifndef CMD_MANAGER_HPP
#define CMD_MANAGER_HPP

#include "Leinter.hpp"


class CmdManager {
public:
    CmdManager();
    void run();
    void handle_add_flashcards(std::string question_number);
    void handle_time();
    void handle_review_flashcards(std::string flashcards_number);
    std::string to_string();
private:
    Leinter* leinter;
};

#endif
