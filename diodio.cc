#include "diodio.h"

Diodio::Diodio(int NSegs){
    Plh8osAutokinhtwn= rand()%10+1;
    AutokinhtaDiodiou = new Autokinhto *[Plh8osAutokinhtwn];
    for ( int i = 0 ;i<Plh8osAutokinhtwn;i++)
        AutokinhtaDiodiou[i] = new Autokinhto(rand()%NSegs +1,-1);
}

void Diodio::EisodosAutokinhtou(const Autokinhto & Neo){
    if ( (AutokinhtaDiodiou = (Autokinhto ** )realloc(AutokinhtaDiodiou,Plh8osAutokinhtwn+1) )== NULL){
        cout << "Provlhma sthn desmeush mnhmhs\n";
        exit(-1);
    }
    AutokinhtaDiodiou[Plh8osAutokinhtwn++] = new Autokinhto(Neo); 
}

Autokinhto & Diodio::E3odosAutokinhtou() {
    Autokinhto  PouVgainei = *AutokinhtaDiodiou[0];
    delete AutokinhtaDiodiou[0];
    for ( int i = 1 ; i < Plh8osAutokinhtwn;i++)
        AutokinhtaDiodiou[i-1] = AutokinhtaDiodiou[i];
    if ( (AutokinhtaDiodiou = (Autokinhto ** )realloc(AutokinhtaDiodiou,Plh8osAutokinhtwn-1) )== NULL){
        cout << "Provlhma sthn desmeush mnhmhs\n";
        exit(-1);
    }
    return PouVgainei;
} 

DiodioMeYpallhlo::DiodioMeYpallhlo(int NSegs) : Diodio(NSegs){
    cout << "Kataskeuasthke ena diodio me ypallhlo\n";
}

DiodioMeYpallhlo::~DiodioMeYpallhlo(){
    cout << "KAtastrafhke ena diodio me ypallhlo\n";
}

HelktronikoDiodio::HelktronikoDiodio(int NSegs) : Diodio(NSegs){
    cout << "Kataskeuasthke ena hlektroniko diodio \n";
}

HelktronikoDiodio::~HelktronikoDiodio(){
    cout << "KAtastrafhke ena hlektroniko diodio\n";
}

