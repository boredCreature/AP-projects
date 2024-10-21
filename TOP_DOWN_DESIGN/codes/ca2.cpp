#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;


struct Spot{
        int size;
        string type;

    };
struct Price{
        int StaticPrice;
        int PricePerDay;
        
};

typedef map<string, int> CarMap;
typedef map<int, Spot> SpotMap;
typedef map<int, Price> PriceMap;
typedef map<string, int> Inputs;


//this function splits the CVS file and store words in a vector of string
vector<string> SplitString(string line, char delimiter = ','){

    vector<string> tokens;
    string token;
    stringstream ss(line);
    while(getline(ss, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}


void readCarFile(const string& CarFile, CarMap& cars){
    ifstream file(CarFile);
    string line, TopOfFile = "name,size";
    while(getline(file, line)){
        if(line != TopOfFile){
            auto tokens = SplitString(line);
            string CarName = tokens[0];
            int size = stoi(tokens[1]);
            cars[CarName] = size;
        }
    }
}

void readSpotFile(const string& SpotFile, SpotMap& spots ){

    ifstream File(SpotFile);
    string line, TopOfLine = "id,size,type";
    while(getline(File, line)){
        if(line != TopOfLine){
            auto tokens = SplitString(line);
            int id = stoi(tokens[0]), size = stoi(tokens[1]);
            string type = tokens[2];
            spots[id] = {size, type};
            
        }
    }
}

void readPricesFile(const string& PricesFile, PriceMap& prices ){

    ifstream File(PricesFile);
    string TopOfLine = "size,static_price,price_per_day", line;
    while(getline(File, line)){
        if(line != TopOfLine){
            auto tokens = SplitString(line);
            int size = stoi(tokens[0]), StaticPrice = stoi(tokens[1]),
            PricePerDay = stoi(tokens[2]);
            prices[size] = {StaticPrice, PricePerDay};

        }
    }
}
void fillStatusMap(map<int, bool>& SpotStatus, SpotMap& spots){
    for(auto& spot : spots){
        SpotStatus[spot.first] = true;
    }
}

int calculatePrice(string type, int BasePrice, int CoveredAddition, int CCTVAddition){
    if(type == "covered"){
        return BasePrice + CoveredAddition;
    }
    else if(type == "CCTV"){
        return BasePrice + CCTVAddition;
    }
    return BasePrice;
}

vector<int> findSuitableSpots(int CarSize, SpotMap& spots){
    vector<int> SuitableSpots;
    for(auto spot : spots){
        if(spot.second.size == CarSize){
            SuitableSpots.push_back(spot.first);
        }
    }
    return SuitableSpots;
}

void requestSpot(string CarName, CarMap& cars, SpotMap& spots, PriceMap& prices){
    int CarSize = cars[CarName];
    auto SuitableSpots = findSuitableSpots(CarSize, spots);
    for(auto SpotID : SuitableSpots){
        auto spot = spots[SpotID];
        int StaticPrice = calculatePrice(spot.type, prices[CarSize].StaticPrice, 50, 80);
        int PricePerDay = calculatePrice(spot.type, prices[CarSize].PricePerDay, 30, 60);
        cout << SpotID << ": " << spot.type << " " << StaticPrice << " " << PricePerDay << endl;
    }
}

void handleRequestSpot(vector<string> words,CarMap& cars, SpotMap& spots, PriceMap& prices){
    string CarName = words[1];
    requestSpot(CarName, cars, spots, prices);
}

void assignSpot(int ID, map<int, bool>& SpotStatus){
    if(SpotStatus[ID] == true){
        SpotStatus[ID] = false;
        cout << "Spot " << ID << " is occupied now." << endl;
    }
}

void handleAssignSpot(vector<string> words, map<int, bool>& SpotStatus, map<int, int>& SpotDays){
    int ID = stoi(words[1]);
    SpotDays[ID] = 0;
    assignSpot(ID,SpotStatus);

}

void passTime(int NumOfDays, map<int, int>& SpotDays){
    for(auto& ID : SpotDays){
        ID.second += NumOfDays;
    }
}

void handlePassTime(vector<string> words, map<int, int>& SpotDays){
    int NumOfDays = stoi(words[1]);
    passTime(NumOfDays, SpotDays);
}

int calculateTotalCost(int ID, map<int, int>& SpotDays, SpotMap& spots, PriceMap& prices){
    int UsedDays = SpotDays[ID];
    auto spot = spots[ID];
    int BaseStaticPrice = prices[spot.size].StaticPrice,
    BasePricePerDay = prices[spot.size].PricePerDay,
    StaticPrice = calculatePrice(spot.type, BaseStaticPrice, 50, 80),
    PricePerDay = calculatePrice(spot.type, BasePricePerDay, 30, 60);
    return StaticPrice + (UsedDays * PricePerDay);

}


void checkOut(int ID, map<int, bool>& SpotStatus, map<int, int>& SpotDays, SpotMap& spots, PriceMap& prices){
    SpotStatus[ID] = true;
    int TotalCost = calculateTotalCost(ID, SpotDays, spots, prices);
    SpotDays.erase(ID);
    cout << "spot " << ID << " is free now." << endl;
    cout << "total cost: " << TotalCost << endl;
}

void handleCheckOut(vector<string> words, map<int, bool>& SpotStatus, map<int, int>& SpotDays, SpotMap& spots, PriceMap& prices){
    int ID = stoi(words[1]);
    checkOut(ID, SpotStatus, SpotDays, spots, prices);
}

string FirstWordInSentence(vector<string>& words) {
    string FirstWord = words[0];
    return FirstWord;

}

void handleCommand(vector<string>& words, CarMap& cars, SpotMap& spots, PriceMap& prices, 
                   map<int, bool>& SpotStatus, map<int, int>& SpotDays) {
    string command = FirstWordInSentence(words);
    
    if (command == "request_spot") {
        handleRequestSpot(words, cars, spots, prices);
    } else if (command == "assign_spot") {
        handleAssignSpot(words, SpotStatus, SpotDays);
    } else if (command == "checkout") {
        handleCheckOut(words, SpotStatus, SpotDays, spots, prices);
    } else if (command == "pass_time") {
        handlePassTime(words, SpotDays);
    }
}

void getCommands(CarMap& cars, SpotMap& spots, PriceMap& prices, 
                 map<int, bool>& SpotStatus, map<int, int>& SpotDays) {
    string line;
    while (getline(cin, line)) {
        vector<string> words = SplitString(line, ' ');
        handleCommand(words, cars, spots, prices, SpotStatus, SpotDays);
    }
}

void runParkManagement(const string& CarFile, const string& SpotFile, const string& PriceFile) {
    CarMap cars;
    SpotMap spots;
    PriceMap prices;

    map<int, bool> SpotStatus;
    map<int, int> SpotDays;
    
    fillStatusMap(SpotStatus, spots);
    //reading Files
    readCarFile(CarFile, cars);
    readSpotFile(SpotFile, spots);
    readPricesFile(PriceFile, prices);
    //calling a function to run commands
    getCommands(cars, spots, prices, SpotStatus, SpotDays);
}

int main(int argc, char* argv[]){
    runParkManagement(argv[1], argv[2], argv[3]);
    return 0;

}


