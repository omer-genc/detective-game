#include "Questions.h"

Questions::Questions(){
    string BOS = "BOS";
    ID = 0;
    Story = Question1 = Question2 = Question3 = Question4 = BOS;

}

Questions::Questions(int id, string stry, string q1, string q2, string q3, string q4){
    ID = id;
    Story = stry;
    Question1 = q1;
    Question2 = q2;
    Question3 = q3;
    Question4 = q4;
}

Questions::Questions(const Questions& other){
    ID = other.ID;
    Story = other.Story;
    Question1 = other.Question1;
    Question2 = other.Question2;
    Question3 = other.Question3;
    Question4 = other.Question4;
}

Questions& Questions::operator = (const Questions& other){
    ID = other.ID;
    Story = other.Story;
    Question1 = other.Question1;
    Question2 = other.Question2;
    Question3 = other.Question3;
    Question4 = other.Question4;

    return *this;
}

Questions::~Questions(){}

void Questions::SetID(int id){
    ID = id;
}

void Questions::SetStory(string stry){
    Story = stry;
}

void Questions::SetQuestion(int no, string q){
    switch (no)
    {
    case 1:
        Question1 = q;
        break;
    case 2:
        Question2 = q;
        break;
    case 3:
        Question3 = q;
        break;
    case 4:
        Question4 = q;
        break;    
    default:
        cout<<endl<<endl<<"Hatalı soru numarası girdiniz"<<endl<<endl;
        break;
    }
    
}

int Questions::GetID(){
    return ID;
}

string Questions::GetStory(){
    return Story;
}

string Questions::GetQuestion(int no){
    switch (no)
    {
        case 1:
            return Question1;
            break;
        case 2:
            return Question2;
            break;
        case 3:
            return Question3;
            break;
        case 4:
            return Question4;
            break;    
        default:
            return "Hatalı soru numarası girdiniz";
            break;
    }
}

ostream& operator << (ostream& os, const Questions que){
    os<<"ID: "<<que.ID<<
    endl<<"Story: "<<que.Story<<
    endl<<"Q1: "<<que.Question1<<
    endl<<"Q2: "<<que.Question2<<
    endl<<"Q3: "<<que.Question3<<
    endl<<"Q4: "<<que.Question4<<endl;

    return os;
}

Questions operator + (Questions q1, Questions q2){
    int id = q1.GetID() + q2.GetID();
    string stry = q1.GetStory() + q1.GetStory();
    string Q1 = q1.GetQuestion(1) + q1.GetQuestion(1);  
    string Q2 = q1.GetQuestion(2) + q1.GetQuestion(2);  
    string Q3 = q1.GetQuestion(3) + q1.GetQuestion(3);  
    string Q4 = q1.GetQuestion(4) + q1.GetQuestion(4);  
    Questions q(id,stry,Q1,Q2,Q3,Q4);
    return q;
}

