#include "Person.h"

Person::Person(){
    //doldur
}

Person::Person(int id, string name,Questions set1, Questions set2, Questions set3, Questions set4, Questions set5){
    //doldur
}

Person::Person(const Person& other){
    //doldur
}

Person& Person::opeartor(const Person& other){
    //doldur
}
Person::~Person(){
    cout<<Name<<" Person deleted"<<endl;
}

void Person::SetID(int id){
    ID = id;
}

void Person::SetName(string name){
    Name = name;
}

void Person::SetQuestionSet(int no, Questions& set){
    // soru seti no girilerek yapılacak karar yapıları kullan
}

int Person::GetID(){
    return ID;
}

string Person::GetName(){
    return Name;
}

Questions& GetQuestionSet(int no) {
    //soru seti no girilerek yapılacak karar yapıları kullan
}

ostream& operator << (ostream& os, const Person person){
    //doldur
}

Person operator + (Person person1, Person person2){
    //doldur
}