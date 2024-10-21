#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

// function down below will put the words in a sentence to a vector called words
void get_word(const string sentence , vector<string>& words){
    string temp;
    for(char c : sentence){
        if(c != ' ')
            temp.push_back(c);
        else{
            if(!temp.empty()){
                words.push_back(temp);
                temp.clear();
            }
        }
    }
    if(!temp.empty()){
        words.push_back(temp);
    }
}

void new_category(vector<string> line, map<string, map<string , vector<int> >> &expenses){
    // line[1] refers to the name of the category 
    string category = line[1];
    expenses[category];
    for(auto it = line.begin() + 2; it != line.end(); it++){
        expenses[category][*it];
    }
}

int sub_category_sums(vector<int> expense){
    int sum = 0;
    for(auto it = expense.begin(); it != expense.end(); it++){
        sum += *it;
    }
    return sum;
}

int category_sums(map<string, vector<int>> category){
    int sum = 0;
    for(auto sub_category : category){
        sum += sub_category_sums(sub_category.second);
    }
    return sum;
}

void add_expense(vector<string> line, map<string, map<string , vector<int> >> &expenses){
    
    // line[1] contains <category/subcategory> part 
    string sub_line = line[1];
    int slash_pos = sub_line.find('/');
    string category = sub_line.substr(0, slash_pos);
    string sub_category = sub_line.substr(slash_pos + 1);
    int value = stoi(line.back());
    expenses[category][sub_category].push_back(value);
}

void remove_expense(vector<string> line, map<string, map<string , vector<int> >> &expenses){
    // line[1] contains <category/subcategory> part
    string sub_line = line[1];
    int slash_pos = sub_line.find('/');
    string category = sub_line.substr(0, slash_pos);
    string sub_category = sub_line.substr(slash_pos + 1);
    expenses[category][sub_category].pop_back();
}

bool check_threshold(vector<string> line, int sum){
    if((line.size() == 2 && sum > stoi(line[1])) | line.size() == 1){
        return true;
    }
    else{
        return false;
    }
}

vector<pair<string, int>> sort_sub_category(vector<string> line, map<string, vector<int>> category){
    vector<pair<string, int>> sub_categories;
    for(auto sub_category : category){
        int sum = 0;
        sum = sub_category_sums(sub_category.second);
        if(check_threshold(line, sum))
            sub_categories.push_back(make_pair(sub_category.first, sum));
    }
    sort(sub_categories.begin(), sub_categories.end(), 
        [](pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second;  // Sort in descending order of sums
        });
    return sub_categories;
}

void report(vector<string> line, map<string, map<string , vector<int> >> &expenses){
    map<string, map<string, vector<int> >>::iterator it = expenses.begin();
    vector<pair<string, int>> sub_categories;
    for(auto category : expenses){
            cout << "category: " << category.first << endl;
            cout << "total expenses: " << category_sums(category.second) << endl;
            cout << "subcategories expenses: " << endl; 
        
        sub_categories = sort_sub_category(line, category.second);
        //check_report_threshold(line, it->second);
        for(auto it2 = sub_categories.begin() ; it2 != sub_categories.end(); it2++){
            cout << "   -" << it2->first << " " << it2->second << endl;
        }
        if(it->first == (prev(expenses.end())->first)){
            cout << "**********\n";
        }
        else
            cout << "----------\n";
        it++;
    }
}

void command_detect(vector<vector<string>> &inputs, map<string, map<string , vector<int> >> &expenses){
    for(int i = 0 ; i < inputs.size(); i++){
        vector<string>::iterator it = inputs[i].begin();
        if(*it == "new_category"){
            new_category(inputs[i], expenses);
        }
        else if(*it == "add_expense"){
            add_expense(inputs[i], expenses);
        }
        else if(*it == "remove_expense"){
            remove_expense(inputs[i], expenses);
        }
        else if(*it == "report"){
            report(inputs[i], expenses);
        }
    }
}

void get_inputs(string sentence, vector<vector<string>> &inputs){
    while(getline(cin, sentence)){
        vector<string> word;
        get_word(sentence, word);
        inputs.push_back(word);
    }
}   

int main(){
    map<string, map<string , vector<int> >> expenses;
    vector<vector<string>> inputs;
    string sentence;
    get_inputs(sentence, inputs);
    command_detect(inputs, expenses);
    return 0;
}