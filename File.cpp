#include "File.h"

string Case_Read_ID_Name(){ 
    char ID;
    string x;
    ifstream dosyaOku("Case_name_list.dat");
    string satir = "";	
    if ( dosyaOku.is_open() ){	
        while ( getline(dosyaOku, satir) )
            cout << satir << endl; 
        
        dosyaOku.close();
    } 
    cout<<"Senaryo secmek icin ID giriniz: ";
    
    cin>>ID;
    ifstream dosyaOku2("Case_name_list.dat");
    satir = "";
    char id[100];

    if ( dosyaOku2.is_open() )
    {
        while ( getline(dosyaOku2, satir) ){
            strcpy(id, satir.c_str());	  
                    
            if( id[0] == ID )
                x= satir;

        }
        dosyaOku2.close();
    }
    return x;
}

int getCaseID(string metin){
    string s = metin;
    string delimiter = "_";
    string token = s.substr(0,s.find(delimiter));

    return atoi(token.c_str());
}

string getCaseName(string metin){
    string delimiter = "_";
    string x = metin.erase(0, metin.find(delimiter) + delimiter.length());
    return x;
}


string Case_Read_Story(string name){        // Story bilgisini ekrana yazdıracak 
    ifstream dosyaOku(name+"_story.dat");
    string satir = "";	
    if ( dosyaOku.is_open() )
        getline(dosyaOku, satir);
    
    dosyaOku.close();
    return satir; 
}

string Case_Read_Final(string name){
    ifstream dosyaOku(name+"_final.dat");
    string satir = "";	
    if ( dosyaOku.is_open() )
        getline(dosyaOku, satir);
    
    dosyaOku.close();
    return satir;
}


string Case_Read_Detective(string name){
    ifstream dosyaOku(name+"_detective.dat");
    string satir = "";	
    if ( dosyaOku.is_open() )
        getline(dosyaOku, satir);
    
    dosyaOku.close();
    return satir;
}

int getDetectiveID(string metin){
    string s = metin;
    string delimiter = "_";
    string token = s.substr(0,s.find(delimiter));

    return atoi(token.c_str());
}

string getDetectiveName(string metin){
    string delimiter = "_";
    string x = metin.erase(0, metin.find(delimiter) + delimiter.length());
    return x;
}


string Case_Read_Person(string name){
    ifstream dosyaOku(name+"_person.dat");
    string satir = "";	
    if ( dosyaOku.is_open() )
        getline(dosyaOku, satir);
    
    dosyaOku.close();
    return satir; 
}

int getPersonID(string metin){
    char arry[100];
    strcpy(arry,metin.c_str());
    return arry[0] - '0';
}

string getPersonName(string metin){
    char arry[100];
    int i = 2;
    string name;
    strcpy(arry,metin.c_str());
    
    while (arry[i] != '\0')
    {
        name += arry[i];
        i++;
    }

    return name;
}


string Case_Read_Set_Story(string name, int set_ID){

    string donder;
    if(set_ID == 1)
    {
        ifstream dosyaOku(name+"_question_set1_story.dat");
        string satir = "";

        if ( dosyaOku.is_open() )	
            getline(dosyaOku, satir);
        donder = satir;
        dosyaOku.close();
          
    }
    else if(set_ID == 2)
    {
        ifstream dosyaOku(name+"_question_set2_story.dat");
        string satir = "";

        if ( dosyaOku.is_open() )	
            getline(dosyaOku, satir);
        donder = satir;
        dosyaOku.close();   
    }
    else if (set_ID == 3)
    {
        ifstream dosyaOku(name+"_question_set3_story.dat");
        string satir = "";	
        	
        if ( dosyaOku.is_open() )	
            getline(dosyaOku, satir);
        donder = satir;
        dosyaOku.close();   
    }
    else if (set_ID == 4)
    {
        ifstream dosyaOku(name+"_question_set4_story.dat");
        string satir = "";	
        	
        if ( dosyaOku.is_open() )	
            getline(dosyaOku, satir);
        donder = satir;
        dosyaOku.close();   
    }
    else if(set_ID == 5)
    {
        ifstream dosyaOku(name+"_question_set5_story.dat");
        string satir = "";	
        	
        if ( dosyaOku.is_open() )	
            getline(dosyaOku, satir);
        donder = satir;
        dosyaOku.close();
    }
    else
        donder = "Hata";
    
    return donder;
}

string Case_Read_Quesitons(const string name, int q_ID){
    int k=1;
    ifstream dosyaOku;
    dosyaOku.open(name);
    string satir = "";
    string donder = "HATALI SECIM";
    if ( dosyaOku.is_open() ){
        while ( getline(dosyaOku, satir) ){
            if(k==q_ID){
                donder = satir;               
            }

            k++; 	  
        }
    }
    dosyaOku.close();
    return donder;
}

void readCase(Case &Senaryo){
    string metin = Case_Read_ID_Name();
    string caseName = getCaseName(metin);
    int id = getCaseID(metin);
    
    Senaryo.SetName(caseName);
    Senaryo.SetId(id);

    string caseStory = Case_Read_Story(caseName);
    string caseFinal = Case_Read_Final(caseName);

    Senaryo.SetStory(caseStory);
    Senaryo.SetFinal(caseFinal);

    string detectiveMetin = Case_Read_Detective(caseName);
    int detectiveID = getDetectiveID(detectiveMetin);
    string detectiveName = getDetectiveName(detectiveMetin);
    
    //Detektif eklendi
    Detective other(detectiveID,detectiveName);
    Senaryo.SetDetective(other);

    //Questions story okuma
    string questionStory1 = Case_Read_Set_Story(caseName,1);
    string questionStory2 = Case_Read_Set_Story(caseName,2);
    string questionStory3 = Case_Read_Set_Story(caseName,3);
    string questionStory4 = Case_Read_Set_Story(caseName,4);

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
    int k = 1;
    string adres = caseName + "_questions.dat";
    ifstream dosyaOku(adres);
    string satir;
    if ( dosyaOku.is_open() ){
        while ( getline(dosyaOku, satir) ){
            if(k<=4)
                set1.SetQuestion(k,satir);
            else if(k<=8)
                set2.SetQuestion(k-4,satir);        
            else if(k<=12)
                set2.SetQuestion(k-8,satir);        
            else if(k<=16)
                set2.SetQuestion(k-12,satir);        
            else if(k<=20)
                set2.SetQuestion(k-16,satir);        
            
            cout<<satir<<endl;

            k++; 	  
        }
    }
    dosyaOku.close();
  

    string personMetin = Case_Read_Person(caseName);
    string PersonName = getPersonName(personMetin);
    int personID = getPersonID(personMetin);
    Person person;

    //Person verileri girildi
    person.SetID(personID);
    person.SetName(PersonName);
    //persona sorular eklendi
    person.SetQuestionSet(1,set1);
    person.SetQuestionSet(2,set2);
    person.SetQuestionSet(3,set3);
    person.SetQuestionSet(4,set4);
    person.SetQuestionSet(5,set5);

    // person eklendi
    Senaryo.SetPerson(person);

}
