#ifndef BOX_HPP
#define BOX_HPP

#include <vector>
#include "Flashcard.hpp"

class Box{
public:
    void add_flashcard(Flashcard* new_flashcard); 
    std::string to_string();
private:
    std::vector<Flashcard*> flashcards;
};

#endif