#ifndef CASE_H_
#define CASE_H_
#include "Questions.h"
#include "Person.h"
#include "Detective.h"
#include<fstream>
#include<string>

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


        //Dosyaya yazma işlemleri Uğur kılınç
        void Case_WriteToFile();    // Case hakkındaki tüm bilgileri ilgili dosyalara yazacak	
		void Case_Read_ID_Name(string name,int case_ID);      // ID ve Name bilgisinı ekrana yazdıracak 
		void Case_Read_Story(string name);        // Story bilgisini ekrana yazdıracak 
		void Case_Read_Final(string name);        // Final bilgisini ekrana yazdıracak 
		void Case_Read_Person(string name);       // Person bilgilerini ekrana yazdıracak 
		void Case_Read_Set_Story(string name, int set_ID);   // Set numarasına göre setin story sini ekrana yazdıracak
		void Case_Read_Quesitons(string name, int q_ID);     // Soru numarasına göre (0 a hepsini) soruyu ekrana yazdıracak
		void Case_Read_Detective(string name);    // Detektif bilgilerini ekrana yazdıracak


};
ostream& operator << (ostream& os, const Case _Case);
Case operator + (Case _Case1, Case _Case2);


#endif