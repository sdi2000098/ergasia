#include "eisodos.h"

class Tmhma{
    private :
        int Xwrhtikothta;
    protected :
        Eisodos * EisodosTmhmatos;
        Autokinhto ** AutokinhtaTouTmhmatos;
        int Ari8mosAutokinhtwn,TheshTmhmtatos;
        bool OlaKala;
    public :
        Tmhma(int xwros ,int Thesh);
        virtual ~Tmhma();
        virtual void Enter(){};
        virtual void Exit(){};
        int GetXwrhtikothta() const{return Xwrhtikothta;};
        virtual bool Pass(Autokinhto &);
        int GetNoOfVehicles() const{return Ari8mosAutokinhtwn;};
        static float Percent;
        bool ValeToAma3i(Autokinhto & );
        virtual void Operate();
};

class PrwtoTmhma : public Tmhma{
    private:
        Tmhma * EpomenoTmhma;
    public :
        PrwtoTmhma(Tmhma *,int Xwros,int NSegs,int NewK);
        void Exit();
        bool Pass(Autokinhto &);
        void Operate();
};

class TeleutaioTmhma : public Tmhma{
    private:
        Tmhma * ProhgoumenoTmhma;
    public:
        TeleutaioTmhma(Tmhma *,int Xwros,int NSegs);
        void Exit();
        bool Pass(Autokinhto &);
        void Operate();
};

class EndiamesoTmhma : public Tmhma{
    private : 
        Tmhma * EpomenoTmhma;
        Tmhma * ProhgoumenoTmhma;
    public :
        EndiamesoTmhma(Tmhma * Prohgoumeno, Tmhma * Epomeno,int Xwros,int Thesh,int NSegs,int NewK );
        void Exit();
        bool Pass(Autokinhto &);
        void Operate();
}; 
