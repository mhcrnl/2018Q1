#include <iostream>

using namespace std;

class Actiuni {
public:
    string tiker;
    double nr_actiuni;
    double profit;
    double pret_actiune_actual;

    double castig_pe_actiune(){
        return profit/nr_actiuni;
    }

    double coeficientul_de_capitalizare(double profit_per_actiune){
        return pret_actiune_actual/profit_per_actiune;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Actiuni fp;
    fp.pret_actiune_actual = 0.8640;
    fp.nr_actiuni = 9334682278;
    fp.profit     = 1012898265;
    double profit_per_actiune = fp.castig_pe_actiune();

    cout<<"Profit pe actiune: "<<fp.castig_pe_actiune()<<endl;
    cout<<"PER: "<<fp.coeficientul_de_capitalizare(profit_per_actiune)<<endl;

    return 0;
}
