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
        virtual void Enter(){};
        virtual void Exit(){};
        int GetXwrhtikothta() const{return Xwrhtikothta;};
        virtual void Pass(){};
        int GetNoOfVehicles() const{return GetNoOfVehicles};
};

class PrwtoTmhma : public Tmhma{
    private:
        Tmhma * EpomenoTmhma;
        bool *etoimo;
    public :
        PrwtoTmhma(Tmhma *,int Xwros,int NSegs);
        ~PrwtoTmhma();
        void Exit();
};

class TeleutaioTmhma : public Tmhma{
    private:
        Tmhma * ProhgoumenoTmhma;
        bool *etoimo;
    public:
        TeleutaioTmhma(Tmhma *,int Xwros,int NSegs);
        ~TeleutaioTmhma();
        void Exit();
};

class EndiamesoTmhma : public Tmhma{
    private : 
        Tmhma * EpomenoTmhma;
        Tmhma * ProhgoumenoTmhma;
        int TheshTmhmtatos;
        bool *etoimo;
    public :
        EndiamesoTmhma(Tmhma * Prohgoumeno, Tmhma * Epomeno,int Xwros,int Thesh,int NSegs );
        ~EndiamesoTmhma();
        void Exit();
}; 
