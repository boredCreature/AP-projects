#include <iostream>
#include <sstream>


#include "CmdManager.hpp"
using namespace std;

CmdManager::CmdManager() {
    leinter = new Leinter();
}

void CmdManager::run() {
    std::string command;
    while (std::cin >> command) { 
        if (command == "add_flashcard") {
            std::string question_number;
            std::cin >> question_number;
            handle_add_flashcards(question_number);
        }
    } 
}
void CmdManager::handle_add_flashcards(std::string question_number) {
    int flashcard_numbers = std::stoi(question_number);
    cin.ignore();
    for (int i = 0; i < flashcard_numbers; i++ ) {
        std::string question, answer;
        getline(std::cin, question);
        getline(std::cin, answer);
        Flashcard* new_flashcard = new Flashcard(question, answer);
        leinter->add_flashcards(new_flashcard);
    }
}

string CmdManager::to_string() {
    stringstream os;
    os << leinter->to_string();
    return os.str();
}
