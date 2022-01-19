#include <iostream>

using namespace std;

class Autokinhto{
    private :
        int KomvosE3odou;
        int TrexwnTmhma;
        bool Etoimothta;
    public :
        Autokinhto(int e3odos,int tmhma) : KomvosE3odou(e3odos), TrexwnTmhma(tmhma), Etoimothta(false){};
        int E3odos() const{
            return KomvosE3odou;
        };
        int Tmhma() const{
            return TrexwnTmhma;
        };
        bool EinaiEtoimo() const{
            return Etoimothta;
        };
        void KantoEtoimo(){
            Etoimothta = true;
        }
        void KantoAnetoimo(){
            Etoimothta = false;
        }
        void Alla3eThnThesh(int thesh){
            TrexwnTmhma = thesh;
        }
}; 
