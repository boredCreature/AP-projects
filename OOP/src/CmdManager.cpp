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
            handle_next_day();
        }
        else if (command == "review_today") {
            string flashcards_number;
            cin >> flashcards_number;
            cin.ignore();
            handle_review_flashcards(flashcards_number);
        }
        else if (command == "get_report") {
            string begin_day, end_day;
            cin >> begin_day >> end_day;
            handle_get_report(stoi(begin_day), stoi(end_day));
        }
        else if (command == "streak") {
            handle_streak();
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
    cout << "Flashcards added to the daily box" << endl;
}

void CmdManager::handle_next_day() {
    leinter->update_streak();
    leinter->add_one_day();
    leinter->make_performance_record();
}

void CmdManager::handle_review_flashcards(string flashcards_number) {
    int flashcards_number_ = stoi(flashcards_number);
    vector<Flashcard*> flashcards_for_review = leinter->find_flashcards_for_review(flashcards_number_);
    
    for (auto flashcard : flashcards_for_review) {
        string user_answer;
        cout << "Flashcard: " << flashcard->get_quesetion() << endl;
        cout << "Your Answer: ";
        getline(cin, user_answer);
        bool correctness = flashcard->is_answer_correct(user_answer);
        leinter->handle_flashcard_move(flashcard, correctness);
        if (correctness) {
            leinter->add_to_num_of_correct_answers();
            cout << "Your answer was correct! Well done, keep it up!" << endl;
        }
        else {
            leinter->add_to_num_of_wrong_answers();
            cout << "Your answer was incorrect. Don't worry! The correct answer is: " << flashcard->get_answer() << endl;
        }
    }

    cout << "Keep practicing!" << endl;
    cout << "You've completed today's review! Keep the momentum going and continue building "
    "your knowledge, one flashcard at a time!" << endl;
}

void CmdManager::handle_get_report(int begin_day, int end_day) {

    map<int, performance> performance_records = leinter->get_performance_records();
    int total_correct_answers = 0;
    int total_incorrect_answers = 0;

    for (int i = begin_day; i <= end_day; i++) {
        total_correct_answers += performance_records[i].num_of_correct_answers;
        total_incorrect_answers += performance_records[i].num_of_wrong_answers;
    }

    int total_answers = total_correct_answers + total_incorrect_answers;

    (begin_day == end_day) ? (cout << "Day: " << begin_day << endl) 
                           : (cout << "Day: " << begin_day << " to " << end_day << endl);
                           
    cout << "Correct Answers: " << total_correct_answers << endl;
    cout << "Incorrect Answers: " << total_incorrect_answers << endl;
    cout << "Total: " << total_answers << endl;
    
}

void CmdManager::handle_streak() {
    cout << "Your current streak is: " << leinter->get_streak() << endl;
    cout << "Keep going!" << endl;
}

string CmdManager::to_string() {
    stringstream os;
    os << leinter->to_string();
    return os.str();
}