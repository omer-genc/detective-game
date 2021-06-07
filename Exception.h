#ifndef Exception_h
#define Exception_h

#include <iostream>
#include <string>
using namespace std;

class Exception{
public:
	Exception(string err_message){
	 message = err_message;
	}
	
	string getMessage(){ 
	 message = "Hata! Girilen deger "+ message;
	 return message;
	 }
private:
	string message;	 
};

#endif
