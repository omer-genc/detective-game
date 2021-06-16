#include "File.h"
#include "Exception.h"

int main(){

    Questions set1;
    Questions set2;
    Questions set3;
    Questions set4;
    Questions set5;

    set1.SetID(1);
    set1.SetStory("Olay bir deniz taşıtında yaşanmış olmalı sonuçta masa ve satranç tahtası var. Acaba ne tür bir taşıt tekne olması çok olası bir durum…");
    set1.SetQuestion(1,"Üzerinde üniforma bulunan bu kişiler asker mi?");
    set1.SetQuestion(2,"Bu kişiler sizin askerleriniz miydi?");
    set1.SetQuestion(3,"Olay bir gemide mi yaşandı?");
    set1.SetQuestion(4,"Olay denizde mi yaşandı ?");

    set2.SetID(2);
    set2.SetStory("Bu kişiler bir başkası tarafından öldürülmemiş, amiralin ölümler ile bir alakası olduğunu düşünmüştüm. Galiba yanıldım, tabi yalan söylemiyorsa…");
    set2.SetQuestion(1,"Olay vir deniz taşıtında mı yaşandı?");
    set2.SetQuestion(2,"Olay bir teknede mi yaşandı?");
    set2.SetQuestion(3,"Askerler birileri tarafından mı öldürüldü?");
    set2.SetQuestion(4,"Bu kişiler dost muydu?");

    set3.SetID(3);
    set3.SetStory("Yaşlı amiral gözlerini odasında asılı duran silaha yöneltir. Bunlar silah ile mi öldü diye sorduğunda iki közünü de kapatır. Bu hem evet hem de hayır mı demek istedi, peki ama bunun anlamı ne?");
    set3.SetQuestion(1,"Askerler birbirlerini mi vurdu?");
    set3.SetQuestion(2,"Fotoğrafta gözükmeyen 3. bir şahıs var mıydı?");
    set3.SetQuestion(3,"Ölmeden önce satranç mı oynadılar?");
    set3.SetQuestion(4,"Ölümlerin oyun ile alakası var mı?");

    set4.SetID(4);
    set4.SetStory("Ortada bir satranç tahtası var ve birisi intihar etti acaba hangi intihar etti...");
    set4.SetQuestion(1,"Askerlerden biri silah ile vurularak mı öldü ?");
    set4.SetQuestion(2,"Silahla ölen kişi kaza sonucu mu öldü?");
    set4.SetQuestion(3,"Silah ile ölen kişi intihar mı etti?");
    set4.SetQuestion(4,"Deniz taşıtında olduğunu söylemiştin bu taşıt deniz altı mı?");

    set5.SetID(5);
    set5.SetStory("Askerler, satranç, intihar... taşlar şimdi yerine oturdu");
    set5.SetQuestion(1,"Kazanan mı intihar etti?");
    set5.SetQuestion(2,"Kaybeden boğularak mı öldü?");
    set5.SetQuestion(3,"Deniz altı su mu alıyordu?");
    set5.SetQuestion(4,"Bu bilgiler olayı çözmem için yeterli mi?");

    Person amiral(1,"Amiral",set1,set2,set3,set4,set5);
    Detective Orkun(1,"Orkun");
    string story = "Orkun hafta sonunu değerlendirmek için sanat galerisine gider. Sanat galerisinde gezinirken bir süre sonra sıkılır ve çıkmaya karar verir ve çıkmadan önce son kez o fotoğrafa bakmak ister. Çok ilginç bir fotoğraf, tamamen siyah beyaz eski bir fotoğraf. Arka planı çok belli değildir ve mekânı kestirmek neredeyse imkansızdır. Fotoğrafı ilginç kılan şey ise karşılıklı oturan iki ceset yetmezmiş gibi bir de masanın üzerinde bir satranç tahtası olmasıdır.  Bu fotoğrafın sırrını öğrenmek isteyen Orkun galeri görevlisi ile konuşur ve fotoğrafın izini sürmeye karar verir. Edindiği bilgiye göre bu fotoğraf galeriye emekli bir donanma amirali tarafından bağışlanmıştır. Uzun süren araştırmalar sonucunda bu amiral ile görüşme ayarlar. Görüşmeye giden Orkun hiç ummadığı bir şey ile karşılaşır. Amiral çok yaşlıdır ve konuşma yazma gibi motor fonksiyonlarını kaybetmiştir. Mektuplaştığı kişi yani amiralin eşi ona şunları söyler. “Biliyorum umduğunu bulamadın bende o fotoğrafın sırrını bilmiyorum, ne kadar konuşamasa da bazen soru sorduğumda gözleri ile evet ve hayır cevapları verebilir. Sağ gözünü kırparsa evet sol gözünü kırparsa hayır demek istiyordur.” bunu üzerine Orkun evet ve hayırlı sorular sormaya başlar....";
    string final = "Her şey anlaşıldı bu iki asker deniz altında görevli imiş, taşıtları hasar görmüş ve batıyormuş. Askerler öleceklerini anlayınca bir satranç oyunu oynamaya karar verirler. Kazanan kişi daha acısız ve kolay olan yolu yani silah ile intihar etmeye hak kazanmış. Kazanan kişi intihar eder kaybeden ise boğularak ölür. İyi ama diğeri neden silahla kendini vurmadı? Çünkü tek bir mermileri vardı. Bu sözler bizzat amiralin eşine aittir. Orkun döner ve amiralin eşine konuşur, ama bilmediğinizi söylemiştiniz der. Bu olayı çözen 5. kişisin der amiralin eşi. İnsan yaşlanınca geleni gideni azalıyor. Ben ve eşim böyle bir oyun oynamaya karar verdik.  Böylece son günlerimizde ziyaretçilerimiz çok oluyor bu saye de kendimizi yalnız hissetmiyoruz. Eşim yıllar önce çekti bu fotoğrafı. Olayın detaylarını ise boğulan askerin bıraktığı bir nottan öğrendik";
    Case fotograf(1,"Fotograf",story,final,amiral,Orkun);

    Case *olay = new Case;
    Case oyun();
    int secim;
    bool flag = true;

    do
    {
        try
        {
            cout<<"1. Yazar modu"<<
            endl<<"2. Kayitli oyunlar"<<
            endl<<"3. Yüklü oyun"<<
            endl<<"4. Cikis"<<
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
                    fotograf.Play();
                    break;
                case 4:
                    flag = false;
                    break;
                default:
                    throw Exception("seçim 1 ile 4 arasinda olmali");
                    break;
            }
        }       
        catch(Exception obj)
        {
            cout<< obj.getMessage()<<endl<<endl;
            cin.clear();
            cin.ignore(100, '\n');
        }// end catch
        
        
    } while (flag);
    
    delete olay;

    

    return 0;
}