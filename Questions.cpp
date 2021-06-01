#include "Questions.h"

Questions::Questions(){
    //doldur
}

Questions::Questions(int id, string stry, string q1, string q2, string q3, string q4){
    //doldur
}

Questions::Questions(const Questions& other){
    //Doldur
}

Questions& Questions::operator = (const Questions& other){
    //doldur
}

Questions::~Questions(){
    cout<<ID<<" Questions class deleted"<<endl;
}

void Questions::SetID(int id){
    ID = id;
}

void Questions::SetStory(string stry){
    Story = stry;
}

void Questions::SetQuestion(int no, string q){
    // soru numarası ve ssoru girerek yapılacak else veya switc case kullan
}

int Questions::GetID(){
    return ID;
}

string Questions::GetStory(){
    return Story;
}

string Questions::GetQuestion(int no){
    // soru numarası girilerek soru alıacak esl if yapısı veya switc case kullan
}

ostream& operator << (ostream& os, const Questions que){
    //Doldur
}

Questions operator + (Questions q1, Questions q2){
    //Doldur
}

