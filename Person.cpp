#include "Person.h"

Person::Person(){
    Questions setptr;
    ID = 0;
    Name = "Person";
    Set1 = setptr;
    Set2 = setptr;
    Set3 = setptr;
    Set4 = setptr;
    Set5 = setptr;
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
Person::~Person(){}

void Person::SetID(int id){
    ID = id;
}

void Person::SetName(string name){
    Name = name;
}

void Person::SetQuestionSet(int no, Questions& set){
    switch (no)
    {
        case 1:
            Set1 = set;
            break;
        case 2:
            Set2 = set;
            break;
        case 3:
            Set3 = set;
            break;
        case 4:
            Set4 = set;
            break;
        case 5:
            Set5 = set;
            break;
        default:
            cout<<"Hatalı numara girişi"<<endl;
            break;
    }
}

int Person::GetID(){
    return ID;
}

string Person::GetName(){
    return Name;
}

Questions& Person::GetQuestionSet(int no){
    switch (no)
    {
        case 1:
            return Set1;
            break;
        case 2:
            return Set2;
            break;
        case 3:
            return Set3;
            break;
        case 4:
            return Set4;
            break;
        case 5:
            return Set5;
            break;
        default:
        cout<<endl<<"Hatalı getquestion no"<<endl;
            return Set1;
            break;
    }
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
    int id = person1.GetID() + person2.GetID();
    string name = person1.GetName() + person2.GetName();
    Questions SET1 = person1.GetQuestionSet(1) + person2.GetQuestionSet(1);
    Questions SET2 = person1.GetQuestionSet(2) + person2.GetQuestionSet(2);
    Questions SET3 = person1.GetQuestionSet(3) + person2.GetQuestionSet(3);
    Questions SET4 = person1.GetQuestionSet(4) + person2.GetQuestionSet(4);
    Questions SET5 = person1.GetQuestionSet(5) + person2.GetQuestionSet(5);

    Person x(id,name,SET1,SET2,SET3,SET4,SET5);

    return x;
}