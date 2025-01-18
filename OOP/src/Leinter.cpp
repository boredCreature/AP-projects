#include "Leinter.hpp"
#include <sstream>
#include <iostream>

using namespace std;

Leinter::Leinter() {
    for (int i = 0; i < NUM_OF_BOXES; i++) {
        box[i] = new Box();
    }
}

void Leinter::add_flashcards(Flashcard* flashcard) {
    box[daily]->add_flashcard(flashcard);
}

void Leinter::add_one_day() {
    day += 1;
}

vector<Flashcard*> Leinter::find_flashcards_for_review(int num_of_flashcards) {
    vector<Flashcard*> flashcards_for_review;
    int remaining_flashcards = num_of_flashcards;
    for (int i = remaining_flashcards; i > 0; i --) {
        for (int box_id = monthly; box_id >= daily; box_id --) {
            if (day % TIME_LENGTH_OF_BOX[box_id] == 0) {
                remaining_flashcards = box[box_id]->find_flashcards_for_review(remaining_flashcards, flashcards_for_review);
            }
        }
    }
    return flashcards_for_review;
}

bool Leinter::is_flashcard_answer_correct(Flashcard* flashcard, const string answer_by_user) {
    bool correctness = flashcard->get_answer() == answer_by_user;
    if (correctness == true)
        handle_correct_flashcard_move(flashcard);
    else
        handle_not_correct_flashcard_move(flashcard);
    return correctness;
}

int Leinter::find_box_id(Flashcard* flashcard) {
    
    for (int box_id = 0; box_id < NUM_OF_BOXES; box_id ++){ 
        if (box[box_id]->includes_flashcard(flashcard)) {
            return box_id;
        }
    }
    return -1; //just not to get compiler warnings
}

void Leinter::go_to_next_box(Flashcard* flashcard) {
    int box_id = find_box_id(flashcard);
    box[box_id]->remove_flashcard(flashcard);
    box[box_id + 1]->add_flashcard(flashcard);

}

void Leinter::go_to_previous_box(Flashcard* flashcard) {
    int box_id = find_box_id(flashcard);
    box[box_id]->remove_flashcard(flashcard);
    box[box_id - 1]->add_flashcard(flashcard);

}


bool Leinter::should_end_flashcard_lifecycle(Flashcard* flashcard) {
    int box_id = find_box_id(flashcard);
    if (box_id == monthly) {
        box[box_id]->remove_flashcard(flashcard);
        delete flashcard;
    }
    return (box_id == monthly);
}


void Leinter::handle_correct_flashcard_move(Flashcard* flashcard) {
    Box* flashcard_box = box[find_box_id(flashcard)];
    should_end_flashcard_lifecycle(flashcard);
    go_to_next_box(flashcard);
}

void Leinter::handle_not_correct_flashcard_move(Flashcard* flashcard) {
    int box_id = find_box_id(flashcard);
    if (box_id != daily) {
        go_to_previous_box(flashcard);
    }
}

string Leinter::to_string() {
    stringstream os;
    os << "daily box:" << box[daily]->to_string();
    os << "every three days box:" << box[every_three_days]->to_string() << endl;
    os << "weekly box: " << box[weekly]->to_string() << endl;
    os << "monthly box: " << box[monthly]->to_string() << endl;
    os << "today is day: " << day << endl; 
    return os.str();
}