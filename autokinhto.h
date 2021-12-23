#include <iostream>

using namespace std;

class Autokinhto{
    private :
        int KomvosE3odou;
        int TrexwnTmhma;
        bool Etoimothta;
    public :
        Autokinhto(int e3odos,int tmhma) : KomvosE3odou(e3odos), TrexwnTmhma(tmhma), Etoimothta(false){};
        ~Autokinhto(){cout << "Ena autokinhto katastrafhke\n";};
        int E3odos() const{
            return KomvosE3odou;
        };
        int Tmhma() const{
            return TrexwnTmhma;
        };
        bool EinaiEtoimo() const{
            return Etoimothta;
        };
};