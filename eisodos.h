#include "diodio.h"

class Eisodos{
    private :
        char * OnomaEisodou;
    public :
        Eisodos(char *);
        virtual ~Eisodos();
        virtual Autokinhto & Afairesh();
        virtual void Pros8esh(Autokinhto &);
};

class PrwthEisodos : public Eisodos{
    private :
        DiodioMeYpallhlo ** TaDiodiaMeYpallhlo;
        HelktronikoDiodio ** TaHlektronikaDiodia;
        int Plh8osMeYpallhlo,Plh8osHlektronikwn;
    public :
        PrwthEisodos(char *,int);
        ~PrwthEisodos();
        Autokinhto & Afairesh();
        void Pros8esh(Autokinhto &);


};

class E3odos : public Eisodos{
    public :
        E3odos(char*);
        ~E3odos();
        Autokinhto & Afairesh();
        void Pros8esh(Autokinhto &);
};

class EndiameshEisodos : public Eisodos{
    private :
        DiodioMeYpallhlo ** TaDiodiaMeYpallhlo;
        HelktronikoDiodio ** TaHlektronikaDiodia;
        int Plh8osMeYpallhlo,Plh8osHlektronikwn;
    public :
        EndiameshEisodos(char *,int);
        ~EndiameshEisodos();
        Autokinhto & Afairesh();
        void Pros8esh(Autokinhto &);
};