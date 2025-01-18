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
            cin.ignore();
            handle_add_flashcards(question_number);
        }
        else if (command == "next_day") {
            handle_time();
        }
        else if (command == "review_today") {
            string num_of_flashcards;
            cin >> num_of_flashcards;
            cin.ignore();
            handle_review_flashcards(num_of_flashcards);
        }
    }
}

void CmdManager::handle_add_flashcards(string question_number) {
    int flashcard_numbers = stoi(question_number);
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


void CmdManager::handle_review_flashcards(string num_of_flashcards) {
    int num_of_flashcards_ = stoi(num_of_flashcards);
    vector<Flashcard*> flashcards_for_review = leinter->find_flashcards_for_review(num_of_flashcards_);
    
    for (auto flashcard : flashcards_for_review) {
        string user_answer;
        cout << "Flashcard: " << flashcard->get_quesetion() << endl;
        cout << "Your Answer: ";
        getline(cin, user_answer);
        
        if (leinter->is_flashcard_answer_correct(flashcard, user_answer))
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
