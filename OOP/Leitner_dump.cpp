#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


enum BoxIndex {
    daily_box = 0,
    three_days_box,
    weekly_box,
    monthly_box
};

class Card {
public:
    Card(string q, string a) {question = q, answer = a;}
    string to_string();
private:
string question;
string answer;
};


string Card::to_string() {
    ostringstream os;
    os << question << endl;
    os << answer << endl;
    return os.str();
}

class Box {
public:
    Box(string n) {name = n;}
    void add_flashcards(string question, string answer);
    string to_string();
private:
string name;
vector<Card> cards;
};

void Box::add_flashcards(string question, string answer) {
    cards.push_back(Card(question, answer));
}

string Box::to_string() {
    ostringstream os;
    os << name << endl;
    for (auto card : cards) {
        os << card.to_string() << endl;
    }
    return os.str();
}


class Leinter{
public:
    Leinter(vector<Box> b) {boxes = b;}
    void add_flashcards(string question, string answer);
    string to_string();
private:
vector<Box> boxes;
};

void Leinter::add_flashcards(string question, string answer) {
    boxes[daily_box].add_flashcards(question, answer);
}

string Leinter::to_string() {
    ostringstream os;
    for (auto box : boxes) {
        os << box.to_string() << endl;
    }
    return os.str();
}


void handle_commands(Leinter leinter) {
    string command;
    while (cin >> command) {
        if (command == "add_flashcard") {
            string flashcard_number,question, answer;
            cin >> flashcard_number;
            cin.ignore();
            for (int i = 0; i < stoi(flashcard_number); i++) {
                getline(cin, question);
                getline(cin, answer);
                leinter.add_flashcards(question, answer);
            }
        }
        else if (command == "dump") {
            cout << leinter.to_string();
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


