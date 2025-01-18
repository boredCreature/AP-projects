#ifndef BOX_HPP
#define BOX_HPP

#include "Flashcard.hpp"

class Box{
public:
    void add_flashcard(Flashcard* new_flashcard); 
    bool check_empty();
    int find_flashcards_for_review(int remaining_flashcards, std::vector<Flashcard*>& flashcards_for_review);
    bool includes_flashcard(Flashcard* flashcard);
    void remove_flashcard(Flashcard* flashcard);
    int get_num_of_flashcards();
    std::string to_string();
private:
    std::vector<Flashcard*> flashcards;
};

#endif