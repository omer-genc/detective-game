#include "Case.h"

Case::Case(){
    Person prs;
    Detective dtc;

    ID = 0;
    Name = "Case";
    Story = "Story";
    Final = "Final";
    Person1 = prs;
    Detective1 = dtc;
}

Case::Case(int id, string name, string story, string final, Person person, Detective detective){
    ID = id;
    Name = name;
    Story = story;
    Final = final;
    Person1 = person;
    Detective1 = detective;
}

Case::Case(const Case& other){
    ID = other.ID;
    Name = other.Name;
    Story = other.Story;
    Final = other.Final;
    Person1 = other.Person1;
    Detective1 = other.Detective1;
}

Case& Case::operator = (const Case& other){
    ID = other.ID;
    Name = other.Name;
    Story = other.Story;
    Final = other.Final;
    Person1 = other.Person1;
    Detective1 = other.Detective1;
    return *this;
}

Case::~Case(){}

void Case::SetId(int id){ID = id;}

void Case::SetName(string name){Name = name;}

void Case::SetStory(string story){Story = story;}

void Case::SetFinal(string final){Final = final;}

void Case::SetPerson(Person& person){Person1 = person;}

void Case::SetDetective(Detective& detective){Detective1 = detective;}

int Case::GetID(){return ID;}

string Case::GetName(){return Name;}

string Case::GetStory(){return Story;}

string Case::GetFinal(){return Final;}

Person& Case::GetPerson(){return Person1;}

Detective& Case::GetDedective(){return Detective1;}

ostream& operator << (ostream& os, const Case _Case){
    os<<"Name: "<<_Case.Name<<
    endl<<"ID: "<<_Case.ID<<
    endl<<"Detective: "<<endl<<_Case.Detective1<<
    endl<<"Story: "<<_Case.Story<<
    endl<<"Final: "<<_Case.Final<<
    endl<<_Case.Detective1<<
    endl<<_Case.Person1<<endl;

    return os;

}

Case operator + (Case _Case1, Case _Case2){
    int id = _Case1.GetID() + _Case2.GetID();
    string name = _Case1.GetName() + _Case2.GetName();
    string story = _Case2.GetStory() + _Case2.GetStory();
    string final = _Case1.GetFinal() + _Case2.GetFinal();
    Person person;
    Detective detective;
    Case x(id,name,story,final,person,detective);
    return x;

}

void Case::Play(){
    cout<<Story<<endl;
    Devam();
    int puan = 0;

    // Soru soruluyor
    string secim;
    cout<<"1. "<<Person1.GetQuestionSet(1).GetQuestion(1)<<
    endl<<"2. "<<Person1.GetQuestionSet(1).GetQuestion(2)<<
    endl<<"3. "<<Person1.GetQuestionSet(1).GetQuestion(3)<<
    endl<<"4. "<<Person1.GetQuestionSet(1).GetQuestion(4)<<endl;
    Cevap1(1,1,0,1);
    cout<<Person1.GetQuestionSet(1).GetStory()<<endl;
    Devam();

    // set2 soruları
    cout<<"1. "<<Person1.GetQuestionSet(2).GetQuestion(1)<<
    endl<<"2. "<<Person1.GetQuestionSet(2).GetQuestion(2)<<
    endl<<"3. "<<Person1.GetQuestionSet(2).GetQuestion(3)<<
    endl<<"4. "<<Person1.GetQuestionSet(2).GetQuestion(4)<<endl;
    Cevap2(1,0,0,1);
    cout<<Person1.GetQuestionSet(2).GetStory()<<endl;
    Devam();

    //set3 soruları
    cout<<"1. "<<Person1.GetQuestionSet(3).GetQuestion(1)<<
    endl<<"2. "<<Person1.GetQuestionSet(3).GetQuestion(2)<<
    endl<<"3. "<<Person1.GetQuestionSet(3).GetQuestion(3)<<
    endl<<"4. "<<Person1.GetQuestionSet(3).GetQuestion(4)<<endl;
    Cevap3(0,0,1,1);
    cout<<Person1.GetQuestionSet(3).GetStory()<<endl;
    Devam();

    //set4 soruları
    cout<<"1. "<<Person1.GetQuestionSet(4).GetQuestion(1)<<
    endl<<"2. "<<Person1.GetQuestionSet(4).GetQuestion(2)<<
    endl<<"3. "<<Person1.GetQuestionSet(4).GetQuestion(3)<<
    endl<<"4. "<<Person1.GetQuestionSet(4).GetQuestion(4)<<endl;
    Cevap4(1,0,1,1);
    cout<<Person1.GetQuestionSet(4).GetStory()<<endl;
    Devam();

    //set5 soruları
    cout<<"1. "<<Person1.GetQuestionSet(5).GetQuestion(1)<<
    endl<<"2. "<<Person1.GetQuestionSet(5).GetQuestion(2)<<
    endl<<"3. "<<Person1.GetQuestionSet(5).GetQuestion(3)<<
    endl<<"4. "<<Person1.GetQuestionSet(5).GetQuestion(4)<<endl;
    Cevap5(1,1,1,1);
    cout<<Person1.GetQuestionSet(5).GetStory()<<endl;
    Devam();

    cout<<Final;
   
}   

void Devam(){
    string devam;
    cout<<"devam etmek icin herhangi bir deger giriniz....";
    cin>>devam;
}

void Cevap1(int c1, int c2, int c3, int c4)
{
    string C1 = "Evet",C2 = "Evet",C3 = "Evet",C4 = "Evet";
    int puan = 0;
    string secim;

    if(c1 == 0)
        C1 = "Hayır";
    if(c2 == 0)
        C2 = "Hayır";
    if(c3 == 0)
        C3 = "Hayır";
    if(c4 == 0)
        C4 = "Hayır";

    while (puan < 4)
    {
        cout<<"Lutfen soru seciniz: ";
        cin>>secim;

        if(secim =="1"){
            cout<<C1<<endl;
            puan++; 
        }
        else if(secim =="2"){
            cout<<C2<<endl; 
        }
        else if(secim =="3"){
            cout<<C3<<endl; 
            puan++;
        }
        else if(secim =="4"){
            cout<<C4<<endl;
            puan++;
        }
        else 
            cout<<"Hatalı secim.. "<<endl;
    }
}

void Cevap2(int c1, int c2, int c3, int c4)
{
    string C1 = "Evet",C2 = "Evet",C3 = "Evet",C4 = "Evet";
    int puan = 0;
    string secim;

    if(c1 == 0)
        C1 = "Hayır";
    if(c2 == 0)
        C2 = "Hayır";
    if(c3 == 0)
        C3 = "Hayır";
    if(c4 == 0)
        C4 = "Hayır";

    while (puan < 3)
    {
        cout<<"Lutfen soru seciniz: ";
        cin>>secim;

        if(secim =="1"){
            cout<<C1<<endl;
            puan++;
        }
        else if(secim =="2"){
            cout<<C2<<endl; 
            
        }

        else if(secim =="3"){
            cout<<C3<<endl; 
            puan++;

        }

        else if(secim =="4"){
            cout<<C4<<endl; 
            puan++;

        }
        else 
            cout<<"Hatalı seçim.."<<endl;
    }
}

void Cevap3(int c1, int c2, int c3, int c4)
{
    string C1 = "Evet",C2 = "Evet",C3 = "Evet",C4 = "Evet";
    int puan = 0;
    string secim;

    if(c1 == 0)
        C1 = "Hayır";
    if(c2 == 0)
        C2 = "Hayır";
    if(c3 == 0)
        C3 = "Hayır";
    if(c4 == 0)
        C4 = "Hayır";

    while (puan < 3)
    {
        cout<<"Lutfen soru seciniz: ";
        cin>>secim;

        if(secim =="1"){
            cout<<C1<<endl; 
            puan++;
        }
        else if(secim =="2"){
            cout<<C2<<endl; 
            
        }
        else if(secim =="3"){
            cout<<C3<<endl;
            puan++;
        } 
        else if(secim =="4"){
            cout<<C4<<endl; 
            puan++;
        }
        else 
            cout<<"Hatalı seçim.."<<endl;
    }
}

void Cevap4(int c1, int c2, int c3, int c4)
{
    string C1 = "Evet",C2 = "Evet",C3 = "Evet",C4 = "Evet";
    int puan = 0;
    string secim;

    if(c1 == 0)
        C1 = "Hayır";
    if(c2 == 0)
        C2 = "Hayır";
    if(c3 == 0)
        C3 = "Hayır";
    if(c4 == 0)
        C4 = "Hayır";

    while (puan < 4)
    {
        cout<<"Lutfen soru seciniz: ";
        cin>>secim;

        if(secim =="1"){
            cout<<C1<<endl; 
            puan++;
        }
        else if(secim =="2"){
            cout<<C2<<endl; 
            puan++;
        }
        else if(secim =="3"){
            cout<<C3<<endl; 
            puan++;
        }
        else if(secim =="4"){
            cout<<C4<<endl; 
            puan++;
        }
        else    
            cout<<"Hatalı giriş..."<<endl;
    }
}

void Cevap5(int c1, int c2, int c3, int c4)
{
    string C1 = "Evet",C2 = "Evet",C3 = "Evet",C4 = "Evet";
    int puan = 0;
    string secim;

    if(c1 == 0)
        C1 = "Hayır";
    if(c2 == 0)
        C2 = "Hayır";
    if(c3 == 0)
        C3 = "Hayır";
    if(c4 == 0)
        C4 = "Hayır";

    while (puan < 3)
    {
        cout<<"Lutfen soru seciniz: ";
        cin>>secim;

        if(secim =="1"){
            cout<<C1<<endl;
            puan++;
        } 
        else if(secim =="2"){
            cout<<C2<<endl; 
            puan++;
        }
        else if(secim =="3"){
            cout<<C3<<endl; 
            puan++;
        }
        else if(secim =="4"){
            cout<<C4<<endl; 
            
        }
        else 
            cout<<"Hatalı seçim.."<<endl;
    }
}


void Case::Case_WriteToFile(){

    //  Case_name_list   -> ID ve Name
    ofstream Case_Write_ID_Name("Case_name_list.dat",ios::app);
    Case_Write_ID_Name<<ID<<"_"<<Name<<endl;

    //  XXX_story   -> Story
    ofstream Case_Write_Story( Name+"_story.dat",ios::app);
    Case_Write_Story<<Story<<endl;

    //  XXX_final   -> Final
    ofstream Case_Write_Final( Name+"_final.dat",ios::app);
    Case_Write_Final<<Final<<endl;

    //  XXX_person   -> Person
    ofstream Case_Write_Person( Name+"_person.dat",ios::app);           // vakaya ait personun ıd ve name için bir txt dosyası oluşturuldu
    Case_Write_Person<<Person1.GetID()<<"_"<<Person1.GetName()<<endl;
    
    // soru setlerinin story leri için txt dosylarının oluşturulması 
    ofstream Set1_Story( Name+"_question_set1_story.dat",ios::app);     // Case->Person->Set1->story için txt oluşturuldu
    Set1_Story<<Person1.GetQuestionSet(1).GetStory()<<endl;
    
    ofstream Set2_Story( Name+"_question_set2_story.dat",ios::app);     // Case->Person->Set2->story için txt oluşturuldu
    Set2_Story<<Person1.GetQuestionSet(2).GetStory()<<endl;
    
    ofstream Set3_Story( Name+"_question_set3_story.dat",ios::app);     // Case->Person->Set3->story için txt oluşturuldu
    Set3_Story<<Person1.GetQuestionSet(3).GetStory()<<endl;
    
    ofstream Set4_Story( Name+"_question_set4_story.dat",ios::app);     // Case->Person->Set4->story için txt oluşturuldu
    Set4_Story<<Person1.GetQuestionSet(4).GetStory()<<endl;
    
    ofstream Set5_Story( Name+"_question_set5_story.dat",ios::app);     // Case->Person->Set5->story için txt oluşturuldu
    Set5_Story<<Person1.GetQuestionSet(5).GetStory()<<endl;       
    
    
    //tüm soruların tek bir txt dosyasına yazılması
    ofstream all_question( Name+"_quesitons.dat",ios::app);     // Case->Person->Set5->story için txt oluşturuldu
    for(int set=1; set<6; set++){
        for(int q=1; q<5; q++){
        all_question<<Person1.GetQuestionSet(set).GetQuestion(q)<<endl;			
        }
    }
    
    // dosyaya yazma : XXX_detective   -> Person
    ofstream Case_Write_Detective( Name+"_detective.dat",ios::app);
    Case_Write_Detective<<Detective1.GetID()<<"_"<<Detective1.GetName()<<endl;   // arada _ var istersen boşluk yapabilirsin sana bırakıyorum
 		
}

void caseDuzenle(Case &Senaryo){
    string caseName;
    int caseID;

    cout<<"Senaryo ismi gir: ";
    cin>>caseName;
    cout<<"Senaryo ID gir: ";
    cin>>caseID;
    
    Senaryo.SetName(caseName);
    Senaryo.SetId(caseID);

    string caseStory;
    string caseFinal;

    cout<<"Senaryo hikayesi gir: ";
    cin>>caseStory;
    cout<<"Senaryo finali gir: ";
    cin>>caseFinal;

    Senaryo.SetStory(caseStory);
    Senaryo.SetFinal(caseFinal);

    
    string detectiveName;
    int detectiveID;
    cout<<"Dedektif ismi gir: ";
    cin>>detectiveName;
    cout<<"Dedektif ID gir: ";
    cin>>detectiveID;

    //Detektif eklendi
    Detective other(detectiveID,detectiveName);
    Senaryo.SetDetective(other);

    //Questions story okuma
    
    string questionStory1;
    string questionStory2;
    string questionStory3;
    string questionStory4;
    string questionStory5;

    cout<<"Soru seti 1 için story gir";
    cin>>questionStory1;
    cout<<"Soru seti 2 için story gir";
    cin>>questionStory2;
    cout<<"Soru seti 3 için story gir";
    cin>>questionStory3;
    cout<<"Soru seti 4 için story gir";
    cin>>questionStory4;
    cout<<"Soru seti 5 için story gir";
    cin>>questionStory5;
    

    Questions set1;
    Questions set2;
    Questions set3;
    Questions set4;
    Questions set5;

    //Soru seti id leri girildi
    set1.SetID(1);
    set2.SetID(2);
    set3.SetID(3);
    set4.SetID(4);
    set5.SetID(5);

    //soru seti storyleri girildi
    set1.SetStory(questionStory1);
    set2.SetStory(questionStory2);
    set3.SetStory(questionStory3);
    set4.SetStory(questionStory4);

    //soru setlerine sorular girildi
    string soru;
    cout<<"Soru seti 1"<<endl;
    for (int i = 1; i < 5; i++)
    {
        cout<<"Soru " << i << " giriniz: ";
        cin>>soru;
        set1.SetQuestion(i,soru);
    }

    cout<<"Soru seti 2"<<endl;
    for (int i = 1; i < 5; i++)
    {
        cout<<"Soru " << i << " giriniz: ";
        cin>>soru;
        set2.SetQuestion(i,soru);
    }

    cout<<"Soru seti 3"<<endl;
    for (int i = 1; i < 5; i++)
    {
        cout<<"Soru " << i << " giriniz: ";
        cin>>soru;
        set3.SetQuestion(i,soru);
    }

    cout<<"Soru seti 4"<<endl;
    for (int i = 1; i < 5; i++)
    {
        cout<<"Soru " << i << " giriniz: ";
        cin>>soru;
        set4.SetQuestion(i,soru);
    }

    cout<<"Soru seti 5"<<endl;
    for (int i = 1; i < 5; i++)
    {
        cout<<"Soru " << i << " giriniz: ";
        cin>>soru;
        set5.SetQuestion(i,soru);
    }
    

    string personName;
    int personID;
    Person person;
    cout<<"Person ID gir: ";
    cin>>personID;
    cout<<"Person Name gir: ";
    cin>>personName;

    //Person verileri girildi
    person.SetID(personID);
    person.SetName(personName);
    //persona sorular eklendi
    person.SetQuestionSet(1,set1);
    person.SetQuestionSet(2,set2);
    person.SetQuestionSet(3,set3);
    person.SetQuestionSet(4,set4);
    person.SetQuestionSet(5,set5);

    // person eklendi
    Senaryo.SetPerson(person);
}
