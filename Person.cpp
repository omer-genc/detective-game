#include "Person.h"

Person::Person(){
    ID = 0;
    Name = "Default";
}

Person::Person(int id, string name,Questions set1, Questions set2, Questions set3, Questions set4, Questions set5){
    ID = id;
    Name = name;
    Set1 = set1;
    Set2 = set2;
    Set3 = set3;
    Set4 = set4;
    Set5 = set5;
}

Person::Person(const Person& other){
    ID = other.ID;
    Name = other.Name;
    Set1 = other.Set1;
    Set2 = other.Set2;
    Set3 = other.Set3;
    Set4 = other.Set4;
    Set5 = other.Set5;
}

Person& Person::operator = (const Person& other){
    ID = other.ID;
    Name = other.Name;
    Set1 = other.Set1;
    Set2 = other.Set2;
    Set3 = other.Set3;
    Set4 = other.Set4;
    Set5 = other.Set5;
    return *this;
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
    os<<"ID: "<<person.ID<<
    endl<<"Name: "<<person.Name<<
    endl<<"set 1: "<<endl<<person.Set1<<
    endl<<"set 2: "<<endl<<person.Set2<<
    endl<<"set 3: "<<endl<<person.Set3<<
    endl<<"set 4: "<<endl<<person.Set4<<
    endl<<"set 5: "<<endl<<person.Set5<<endl;
    return os;
}

Person operator + (Person person1, Person person2){
    //doldur
}