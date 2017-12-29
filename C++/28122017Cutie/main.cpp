#include <iostream>

using namespace std;

class Cutie {
private:
    double latime;
protected:
    double inaltime;
public:
    static int objectCount;
    double lungime;
    //constructor fara parametrii
    Cutie(){
        cout << "Obiectul Cutie a fost creat"<<endl;
        objectCount++;
    }
    //constructor cu 1 parametru
    Cutie(double lat){
        latime = lat;
        cout<<"Obiectul Cutie are latimea: "<<lat<<endl;
    }
    // constructor de copiere
    Cutie(const Cutie &obj){
        cout<<"Constructorul de copiere."<<endl;
    }
    //Destructor
    ~Cutie(){
        cout<<"Obiectul cutie a fost sters."<<endl;
    }
    double getVolum(void){
        return latime*inaltime*lungime;
    }
    void setLatime(double lat);
    void setInaltime(double ina);
    void setLungime(double lun);

    double getLatime(void){
        return latime;
    }

    double getInaltime(void){
        return inaltime;
    }
    friend void afiseazaCutie(Cutie cutie){
        cout<<"Cutie inaltime: "<<cutie.inaltime<<endl;
    }
    int compare(Cutie cutie){
        return this->inaltime <= cutie.inaltime;
    }
};

void Cutie::setLungime(double lun){
    lungime = lun;
}

void Cutie::setInaltime(double ina){
    inaltime = ina;
}

void Cutie::setLatime(double lat){
    latime = lat;
}

class CutieMica:public Cutie {
public:
    //constructor fara parametrii
    CutieMica(){
        cout<<"Obiectul CutieMica a fost creat."<<endl;
    }
    //Destructor
    ~CutieMica(){
        cout<<"Obiectul CutieMica a fost sters."<<endl;
    }
    void setCutieMicaInaltime(double ina){
        inaltime = ina;
    }
    double getCutieMicaInaltime(void){
        return inaltime;
    }
};

int Cutie::objectCount = 0;

int main()
{
    cout << "Hello world!" << endl;

    Cutie cutie1;
    Cutie cutie3;
    Cutie cutie2 = cutie3;
    CutieMica cutie_mica;
    Cutie cutie4(32);
    double volum;
    Cutie *ptrCutie;
    ptrCutie = &cutie4;
    cout<<"Latime cutie4: "<<ptrCutie->getLatime()<<endl;
    //valori aleatoare deoarece obiectele nu au fost initializate
    afiseazaCutie(cutie1);
    afiseazaCutie(cutie2);
    afiseazaCutie(cutie3);

    cutie1.setLatime(4.5);
    cutie1.setInaltime(5.6);
    cutie1.lungime = 7.9;

    volum = cutie1.getInaltime() * cutie1.getLatime() * cutie1.lungime;
    cout << "Volumul cutie1: "<<volum<<endl;

    cutie1.setLatime(23);
    cutie1.setInaltime(6);
    cutie1.setLungime(2);
    cout << "Volumul cutiei 1: "<<cutie1.getVolum()<<endl;

    cutie2.setInaltime(45);
    cutie2.setLatime(34);
    cutie2.lungime = 56;
    volum = cutie2.getInaltime()*cutie2.getLatime()*cutie2.lungime;
    cout << "Volumul cutiei2: "<<volum<<endl;

    cutie2.setLatime(67);
    cutie2.setInaltime(4);
    cutie2.setLungime(3);
    cout << "Volumul cutiei 2: "<<cutie2.getVolum()<<endl;

    cutie_mica.setCutieMicaInaltime(23);
    cutie_mica.setLatime(23);
    //cutie_mica.latime = 34.5; // acces numai in interiorul clasei Cutie
    cutie_mica.lungime = 3.5;
    cutie_mica.setInaltime(3.5);
    cout << "CutieMica volum: "<<cutie_mica.getVolum()<<endl;

    if(cutie2.compare(cutie1)){
        cout<<"Cutie2 "<<cutie2.getInaltime()<<" este mai inalta ca cutie1 "<< cutie1.getInaltime()<<endl;
    } else {
        cout<<"Cutie2 este mai scunda sau egala cutie1"<<endl;
    }
    cout<<"Au fost create un numar de obiecte: "<<Cutie::objectCount<<endl;
    return 0;
}
