#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;



class Card {
public:
    Card(string q, string a) {question = q, answer = a;}
private:
string question;
string answer;
};


class Box {
public:
    Box(string n) {name = n;}
    void add_flashcards(string question, string answer);
private:
string name;
vector<Card> cards;
};

void Box::add_flashcards(string question, string answer) {
    cards.push_back(Card(question, answer));
}


class Leinter{
public:
    Leinter(vector<Box> b) {boxes = b;}
    void add_flashcards(string question, string answer);
private:
vector<Box> boxes;
};


void Leinter::add_flashcards(string question, string answer) {
    boxes[0].add_flashcards(question, answer);
}

void handle_add_flashcard(Leinter& leinter) {
    string flashcard_number, question, answer;
    cin >> flashcard_number;
    cin.ignore();
    for (int i = 0; i < stoi(flashcard_number); i++) {
        getline(cin, question);
        getline(cin, answer);
        leinter.add_flashcards(question, answer);
    }
}

void handle_commands(Leinter& leinter) {
    string command;
    while(cin >> command) {
        if (command == "add_flashcard") {
            handle_add_flashcard(leinter);
            cout << "flashcards added to the daily box" << endl;
        }
    }
}

int main() {

    Leinter leinter(
        {Box("Daily"), Box("Three_days"), Box("weekly"), Box("Monthly")}
    ); 
    handle_commands(leinter);
    return 0;
}
