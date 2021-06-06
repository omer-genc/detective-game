#include "File.h"
/*
    lütfen mod seçiniz
    1. Yazar modu
    2. Kayitli oyunlar

*/
int main(){

    Case *olay = new Case;
    int secim;
    bool kapi = true;
    while (kapi)
    {
        cout<<"1. Yazar modu"<<
        endl<<"2. Kayitli oyunlar"<<
        endl<<"3. Cikis"<<
        endl<<"Secim: ";
        cin>>secim;

        switch (secim)
        {
            case 1:
                caseDuzenle(*olay);
                olay->Case_WriteToFile();
                break;
            case 2:
                readCase(*olay);
                olay->Play();
                break;
            case 3:
                kapi = false;
                break;
            default:
                cout<<"Hatalı giriş..."<<endl;
                break;
        }


    }

    return 0;
}