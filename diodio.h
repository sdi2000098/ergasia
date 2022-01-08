#include "autokinhto.h"

using namespace std;

class Diodio{
    private :
        Autokinhto ** AutokinhtaDiodiou;
        int Plh8osAutokinhtwn;
    public :
        Diodio(int NSegs,int TheshDiodiou);
        virtual ~Diodio();
        void EisodosAutokinhtou(const Autokinhto &);        //Vazei ena autokinhto
        Autokinhto & E3odosAutokinhtou() ;                  //E3ageis ena autokinhto, epistrefei autokinhto me proorismo-1 se periptwsh apotyxias
};

class DiodioMeYpallhlo : public Diodio{
    public:
        DiodioMeYpallhlo(int NSegs,int TheshDiodiou);
        ~DiodioMeYpallhlo();
};

class HelktronikoDiodio : public Diodio{
    public:
        HelktronikoDiodio(int NSegs,int TheshDiodiou);
        ~HelktronikoDiodio();
}; 
