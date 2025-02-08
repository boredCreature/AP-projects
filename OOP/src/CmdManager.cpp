#include <iostream>
#include <sstream>

#include "CmdManager.hpp"
using namespace std;


CmdManager::CmdManager() {
    leinter = new Leinter();
}

void CmdManager::handle_inputs() {
    string command;
    while (cin >> command) { 
        if (command == "add_flashcard") {
            string question_number;
            cin >> question_number;
            handle_add_flashcards(question_number);
        }
        else if (command == "next_day") {
            handle_time();
        }
        else if (command == "review_today") {
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
    cout << "Flashcards added to the daily box" << endl;
}

void CmdManager::handle_time() {
    leinter->add_one_day();
}

void CmdManager::handle_review_flashcards(string flashcards_number) {
    int flashcards_number_ = stoi(flashcards_number);
    vector<Flashcard*> flashcards_for_review = leinter->find_flashcards_for_review(flashcards_number_);
    
    for (auto flashcard : flashcards_for_review) {
        string user_answer;
        cout << "Flashcard: " << flashcard->get_quesetion() << endl;
        cout << "Your Answer: ";
        cin.ignore();
        getline(cin, user_answer);
        bool correctness = flashcard->is_answer_correct(user_answer);
        leinter->handle_flashcard_move(flashcard, correctness);
        if (correctness)
            cout << "Your answer was correct! Well done, keep it up!" << endl;
        else
            cout << "Your answer was incorrect. Don't worry! The correct answer is: " << flashcard->get_answer() << endl;
    }

    cout << "Keep practicing!" << endl;
    cout << "You've completed today's review! Keep the momentum going and continue building "
    "your knowledge, one flashcard at a time!" << endl;
}

string CmdManager::to_string() {
    stringstream os;
    os << leinter->to_string();
    return os.str();
}
