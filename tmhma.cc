#include "tmhma.h"

using namespace std;

Tmhma :: Tmhma(int xwros ) : Xwrhtikothta(xwros){
    Ari8mosAutokinhtwn = rand()%100+1;
    AutokinhtaTouTmhmatos = new Autokinhto*[Ari8mosAutokinhtwn];
};

PrwtoTmhma :: PrwtoTmhma(Tmhma * Next,int Xwros,int NSegs) : Tmhma(Xwros),EpomenoTmhma(Next){
    for ( int i = 0 ;i<Ari8mosAutokinhtwn;i++)
        AutokinhtaTouTmhmatos[i] = new Autokinhto(rand()%NSegs+1,0);
    EisodosTmhmatos = new PrwthEisodos(NSegs);
};

TeleutaioTmhma :: TeleutaioTmhma(Tmhma * Prev,int Xwros,int NSegs) : Tmhma(Xwros),ProhgoumenoTmhma(Prev){
    for ( int i = 0 ;i<Ari8mosAutokinhtwn;i++)
        AutokinhtaTouTmhmatos[i] = new Autokinhto(NSegs+1,NSegs);
    EisodosTmhmatos = new E3odos(NSegs);
};

EndiamesoTmhma :: EndiamesoTmhma(Tmhma* Prev,Tmhma* Next,int Xwros,int Thesh,int NSegs) :
    Tmhma(Xwros),EpomenoTmhma(Next),ProhgoumenoTmhma(Prev),TheshTmhmtatos(Thesh){
    for ( int i = 0 ;i<Ari8mosAutokinhtwn;i++)
        AutokinhtaTouTmhmatos[i] = new Autokinhto(rand()%(NSegs-TheshTmhmtatos)+TheshTmhmtatos+1,TheshTmhmtatos);
}

Tmhma :: ~Tmhma(){
    
}