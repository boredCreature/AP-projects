#ifndef CMD_MANAGER_HPP
#define CMD_MANAGER_HPP

#include "Leinter.hpp"


class CmdManager {
public:
    CmdManager();
    void handle_cmd(std::string cmd, std::string line);
    std::string to_string();
private:
    void handle_add_flashcards(int question_number);
    void handle_next_day();
    void handle_review_flashcards(int flashcards_number);
    void handle_single_flashcard_review(Flashcard* flashcard);
    void handle_get_report(int begin_day,int end_day);
    void handle_get_progress_report();
    void handle_streak();
    Leinter* leinter;
};

#endif
