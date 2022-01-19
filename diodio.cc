#include "diodio.h"

Diodio::Diodio(int NSegs,int TheshDiodiou){
    Plh8osAutokinhtwn= rand()%10+1;                 // Tyxaia eisagontai 10 to poly ama3ia sto diodio
    AutokinhtaDiodiou = new Autokinhto*[Plh8osAutokinhtwn];
    for ( int i = 0 ;i<Plh8osAutokinhtwn;i++)
        AutokinhtaDiodiou[i] = new Autokinhto(rand()%(NSegs+1-TheshDiodiou) +TheshDiodiou+1,-1);
    //H parapanw e3odos tou autokinhtou pairnei timhes apo ton komvo ston opoio vrisketai to diodio +1 mexri kai ton teleutaio komvo
}

Diodio::~Diodio(){
    for (int i =0;i<Plh8osAutokinhtwn;i++)
        delete AutokinhtaDiodiou[i];
    delete []AutokinhtaDiodiou;
}

void Diodio::EisodosAutokinhtou(const Autokinhto & Neo){
    if ( (AutokinhtaDiodiou = (Autokinhto ** )realloc(AutokinhtaDiodiou,(Plh8osAutokinhtwn+1)*sizeof(Autokinhto*) ))== NULL){
        cout << "Provlhma sthn desmeush mnhmhs\n";
        exit(-1);
    }
    AutokinhtaDiodiou[Plh8osAutokinhtwn++] = new Autokinhto(Neo); 
}

Autokinhto Diodio::E3odosAutokinhtou() {
    if (Plh8osAutokinhtwn == 0){            //Den yparxoun ama3ia na vgoun
        Autokinhto PouVgainei(-1,-1);
        return PouVgainei;
    }   
    Autokinhto  PouVgainei(*AutokinhtaDiodiou[0]);  //8a afairesei to prwto ama3i tou diodiou
    delete AutokinhtaDiodiou[0];
    for ( int i = 1 ; i < Plh8osAutokinhtwn;i++)    // Ola ta ama3ia phgainoun mia 8esh mprosta
        AutokinhtaDiodiou[i-1] = AutokinhtaDiodiou[i];
    if (--Plh8osAutokinhtwn == 0){      // Den yparxoun alla ama3ia sto diodio
        AutokinhtaDiodiou = NULL;
        return PouVgainei;
    }
    if ( (AutokinhtaDiodiou = (Autokinhto ** )realloc(AutokinhtaDiodiou,(Plh8osAutokinhtwn)*sizeof(Autokinhto*) ) )== NULL){
        cout << "Provlhma sthn desmeush mnhmhs\n";
        exit(-1);
    }
    return PouVgainei;
}  
 
DiodioMeYpallhlo::DiodioMeYpallhlo(int NSegs,int TheshDiodiou) : Diodio(NSegs,TheshDiodiou){
    cout << "Kataskeuasthke ena diodio me ypallhlo\n";
}

DiodioMeYpallhlo::~DiodioMeYpallhlo(){
    cout << "Katastrafhke ena diodio me ypallhlo\n";
}

HelktronikoDiodio::HelktronikoDiodio(int NSegs,int TheshDiodiou) : Diodio(NSegs,TheshDiodiou){
    cout << "Kataskeuasthke ena hlektroniko diodio \n";
}

HelktronikoDiodio::~HelktronikoDiodio(){
    cout << "Katastrafhke ena hlektroniko diodio\n";
}

