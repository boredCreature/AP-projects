#ifndef BOX_HPP
#define BOX_HPP

#include "Flashcard.hpp"

class Box{
public:
    void add_flashcard(Flashcard* new_flashcard);
    void delete_flashcard(Flashcard* flashcard);
    bool check_empty();
    int find_flashcards_for_review(int remaining_flashcards, std::vector<Flashcard*>& flashcards_for_review);
    bool does_include_flashcard(Flashcard* flashcard);
    std::vector<Flashcard*> handle_unreviewed_flashcards(std::vector<Flashcard*> all_reviewed_flashcards_in_day);
    std::string to_string();
private:
    std::vector<Flashcard*> flashcards;
};

#endif

