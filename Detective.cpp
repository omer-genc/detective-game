#include "Detective.h"

Detective::Detective(){
    ID = 0;
    Name = "Default Detective";
}

Detective::Detective(int id, string name){
    // contructor

}

Detective::Detective(const Detective& other){
    // copy constructor


}

Detective& Detective::operator = (const Detective& other){
    //Assigment operator

}

Detective::~Detective(){
    cout<<Name<<" Detective deleted"<<endl;
}

void Detective::SetID(int id){
    ID = id;
}

void Detective::SetName(string name){
    Name = name;
}

int Detective::GetID(){
    return ID;
}

string Detective::GetName(){
    return Name;
}

ostream& operator << (ostream& os, const Detective& detec){
    //doldur burayı
}

Detective operator + (Detective detec1, Detective detec2){
    //doldur burayı
}