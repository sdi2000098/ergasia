#include "eisodos.h"

class Tmhma{
    protected :
        Eisodos * EisodosTmhmatos;
        Autokinhto ** AutokinhtaTouTmhmatos;
        int Xwrhtikothta;
        int Ari8mosAutokinhtwn;
    public :
        Tmhma(int);
        ~Tmhma();
        virtual void Enter();
        virtual void Exit();
        int GetXwrhtikothta() const;
        virtual void Pass();
        int GetNoOfVehicles() const;
};

class PrwtoTmhma : public Tmhma{
    private:
        Tmhma * EpomenoTmhma;
    public :
        PrwtoTmhma(Tmhma *,int Xwros,int NSegs);
        ~PrwtoTmhma();
};

class TeleutaioTmhma : public Tmhma{
    private:
        Tmhma * ProhgoumenoTmhma;
    public:
        TeleutaioTmhma(Tmhma *,int Xwros,int NSegs);
        ~TeleutaioTmhma();
};

class EndiamesoTmhma : public Tmhma{
    private : 
        Tmhma * EpomenoTmhma;
        Tmhma * ProhgoumenoTmhma;
        int TheshTmhmtatos;
    public :
        EndiamesoTmhma(Tmhma * Prohgoumeno, Tmhma * Epomeno,int Xwros,int Thesh,int NSegs );
        ~EndiamesoTmhma();
}; 