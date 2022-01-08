#include "diodio.h"

class Eisodos{
    private:
        int Thesh;
    protected:
        int K;
    public :
        Eisodos(int Th,int NewK);
        virtual ~Eisodos();
        virtual Autokinhto & Afairesh();
        virtual void Pros8esh(Autokinhto &);
        virtual Autokinhto & AfaireseApoYpallhlo();
        virtual Autokinhto & AfaireseApoHlektroniko();
        virtual Autokinhto ** Operate(int PosaNaVgoun);
        static int NSegs;
};

class PrwthEisodos : public Eisodos{
    private :
        DiodioMeYpallhlo ** TaDiodiaMeYpallhlo;
        HelktronikoDiodio ** TaHlektronikaDiodia;
        int Plh8osMeYpallhlo,Plh8osHlektronikwn;
    public : 
        PrwthEisodos(int NSegs,int NewK);
        ~PrwthEisodos();
        Autokinhto & Afairesh();
        void Pros8esh(Autokinhto &);
        Autokinhto & AfaireseApoYpallhlo();
        Autokinhto & AfaireseApoHlektroniko();
        Autokinhto ** Operate(int PosaNaVgoun);
        static int SeiraYpallhlou,SeiraHlektronikou;
};

class E3odos : public Eisodos{
    public :
        E3odos(int NSegs);
        ~E3odos();
        Autokinhto & Afairesh();
        void Pros8esh(Autokinhto &);
        Autokinhto & AfaireseApoYpallhlo();
        Autokinhto & AfaireseApoHlektroniko();
        Autokinhto ** Operate(int PosaNaVgoun);
};

class EndiameshEisodos : public Eisodos{
    private :
        DiodioMeYpallhlo ** TaDiodiaMeYpallhlo;
        HelktronikoDiodio ** TaHlektronikaDiodia;
        int Plh8osMeYpallhlo,Plh8osHlektronikwn;
    public :
        EndiameshEisodos (int Th, int NSegs,int NewK);
        ~EndiameshEisodos();
        Autokinhto & Afairesh();
        void Pros8esh(Autokinhto &);
        Autokinhto & AfaireseApoYpallhlo();
        Autokinhto & AfaireseApoHlektroniko();
        Autokinhto ** Operate(int PosaNaVgoun);
        static int SeiraYpallhlou,SeiraHlektronikou;
};
