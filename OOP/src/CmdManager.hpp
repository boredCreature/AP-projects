#ifndef CMD_MANAGER_HPP
#define CMD_MANAGER_HPP

#include "Leinter.hpp"


class CmdManager {
public:
    CmdManager();
    void handle_inputs();
    void handle_add_flashcards(std::string question_number);
    void handle_next_day();
    void handle_review_flashcards(std::string flashcards_number);
    void handle_get_report(int begin_day,int end_day);
    std::string to_string();
private:
    Leinter* leinter;
};

#endif
