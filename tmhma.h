#include "eisodos.h"

class Tmhma{
    private :
        int Xwrhtikothta;
    protected :
        Eisodos * EisodosTmhmatos;
        Autokinhto ** AutokinhtaTouTmhmatos;
        int Ari8mosAutokinhtwn,TheshTmhmtatos;
        bool OlaKala;       // An auth h metavlhth parameinei true tote den yphr3e kamia ka8ysterhsh
    public :
        Tmhma(int xwros ,int Thesh,float NewPercent);
        virtual ~Tmhma();
        void Enter();
        virtual void Exit() = 0;
        int GetXwrhtikothta() const{return Xwrhtikothta;};
        virtual bool Pass(Autokinhto &) = 0;
        int GetNoOfVehicles() const{return Ari8mosAutokinhtwn;};
        static float Percent;
        bool ValeToAma3i(Autokinhto & );        // Eisagei ena autokinhto sto tmhma, epistrefei 0 an to tmhma htan gemato
        virtual void OriseEpomeno(Tmhma *) =0;  // Orizei to thn metavlhth EpomenoTmhma
        virtual void Operate() = 0;
};

class PrwtoTmhma : public Tmhma{
    private:
        Tmhma * EpomenoTmhma;
    public :
        PrwtoTmhma(int Xwros,int NSegs,int NewK,float NewPercent);
        ~PrwtoTmhma();
        void Exit();
        bool Pass(Autokinhto &);
        void Operate();
        void OriseEpomeno(Tmhma *);
};

class TeleutaioTmhma : public Tmhma{
    private:
        Tmhma * ProhgoumenoTmhma;
    public:
        TeleutaioTmhma(Tmhma *,int Xwros,int NSegs,int NewK,float NewPercent);
        ~TeleutaioTmhma();
        void Exit();
        bool Pass(Autokinhto &);
        void Operate();
        void OriseEpomeno(Tmhma *){};
};

class EndiamesoTmhma : public Tmhma{
    private : 
        Tmhma * EpomenoTmhma;
        Tmhma * ProhgoumenoTmhma;
    public :
        EndiamesoTmhma(Tmhma * Prohgoumeno,int Xwros,int Thesh,int NSegs,int NewK,float NewPercent);
        ~EndiamesoTmhma();
        void Exit();
        bool Pass(Autokinhto &);
        void Operate();
        void OriseEpomeno(Tmhma *);
}; 
