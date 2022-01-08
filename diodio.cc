#include "diodio.h"

Diodio::Diodio(int NSegs,int TheshDiodiou){
    Plh8osAutokinhtwn= rand()%10+1;
    AutokinhtaDiodiou = new Autokinhto*[Plh8osAutokinhtwn];
    for ( int i = 0 ;i<Plh8osAutokinhtwn;i++)
        AutokinhtaDiodiou[i] = new Autokinhto(rand()%(NSegs+1-TheshDiodiou) +TheshDiodiou+1,-1);
}

void Diodio::EisodosAutokinhtou(const Autokinhto & Neo){
    if ( (AutokinhtaDiodiou = (Autokinhto ** )realloc(AutokinhtaDiodiou,(Plh8osAutokinhtwn+1)*sizeof(Autokinhto*) ))== NULL){
        cout << "Provlhma sthn desmeush mnhmhs\n";
        exit(-1);
    }
    AutokinhtaDiodiou[Plh8osAutokinhtwn++] = new Autokinhto(Neo); 
}

Autokinhto & Diodio::E3odosAutokinhtou() {
    if (Plh8osAutokinhtwn == 0){
        Autokinhto PouVgainei(-1,-1);
        return PouVgainei;
    }
    Autokinhto  PouVgainei(*AutokinhtaDiodiou[0]);
    delete AutokinhtaDiodiou[0];
    for ( int i = 1 ; i < Plh8osAutokinhtwn;i++)
        AutokinhtaDiodiou[i-1] = AutokinhtaDiodiou[i];
    if ( (AutokinhtaDiodiou = (Autokinhto ** )realloc(AutokinhtaDiodiou,(Plh8osAutokinhtwn-1)*sizeof(Autokinhto*) ) )== NULL){
        cout << "Provlhma sthn desmeush mnhmhs\n";
        exit(-1);
    }
    Plh8osAutokinhtwn--;
    return PouVgainei;
}  
 
DiodioMeYpallhlo::DiodioMeYpallhlo(int NSegs,int TheshDiodiou) : Diodio(NSegs,TheshDiodiou){
    cout << "Kataskeuasthke ena diodio me ypallhlo\n";
}

DiodioMeYpallhlo::~DiodioMeYpallhlo(){
    cout << "KAtastrafhke ena diodio me ypallhlo\n";
}

HelktronikoDiodio::HelktronikoDiodio(int NSegs,int TheshDiodiou) : Diodio(NSegs,TheshDiodiou){
    cout << "Kataskeuasthke ena hlektroniko diodio \n";
}

HelktronikoDiodio::~HelktronikoDiodio(){
    cout << "Katastrafhke ena hlektroniko diodio\n";
}

