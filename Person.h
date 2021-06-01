#ifndef PERSON_H_
#define PERSON_H_
#include "Questions.h"

class Person{
    friend ostream& operator << (ostream& os, const Person person);
    private:
        int ID;
        string Name;
        Questions Set1;
        Questions Set2;
        Questions Set3;
        Questions Set4;
        Questions Set5;
    public:
        Person();
        Person(int id, string name,Questions set1, Questions set2, Questions set3, Questions set4, Questions set5);
        Person(const Person& other);
        Person& opeartor(const Person& other);
        ~Person();

        void SetID(int id);
        void SetName(string name);
        void SetQuestionSet(int no, Questions& set); // soru seti no girilerek yapılacak karar yapıları kullan

        int GetID();
        string GetName();
        Questions& GetQuestionSet(int no); //soru seti no girilerek yapılacak karar yapıları kullan
        
};
ostream& operator << (ostream& os, const Person person);
Person operator + (Person person1, Person person2);

#endif