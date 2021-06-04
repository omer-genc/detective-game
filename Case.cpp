#include "Case.h"

Case::Case(){
    Person prs;
    Detective dtc;

    ID = 0;
    Name = "Case";
    Story = "Story";
    Final = "Final";
    Person1 = prs;
    Detective1 = dtc;
}

Case::Case(int id, string name, string story, string final, Person person, Detective detective){
    ID = id;
    Name = name;
    Story = story;
    Final = final;
    Person1 = person;
    Detective1 = detective;
}
Case::Case(const Case& other){
    ID = other.ID;
    Name = other.Name;
    Story = other.Story;
    Final = other.Final;
    Person1 = other.Person1;
    Detective1 = other.Detective1;
}

Case& Case::operator = (const Case& other){
    ID = other.ID;
    Name = other.Name;
    Story = other.Story;
    Final = other.Final;
    Person1 = other.Person1;
    Detective1 = other.Detective1;
    return *this;
}
Case::~Case(){
    cout<<endl<<Name<<" Deleted"<<endl;
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
    Person1 = person;
}

void Case::SetDetective(Detective& detective){
    Detective1 = detective;
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
    return Person1;
}

Detective& Case::GetDedective(){
    return Detective1;
}

ostream& operator << (ostream& os, const Case _Case){
    os<<"Name: "<<_Case.Name<<
    endl<<"ID: "<<_Case.ID<<
    endl<<"Detective: "<<endl<<_Case.Detective1<<
    endl<<"Story: "<<_Case.Story<<
    endl<<"Final: "<<_Case.Final<<
    endl<<_Case.Detective1<<
    endl<<_Case.Person1<<endl;

}

Case operator + (Case _Case1, Case _Case2){
    int id = _Case1.GetID() + _Case2.GetID();
    string name = _Case1.GetName() + _Case2.GetName();
    string story = _Case2.GetStory() + _Case2.GetStory();
    string final = _Case1.GetFinal() + _Case2.GetFinal();
    Person person;
    Detective detective;
    Case x(id,name,story,final,person,detective);
    return x;

}