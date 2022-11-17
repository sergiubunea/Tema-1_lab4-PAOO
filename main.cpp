#include <iostream>
using namespace std;


class Uncopyable{
    protected:
        Uncopyable(){}
        ~Uncopyable(){}
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};

class Casa:private Uncopyable{
    public:
        Casa(){}
        Casa(const string&Nume_proprietar, const int&Nr_etaje, const int&Nr_camere):Nume_proprietar(Nume_proprietar), Nr_etaje(Nr_etaje), Nr_camere(Nr_camere){}
        ~Casa(){
            cout<<"Casa a fost stearsa!\n";
        }

        //copying constructor
        Casa& operator=(const Casa& casa){
            Nume_proprietar=casa.Nume_proprietar;
            Nr_etaje=casa.Nr_etaje;
            Nr_camere=casa.Nr_camere;
            return *this;
        }

        void afisareCasa(){
            cout<<"Nume proproetar: "<<this->Nume_proprietar<<"\nNumar etaje: "<<this->Nr_etaje<<"\nNumar camere: "<<this->Nr_camere<<"\n";
        };
    private:
        string Nume_proprietar;
        int Nr_etaje;
        int Nr_camere;
};

int main(){
    Casa c1("Sergiu", 2, 5);
    c1.afisareCasa();
    Casa c2("Alexandra", 1, 3);
    Casa c3;
    c3=c2;
    c3.afisareCasa();
    return 0;
}