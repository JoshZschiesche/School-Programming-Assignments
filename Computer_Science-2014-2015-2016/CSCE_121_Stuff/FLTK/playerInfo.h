struct playerInfo
{
    string playerName;
    int playerScore;
    bool operator() (playerInfo i, playerInfo j) 
    {
        return (i.playerScore > j.playerScore);
    }
} player;
