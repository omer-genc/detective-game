#ifndef CASE_H_
#define CASE_H_
#include "Questions.h"
#include "Person.h"
#include "Detective.h"

class Case
{   friend ostream& operator << (ostream& os, const Case _Case);
    private:
        int ID;
        string Name;
        string Story;
        string Final;
        Person Person1;
        Detective Detective1;
    public:
        Case();
        Case(int id, string name, string story, string final, Person person, Detective detective);
        Case(const Case& other);
        Case& operator = (const Case& other);
        ~Case();

        void SetId(int id);
        void SetName(string name);
        void SetStory(string story);
        void SetFinal(string final);
        void SetPerson(Person& person);
        void SetDetective(Detective& detective);

        int GetID();
        string GetName();
        string GetStory();
        string GetFinal();
        Person& GetPerson(); 
        Detective& GetDedective(); 


};
ostream& operator << (ostream& os, const Case _Case);
Case operator + (Case _Case1, Case _Case2);


#endif