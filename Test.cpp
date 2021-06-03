#include "Test.h"

void TestDedective(){

    Detective d1;
    cout<<d1<<endl;

    Detective d2(1,"Ömer");
    cout<<d2<<endl;

    Detective d3(d2);
    cout<<d3<<endl;

    d1 = d2;
    cout<<d1<<endl;

    d1.SetID(100); d2.SetName("AAAAAA");

    cout<<d1.GetID()<<" "<<d1.GetName();
}

void TestQuestions(){
    Questions q1;
    cout<<q1<<endl;

    Questions q2(1,"hikaye","soru","soru","soru","soru");
    cout<<q2<<endl;

    Questions q3(q2);
    cout<<q3<<endl;

    q1 = q2;
    cout<<q1<<endl;

    q1 = q2 + q3;
    cout<<q1<<endl;

    q1.SetID(2);
    q1.SetStory("aaaa");
    q1.SetQuestion(1,"1");
    q1.SetQuestion(2,"2");
    q1.SetQuestion(3,"3");
    q1.SetQuestion(4,"4");
    cout<<q1<<endl;

    cout<<q1.GetID()<<
    endl<<q1.GetStory()<<
    endl<<q1.GetQuestion(1)<<
    endl<<q1.GetQuestion(2)<<
    endl<<q1.GetQuestion(3)<<
    endl<<q1.GetQuestion(4)<<endl;

}

void TestPerson(){
    Person p1();
    cout<<p1;
}
