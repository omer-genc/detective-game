#ifndef CASE_H_
#define CASE_H_
#include "Questions.h"
#include "Person.h"
#include "Detective.h"

class Case
{   friend ostream& operator << (ostream& os, const Detective detective);
    private:
        int ID;
        string Name;
        string Story;
        Person Person1;
        Person Person2;
        Detective Detective1;
        Detective Detective2;
    public:
        Case();
        Case(int id, string name, string story, Person person1, Person person2, Detective detective1, Detective detective2);
        Case(const Case& other);
        Case& Operator(const Case& other);
        ~Case();

        void SetId(int id);
        void SetName(string name);
        void SetStory(string story);
        void SetPerson(int no, Person& person); // karar yapıları kullannarak yaz örnek no 1 olduğunda person1 de değişiklik yap
        void SetDetective(int no, Detective& detective);

        int GetID();
        string GetName();
        string GetStory();
        Person& GetPerson(int no); //karar yapıları kullanarak yaz
        Detective& GetDedective(int no); // karar yapıları kullanarak yaz


};
ostream& operator << (ostream& os, const Detective detective);
Detective operator + (Detective detective1, Detective detective2);


#endif