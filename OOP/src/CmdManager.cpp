#include <iostream>
#include <sstream>

#include "CmdManager.hpp"
using namespace std;


CmdManager::CmdManager() {
    leinter = new Leinter();
}

void CmdManager::run() {
    string command;
    while (cin >> command) { 
        if (command == "add_flashcard") {
            string question_number;
            cin >> question_number;
            handle_add_flashcards(question_number);
        }
        if (command == "next_day") {
            handle_time();
        }
        if (command == "review_today") {
            string flashcards_number;
            cin >> flashcards_number;
            handle_review_flashcards(flashcards_number);
        }
    }
}

void CmdManager::handle_add_flashcards(string question_number) {
    int flashcard_numbers = stoi(question_number);
    cin.ignore();
    for (int i = 0; i < flashcard_numbers; i++ ) {
        string question, answer;
        getline(cin, question);
        getline(cin, answer);
        Flashcard* new_flashcard = new Flashcard(question, answer);
        leinter->add_flashcards(new_flashcard);
    }
}

void CmdManager::handle_time() {
    leinter->add_one_day();
}

void CmdManager::handle_review_flashcards(string flashcards_number) {
    int flashcards_number_ = stoi(flashcards_number);
    vector<Flashcard*> flashcards_for_review = leinter->find_flashcards_for_review(flashcards_number_);
}

string CmdManager::to_string() {
    stringstream os;
    os << leinter->to_string();
    return os.str();
}
