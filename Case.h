#ifndef CASE_H_
#define CASE_H_
#include "Questions.h"
#include "Person.h"
#include "Detective.h"
#include<fstream>
#include<string>
#include<cstring>

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

        void Play();


        //Dosyaya yazma işlemleri Uğur kılınç
        void Case_WriteToFile();    // Case hakkındaki tüm bilgileri ilgili dosyalara yazacak	
		


};
ostream& operator << (ostream& os, const Case _Case);
Case operator + (Case _Case1, Case _Case2);

void Devam();
void Cevap1(int c1, int c2, int c3, int c4);
void Cevap2(int c1, int c2, int c3, int c4);
void Cevap3(int c1, int c2, int c3, int c4);
void Cevap4(int c1, int c2, int c3, int c4);
void Cevap5(int c1, int c2, int c3, int c4);

#endif