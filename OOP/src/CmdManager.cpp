#include <iostream>
#include <sstream>

#include "CmdManager.hpp"
using namespace std;


CmdManager::CmdManager() {
    leinter = new Leinter();
}

void CmdManager::handle_cmd(string cmd, string line) {

        if (cmd == "add_flashcard") {
            int question_number = stoi(line);
            handle_add_flashcards(question_number);
        }

        else if (cmd == "next_day") {
            handle_next_day();
        }
        
        else if (cmd == "review_today") {
            int flashcards_number = stoi(line);
            handle_review_flashcards(flashcards_number);
        }

        else if (cmd == "get_report") {
            string begin_day = line.substr(0, line.find(" "));
            string end_day = line.substr(line.find(" ") + 1);
            handle_get_report(stoi(begin_day), stoi(end_day));
        }

        else if (cmd == "get_progress_report") {
            handle_get_progress_report();
        }

        else if (cmd == "streak") {
            handle_streak();
        }

}

void CmdManager::handle_add_flashcards(int question_number) {

    for (int i = 0; i < question_number; i++ ) {
        string question, answer;
        getline(cin, question);
        getline(cin, answer);
        Flashcard* new_flashcard = new Flashcard(question, answer);
        leinter->add_flashcards(new_flashcard);
    }
    cout << "flashcards added to the daily box" << endl;
}

void CmdManager::handle_next_day() {
    leinter->update_streak();
    leinter->add_one_day();
    leinter->make_performance_record();

    cout << "Good morning! Today is day " << leinter->get_progress().day << " of our journey." << endl;
    cout << "Your current streak is: " << leinter->get_progress().streak << endl;
    cout << "Start reviewing to keep your streak!" << endl;
}

void CmdManager::handle_review_flashcards(int flashcard_number) {
    leinter->add_to_participated_days();
    vector<Flashcard*> flashcards_for_review = leinter->find_flashcards_for_review(flashcard_number);
    
    for (auto flashcard : flashcards_for_review) {
        handle_single_flashcard_review(flashcard);
    }

    cout << "You’ve completed today’s review! Keep the momentum going and continue building "
    "your knowledge, one flashcard at a time!" << endl;
}

void CmdManager::handle_single_flashcard_review(Flashcard* flashcard) {
    string user_answer;
        cout << "Flashcard: " << flashcard->get_quesetion() << endl;
        cout << "Your answer: " << endl;
        getline(cin, user_answer);
        bool correctness = flashcard->is_answer_correct(user_answer);

        leinter->update_performance_records(correctness);
        leinter->handle_flashcard_move(flashcard, correctness);

        correctness ? cout << "Your answer was correct! Well done, keep it up!" << endl
                    : cout << "Your answer was incorrect. Don't worry! The correct answer is: " << flashcard->get_answer() << ". Keep practicing!" << endl;
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

void CmdManager::handle_get_progress_report() {
    cout << "Challenge Progress Report: \n" << endl;
    cout << "Day of the Challenge: " << leinter->get_progress().day << endl;
    cout << "Streak: " << leinter->get_progress().streak << endl;
    cout << "Total Days Participated: " << leinter->get_progress().num_of_participated_days << endl;
    cout << "Mastered Flashcards: " << leinter->get_progress().num_of_mastered_flashcards << endl;
    cout << endl;
    cout << "Keep up the great work!    " << "You're making steady progress toward mastering your flashcards. " << endl;
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