#include "std_lib_facilities.h"

struct playerInfo
{
    string playerName;
    int playerScore;
    
    bool operator() (playerInfo i, playerInfo j) {
        return (i.playerScore > j.playerScore);
    }
} player;

int main(){
    
    fstream scores;
    scores.open("Scores.txt");
    
    playerInfo newPlayer;
    
    Vector<playerInfo> HighscoreTable (5);
    
    cout << "Please enter new Player's name: ";
    cin >> newPlayer.playerName;
    cout << "Please enter new Player's Score: ";
    cin >> newPlayer.playerScore;
    
    for (int i = 0; HighscoreTable.size() > i; i++) {
        scores >> HighscoreTable[i].playerName >> HighscoreTable[i].playerScore;
    }
    
    scores.close();
    
    HighscoreTable.push_back(newPlayer);
    
    sort(HighscoreTable.begin(), HighscoreTable.end(), player);
    
    scores.open("Scores.txt", ios::trunc | ios::out);
    
    for (int i = 0; HighscoreTable.size()-1 > i; i++) {
        scores << HighscoreTable[i].playerName;
        scores << " ";
        scores << HighscoreTable[i].playerScore;
        scores << endl;
    }
    
    scores.close();

}