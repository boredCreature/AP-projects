#include "Leinter.hpp"
#include <sstream>
#include <iostream>

using namespace std;

Leinter::Leinter() {
    for (int box_id = 0; box_id < NUM_OF_BOXES; box_id++) {
        box[box_id] = new Box();
    }

    progress.day = 1;
    progress.streak = 0;
    progress.num_of_participated_days = 0;
    progress.num_of_mastered_flashcards = 0;
}

void Leinter::add_flashcards(Flashcard* flashcard) {
    box[daily]->add_flashcard(flashcard);
}

void Leinter::add_one_day() {
    progress.day += 1;
    handle_unreviewed_flashcards_move();
}

vector<Flashcard*> Leinter::find_flashcards_for_review(int flashcards_number) {
    vector<Flashcard*> flashcards_for_review;
    int remaining_flashcards = flashcards_number;
    for (int i = remaining_flashcards; i > 0; i --) {
        for (int box_id = monthly; box_id >= daily; box_id --) {
            if (progress.day % TIME_LENGTH_OF_BOX[box_id] == 0) {
                remaining_flashcards = box[box_id]->find_flashcards_for_review(remaining_flashcards, flashcards_for_review);
            }
        }
    }
    add_flashcards_to_all_reviewed_flashcards_in_day(flashcards_for_review);
    return flashcards_for_review;
}

int Leinter::find_box_id(Flashcard* flashcard) {
    for (int box_id = 0; box_id < NUM_OF_BOXES; box_id ++) {
        if (box[box_id]->does_include_flashcard(flashcard)) {
            return box_id;
        }
    }
    return -1; //just not to get compiler warning
}


void Leinter::handle_flashcard_move(Flashcard* flashcard, bool answer_correction) {
    int box_id = find_box_id(flashcard);

    //END FLASHCARD LIFECYCLE   
    if (answer_correction && box_id == Box_Id::monthly) {
        box[box_id]->delete_flashcard(flashcard);
        add_to_num_of_mastered_flashcards();
    }
    else if (!answer_correction && box_id == Box_Id::daily)
        return;

    else if ((!answer_correction && flashcard->should_move_to_next_box_because_of_wrong_answer()) || answer_correction)
    {   move_direction direction = answer_correction ? move_direction::upper : move_direction::lower;
        move_flashcard(flashcard, direction);
        //Reset flashcard number of wrong answers
        flashcard->reset_num_of_wrong_answers();}

}

void Leinter::move_flashcard(Flashcard* flashcard, int move_direction) {
    int box_id = find_box_id(flashcard);
    box[box_id]->delete_flashcard(flashcard);

    if (move_direction == move_direction::upper)
        box[box_id + 1]->add_flashcard(flashcard);

    else if (move_direction == move_direction::lower) 
        box[box_id - 1]->add_flashcard(flashcard);
}

void Leinter::add_flashcards_to_all_reviewed_flashcards_in_day(vector<Flashcard*> reviewed_flashcards) {
    all_reviewed_flashcards_in_day.insert(all_reviewed_flashcards_in_day.end(), reviewed_flashcards.begin(), reviewed_flashcards.end());
}

void Leinter::find_unreviewed_flashcards_in_day() {
    vector<Flashcard*> unreviewed_flashcards_in_day;
    for (int box_id = 0; box_id < NUM_OF_BOXES; box_id ++) {
        if (progress.day % TIME_LENGTH_OF_BOX[box_id] == 0) {
            vector<Flashcard*> unreviewed_flashcards = box[box_id]->handle_unreviewed_flashcards(unreviewed_flashcards_in_day);
            unreviewed_flashcards_in_day.insert(unreviewed_flashcards_in_day.end(), unreviewed_flashcards.begin(), unreviewed_flashcards.end());
        }
    }
}

void Leinter::handle_unreviewed_flashcards_move() {
    for (auto flashcard : unreviewed_flashcards_in_day) {
        handle_flashcard_move(flashcard, move_direction::lower);
    }
}

void Leinter::update_performance_records(bool correctness) {
    correctness ? performance_records[progress.day].num_of_correct_answers += 1
                : performance_records[progress.day].num_of_wrong_answers +=1;
}

void Leinter::make_performance_record() {
    performance performance_record;
    performance_records[progress.day] = performance_record;
}


void Leinter::update_streak() {
    performance_records[progress.day].get_total_answers() != 0 ? progress.streak += 1 : progress.streak = 0;
}

void Leinter::add_to_num_of_mastered_flashcards() {
    progress.num_of_mastered_flashcards += 1;
}

void Leinter::add_to_participated_days() {
    progress.num_of_participated_days += 1;
}


string Leinter::to_string() {
    stringstream os;
    os << "Box daily: " << box[daily]->to_string() << endl;
    os << "Box every three days: " << box[every_three_days]->to_string() << endl;
    os << "Box weekly: " << box[weekly]->to_string() << endl;
    os << "Box monthly: " << box[monthly]->to_string() << endl;
    os << "today is day: " << progress.day << endl; 
    return os.str();
}