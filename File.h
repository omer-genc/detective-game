#ifndef FILE_H_
#define FILE_H_
#include "Case.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

string Case_Read_ID_Name();
int getCaseID();
string getCaseName();

string Case_Read_Story(string name);
string Case_Read_Final(string name);

string Case_Read_Detective(string name);
int getDetectiveID(string metin);
string getDetectiveName(string metin);

string Case_Read_Person(string name); 
int getPersonID(string metin);
string getPersonName(string metin);

string Case_Read_Set_Story(string name, int set_ID);
string Case_Read_Quesitons(string name, int q_ID);

void readCase(Case &senaryo);
#endif