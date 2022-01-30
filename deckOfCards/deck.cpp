#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

enum Suit{
    spade,
    heart,
    club,
    diamond
};

string conv(Suit s){
    switch(s){
        case spade: return "spade";
        case heart: return "heart";
        case club: return "club";
        case diamond: return "diamond";
    }
    return "";
}
class Card{
   public:
    int faceValue;
    string suit;
    Card(int faceValue, string suit){
        this->faceValue=faceValue;
        this->suit=suit;
    }
};

class Deck{
    public:
    vector<Card> cardDeck;
    Deck(){
    for(int suit=0;suit<4;suit++){
    for(int value=1;value<=13;value++){
        cardDeck.push_back(Card(value,conv((Suit)suit)));
    }
    }
    }

};

int main(){
Deck mydeck;
for(int i=0;i<mydeck.cardDeck.size();i++){
    cout<<mydeck.cardDeck[i].faceValue<<" "<<mydeck.cardDeck[i].suit<<endl;
}

return 0;
}