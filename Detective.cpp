#include "Detective.h"

Detective::Detective(){
    ID = 0;
    Name = "Default Detective";
}

Detective::Detective(int id, string name){
    Name = name;
    ID = id;
}

Detective::Detective(const Detective& other){
    Name = other.Name;
    ID = other.ID;
}

Detective& Detective::operator = (const Detective& other){
    Name = other.Name;
    ID = other.ID;
    return *this;
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

ostream& operator << (ostream& os,  const Detective detec){
    os<<"Name: "<<detec.Name<<endl<<"ID: "<<detec.ID;
    return os;
}

Detective operator + (Detective detec1, Detective detec2){
    string name = detec1.GetName() + detec2.GetName();
    int id = detec1.GetID() + detec2.GetID();
    Detective x(id,name);

    return x;
}