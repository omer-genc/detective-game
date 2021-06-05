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
    cout<<"Seneryo seçmek için ID giriniz: ";
    
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
    char arry[100];
    strcpy(arry,metin.c_str());
    return arry[0] - '0';
}

string getCaseName(string metin){
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
    char arry[100];
    strcpy(arry,metin.c_str());
    return arry[0] - '0';
}

string getDetectiveName(string metin){
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

string Case_Read_Quesitons(string name, int q_ID){
    int k=1;
    ifstream dosyaOku(name+"_quesitons.dat");
    string satir = "";
    string donder = "HATALI SECIM";
    if ( dosyaOku.is_open() ){
        while ( getline(dosyaOku, satir) ){
            if(k==q_ID)
                donder = satir;

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
    string soru;
    for (int i = 1; i < 21; i++)
    {
        soru = Case_Read_Quesitons(caseName,i);
        if (i<5)
            set1.SetQuestion(i,soru);
        else if(i<9)
            set2.SetQuestion(i-4,soru);
        else if(i<13)
            set3.SetQuestion(i-8,soru);
        else if(i<17)
            set4.SetQuestion(i-12,soru);
        else if(i<21)
            set5.SetQuestion(i-16,soru);
    }

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
