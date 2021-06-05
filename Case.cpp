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
Case::~Case(){
    cout<<endl<<Name<<" Deleted"<<endl;
}

void Case::SetId(int id){
    ID = id;
}

void Case::SetName(string name){
    Name = name;
}

void Case::SetStory(string story){
    Story = story;
}

void Case::SetFinal(string final){
    Final = final;
}

void Case::SetPerson(Person& person){
    Person1 = person;
}

void Case::SetDetective(Detective& detective){
    Detective1 = detective;
}

int Case::GetID(){
    return ID;
}

string Case::GetName(){
    return Name;
}

string Case::GetStory(){
    return Story;
}

string Case::GetFinal(){
    return Final;
}

Person& Case::GetPerson(){
    return Person1;
}

Detective& Case::GetDedective(){
    return Detective1;
}

ostream& operator << (ostream& os, const Case _Case){
    os<<"Name: "<<_Case.Name<<
    endl<<"ID: "<<_Case.ID<<
    endl<<"Detective: "<<endl<<_Case.Detective1<<
    endl<<"Story: "<<_Case.Story<<
    endl<<"Final: "<<_Case.Final<<
    endl<<_Case.Detective1<<
    endl<<_Case.Person1<<endl;

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

//Dosyaya yazma işlemleri uğur kılınç
void Case::Case_WriteToFile(){  // dosyaya yazma fonksiyonları

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

void Case::Case_Read_ID_Name(string name,int case_ID){      // ID ve Name bilgisinı ekrana yazdıracak 
  ifstream dosyaOku("Case_name_list.dat");
  string satir = "";   char id[100];
  if ( dosyaOku.is_open() ){
    while ( getline(dosyaOku, satir) ){
 	  strcpy(id, satir.c_str());	  	   	   	     
	  if( id[0] == case_ID )
        cout << satir << endl;	      
	}
    dosyaOku.close();
  }
}

void Case::Case_Read_Story(string name){        // Story bilgisini ekrana yazdıracak 
  ifstream dosyaOku(name+"_story.dat");
  string satir = "";	
  if ( dosyaOku.is_open() ){	
    while ( getline(dosyaOku, satir) ){ cout << satir << endl; }
    dosyaOku.close();
  }   
}

void Case::Case_Read_Final(string name){        // Final bilgisini ekrana yazdıracak 
  ifstream dosyaOku(name+"_final.dat");
  string satir = "";	
  if ( dosyaOku.is_open() ){	
    while ( getline(dosyaOku, satir) ){ cout << satir << endl; }
    dosyaOku.close();
  }   
}

void Case::Case_Read_Person(string name){       // Person bilgilerini ekrana yazdıracak 
  ifstream dosyaOku(name+"_person.dat");
  string satir = "";	
  if ( dosyaOku.is_open() ){	
    while ( getline(dosyaOku, satir) ){ cout << satir << endl; }
    dosyaOku.close();
  }   
}

void Case::Case_Read_Set_Story(string name, int set_ID){   // Set numarasına göre setin story sini ekrana yazdıracak

    if(set_ID == 1)
    {
        ifstream dosyaOku(name+"_question_set1_story.dat");
        string satir = "";

        if ( dosyaOku.is_open() ){	
            while ( getline(dosyaOku, satir) ){ cout << satir << endl; }
            dosyaOku.close();
        }        
    }
    else if(set_ID == 2)
    {
        ifstream dosyaOku(name+"_question_set2_story.dat");
        string satir = "";	
        if ( dosyaOku.is_open() ){	
            while ( getline(dosyaOku, satir) ){ cout << satir << endl; }
            dosyaOku.close();
        }   
    }
    else if (set_ID == 3)
    {
        ifstream dosyaOku(name+"_question_set3_story.dat");
        string satir = "";	
        if ( dosyaOku.is_open() ){	
            while ( getline(dosyaOku, satir) ){ cout << satir << endl; }
            dosyaOku.close();
        }   
    }
    else if (set_ID == 4)
    {
        ifstream dosyaOku(name+"_question_set4_story.dat");
        string satir = "";	
        if ( dosyaOku.is_open() ){	
            while ( getline(dosyaOku, satir) ){ cout << satir << endl; }
            dosyaOku.close();
        }   
    }
    else if(set_ID == 5)
    {
        ifstream dosyaOku(name+"_question_set5_story.dat");
        string satir = "";	
        if ( dosyaOku.is_open() ){	
            while ( getline(dosyaOku, satir) ){ cout << satir << endl; }
            dosyaOku.close();
        }
    }
    else
        cout<<endl<<endl<<"Hatali set numarasi girdiniz!"<<endl<<endl;
}

void Case::Case_Read_Quesitons(string name, int q_ID){     // Soru numarasına göre(0 ise hepsini) soruyu ekrana yazdıracak
  int k=0;
  ifstream dosyaOku(name+"_quesitons.dat");
  string satir = "";
  if ( dosyaOku.is_open() ){
      while ( getline(dosyaOku, satir) ){
		k++;
    	if(k==q_ID)  cout << satir << endl;
		if(0==q_ID)  cout << satir << endl; 	  
    }
  }
    
    dosyaOku.close();
}

void Case::Case_Read_Detective(string name){    // Detektif bilgilerini ekrana yazdıracak
  ifstream dosyaOku(name+"_detective.dat");
  string satir = "";	
  if ( dosyaOku.is_open() ){	
    while ( getline(dosyaOku, satir) ){ cout << satir << endl; }
    dosyaOku.close();
  }   
}