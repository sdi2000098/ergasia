#include "autokinhto.h"

using namespace std;

class Diodio{
    private :
        Autokinhto ** AutokinhtaDiodiou;
        int Plh8osAutokinhtwn;
    public :
        Diodio(int );
        virtual ~Diodio();
        void EisodosAutokinhtou(const Autokinhto &);
        Autokinhto & E3odosAutokinhtou() ;
};

class DiodioMeYpallhlo : public Diodio{
    public:
        DiodioMeYpallhlo(int);
        ~DiodioMeYpallhlo();
};

class HelktronikoDiodio : public Diodio{
    public:
        HelktronikoDiodio(int);
        ~HelktronikoDiodio();
};