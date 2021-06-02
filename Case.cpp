#include "Case.h"

Case::Case(){
    //doldur
}

Case::Case(int id, string name, string story, string final, Person person1, Detective detective1, Detective detective2){
    //doldur
}
Case::Case(const Case& other){
    //doldur
}
Case& Case::Operator(const Case& other){
    //doldur
}
Case::~Case(){
    //doldur
}

void Case::SetId(int id){
    ID = id;
}

void Case::SetName(string name){
    Name = name;
}

void Case::SetStory(string story){
    Story = story;
}

void Case::SetFinal(string final){
    Final = final;
}

void Case::SetPerson(Person& person){
    
}

void Case::SetDetective(Detective& detective){
    //doldur
}

int Case::GetID(){
    return ID;
}

string Case::GetName(){
    return Name;
}

string Case::GetStory(){
    return Story;
}

string Case::GetFinal(){
    return Final;
}

Person& Case::GetPerson(){
    //doldur
}

Detective& Case::GetDedective(){
    // doldur
}

ostream& operator << (ostream& os, const Case _Case){
    //doldur
}

Case operator + (Case _Case1, Case _Case2){
    //doldur
}