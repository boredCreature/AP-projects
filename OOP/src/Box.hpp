#ifndef BOX_HPP
#define BOX_HPP

#include <vector>
#include "Flashcard.hpp"

class Box{
public:
    void add_flashcard(Flashcard* new_flashcard); 
    bool check_empty();
    // int find_flashcards_for_review(int remaining_flashcards, vector<Flashcard*>& flashcards_for_review);
    std::string to_string();
private:
    std::vector<Flashcard*> flashcards;
};

#endif