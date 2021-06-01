#ifndef DETECTIVE_H_
#define DETECTIVE_H_
#include<iostream>
using namespace std;

class Detective
{
    private:
        int ID;
        string Name;
    public:
        Detective();
        Detective(int id, string name);
        Detective(const Detective& other);
        Detective& operator = (const Detective& other);
        ~Detective();

        void SetID(int id);
        void SetName(string name);

        int GetID();
        string GetName();
};
ostream& operator << (ostream& os, const Detective& detec);
Detective operator + (Detective detec1, Detective detec2);


#endif