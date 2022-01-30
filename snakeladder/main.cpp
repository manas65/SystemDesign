#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Dice{
    public:
int numOfDice;
Dice(){}
Dice(int numOfDice){
    this->numOfDice=numOfDice;
}
int roll(){
 return rand()%(numOfDice*6)-1*(numOfDice);//2 dice toh min =2(1*2) max =12(2*6)   
}
};

class Player{
    public:
    string Name;
    int ID;

    Player(string Name,int ID){
       this->Name=Name;
       this->ID=ID; 
    }
};

class changePos{
    public:
    int startpos;
    int endpos;
    changePos(){}
    changePos(int startpos,int endpos){
        this->startpos=startpos;
        this->endpos=endpos;
    }
};

class gameBoard{
public:
    int boardSize;
    queue<Player> turn;
    unordered_map<int,changePos> snakes;
    unordered_map<int,changePos> ladders;
    Dice dice;
    unordered_map<string,int> playerpos;

        gameBoard(int boardSize,queue<Player> turn,vector<changePos> snakes,vector<changePos> ladders,Dice dice,unordered_map<string,int> playerpos){
            this->boardSize=boardSize;
            this->turn=turn;
            for(changePos pos:snakes)this->snakes[pos.startpos]=pos;
            for(changePos pos:ladders)this->ladders[pos.startpos]=pos;
            this->dice=dice;
            this->playerpos=playerpos;
        }
    void startGame(){
        
        while(turn.size()>1){//atleast 1 player should be in the queue
        Player currPlayer=turn.front();
        turn.pop();
        int currPos=playerpos[currPlayer.Name];
        int diceValue=dice.roll();
        cout<<currPlayer.Name<<" dicevalue "<<diceValue<<endl;
        int nextPos=currPos+diceValue;
        //player reaches the end
            if(nextPos==boardSize)cout<<currPlayer.Name<<" won"<<endl;
            else if(nextPos>boardSize)turn.push(currPlayer);
            else{
                //if next pos is snake
                if(snakes.find(nextPos)!=snakes.end())
                {
                    nextPos=snakes[nextPos].endpos;
                    cout<<currPlayer.Name<<" got bit by snake"<<endl;  
                    playerpos[currPlayer.Name]=nextPos;  
                }
                else if(ladders.find(nextPos)!=ladders.end())
                {
                    nextPos=ladders[nextPos].endpos;
                    cout<<currPlayer.Name<<" climbed a ladder"<<endl;
                    playerpos[currPlayer.Name]=nextPos;    
                }
                else {
                     playerpos[currPlayer.Name]=nextPos; 
                }
                 if(nextPos==boardSize)cout<<currPlayer.Name<<" won"<<endl;
                 else{
                     cout<<currPlayer.Name<<" : "<< nextPos<<endl;
                    turn.push(currPlayer);
                 }   
            }

        }
        cout<<"gamefinished"<<endl;
    }
};

int main(){
    Dice dice(3);
    Player p1("Ram",1);
    Player p2("Sham",2);
    Player p3("tony",3);
    queue<Player>turn;
    turn.push(p1);
    turn.push(p2);
    turn.push(p3);
    vector<changePos>snake={{5,1},{10,2},{11,3}};
    vector<changePos>ladder={{3,14},{12,18},{7,20}};
    unordered_map<string,int> playerpos;
    playerpos[p1.Name]=0;
    playerpos[p2.Name]=8;
    playerpos[p3.Name]=1;
        gameBoard snakeladder(100,turn,snake,ladder,dice,playerpos);

    snakeladder.startGame();
    return 0;




}




