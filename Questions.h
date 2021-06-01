#ifndef QUESTIONS_H_
#define QUESTIONS_H_
#include<iostream>
using namespace std;

class Questions
{   friend ostream& operator << (ostream& os, const Questions que);
    private:
        int ID;
        string Story;
        string Question1;
        string Question2;
        string Question3;
        string Question4;
    public:
        Questions();
        Questions(int id, string stry, string q1, string q2, string q3, string q4);
        Questions(const Questions& other);
        Questions& operator = (const Questions& other);
        ~Questions();

        void SetID(int id);
        void SetStory(string stry);
        void SetQuestion(int no, string q);// soru numarası ve ssoru girerek yapılacak else veya switc case kullan

        int GetID();
        string GetStory();
        string GetQuestion(int no); // soru numarası girilerek soru alıacak esl if yapısı veya switc case kullan

};
ostream& operator << (ostream& os, const Questions que);
Questions operator + (Questions q1, Questions q2);

#endif