#include <iostream>
#include <fstream>
#include <list>
#include <string>
//double balance = -385.00;

void golf(std::list<double>& ledger,bool weekday, int holes){
    double price = 0;
    if (weekday){ //pricing information for your course goes here (cost of games without the membership). My course charges based on the day of the week as well as number of holes
        if (holes == 9){
            price = 13.00;
        }
        else{
            price = 21.00;
        }
    }
    else{
        if (holes == 9){
            price = 14.00;
        }
        else{
            price = 23.00;
        }
    }
    ledger.push_back(price);
}

double getBalance(std::list<double>& ledger){
    double balance = -385.00; //fill in your membership cost here
    std::list<double>::const_iterator itr;
    for (itr = ledger.begin(); itr != ledger.end(); itr++){
        balance += *itr;
    }
    if (balance >= 0){
        std::cout << "\nMom was wrong.\n"; //fill in who you are trying to prove your point to here
    }
    return balance;
}

double avgScore(std::list<int>& scoreBook){
    std::list<int>::const_iterator itr;
    double total = 0;
    for (itr = scoreBook.begin(); itr != scoreBook.end(); itr++){
        total += *itr;
    }

    return total/scoreBook.size();
}

void rewrite(std::list<int>& scoreBook){
    std::ofstream out;
    out.open("scores.txt");

    std::list<int>::const_iterator itr;
    for (itr = scoreBook.begin(); itr != scoreBook.end(); itr++){
        out << *itr << "\n";
    }

}


int main(){
    double entry;
    std::list<double> ledger;
    std::ifstream in;
    in.open("data.txt");

    while (in >> entry){
        ledger.push_back(entry);
    }
    std::string str;
    bool weekday = false;
    int holes;

    std::cout << "if weekend type 'wend', otherwise type 'wd'.\n";
    std::cin >> str;
    if (str == "wd"){
        weekday = true;
    }

    std::cout << "\n9 holes or 18?\n";
    std::cin >> str;
    if (str == "9"){
        holes = 9;
    }
    else {
        holes = 18;
    }
    in.close();


    golf(ledger,weekday,holes);
    std::cout << "\nCurrent Balance: " << getBalance(ledger) << " Dollars.\n\n\nAdding this data to the ledger...\n\n";

    std::ofstream out;
    out.open("data.txt");
    
    std::list<double>::const_iterator itr;
    for (itr = ledger.begin(); itr != ledger.end(); itr++){
        out << *itr;
        out << "\n";
    }

    std::list<int> scoreBook;
    std::ifstream inScores;
    int strokes;
    inScores.open("scores.txt");
    while (inScores >> strokes){
        scoreBook.push_back(strokes);
    }
    inScores.close();

    int score;
    std::cout << "Enter your Score:\n";
    std::cin >> score;
    scoreBook.push_back(score);
    if (holes == 18){
        std::cout << "Enter your Score:\n";
        std::cin >> score;
        scoreBook.push_back(score);
    }


    std::cout << "\nAverage Score is now " << avgScore(scoreBook) << " strokes.\n\n";

    rewrite(scoreBook);



}