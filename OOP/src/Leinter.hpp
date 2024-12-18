#ifndef LEINTER_HPP
#define LEINTER_HPP

#include <vector>
#include "Box.hpp"

struct Boxes {
    Box daily_box;
    Box three_days_box;
    Box weekly_box;
    Box monthly_box;
};

// a class for my top-level object
class Leinter{
public:
    void add_flashcards(Flashcard* flashcard);
    std::string to_string();
private:
    Boxes boxes;
};

#endif



