#include "Case.h"

Case::Case(){
    //doldur
}

Case::Case(int id, string name, string story, Person person1, Person person2, Detective detective1, Detective detective2){
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

void Case::SetPerson(int no, Person& person){
    // karar yapıları kullannarak yaz örnek no 1 olduğunda person1 de değişiklik yap
}

void Case::SetDetective(int no, Detective& detective){
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

Person& Case::GetPerson(int no){
    //karar yapıları kullanarak yaz
}

Detective& Case::GetDedective(int no){
    // karar yapıları kullanarak yaz
}

ostream& operator << (ostream& os, const Detective detective){
    //doldur
}

Detective operator + (Detective detective1, Detective detective2){
    //doldur
}