#include "eisodos.h"
#include <cstring>
using namespace std;

Eisodos::Eisodos(char * Onoma){
    OnomaEisodou = new char[strlen(Onoma)+1];
    strcpy(OnomaEisodou,Onoma);
}

PrwthEisodos::PrwthEisodos(char * Onoma,int NSegs) : Eisodos(Onoma){
    Plh8osHlektronikwn = rand() % 4 +1;
    Plh8osMeYpallhlo = rand()%6 +1;
    TaDiodiaMeYpallhlo = new DiodioMeYpallhlo*[Plh8osMeYpallhlo];
    TaHlektronikaDiodia = new HelktronikoDiodio*[Plh8osHlektronikwn];
    for ( int i = 0;i<Plh8osMeYpallhlo;i++)
        TaDiodiaMeYpallhlo[i] = new DiodioMeYpallhlo(NSegs);
    for ( int i = 0; i< Plh8osHlektronikwn;i++)
        TaHlektronikaDiodia[i] = new HelktronikoDiodio(NSegs);
    cout << "Kataskeuasthke h prwth eisodos\n";
}

E3odos::E3odos(char * Onoma):   Eisodos(Onoma){
    cout << "Kataskeuasthke h e3odos\n";
}

EndiameshEisodos :: EndiameshEisodos (char * Onoma, int NSegs) : Eisodos(Onoma){
    Plh8osHlektronikwn = rand() % 4 +1;
    Plh8osMeYpallhlo = rand()%6 +1;
    TaDiodiaMeYpallhlo = new DiodioMeYpallhlo*[Plh8osMeYpallhlo];
    TaHlektronikaDiodia = new HelktronikoDiodio*[Plh8osHlektronikwn];
     for ( int i = 0;i<Plh8osMeYpallhlo;i++)
        TaDiodiaMeYpallhlo[i] = new DiodioMeYpallhlo(NSegs);
    for ( int i = 0; i< Plh8osHlektronikwn;i++)
        TaHlektronikaDiodia[i] = new HelktronikoDiodio(NSegs);
    cout << "Kataskeuasthke h prwth eisodos\n";

}

Eisodos::~Eisodos(){
    delete []OnomaEisodou;
}

PrwthEisodos :: ~PrwthEisodos(){
    for  ( int i = 0;i<Plh8osMeYpallhlo;i++)
        delete TaDiodiaMeYpallhlo[i];
    for (int i = 0;i<Plh8osHlektronikwn;i++)
        delete TaHlektronikaDiodia[i];
    delete []TaDiodiaMeYpallhlo;
    delete []TaHlektronikaDiodia;
    cout << "Katastrafhke h prwth eisodos\n";
}

E3odos :: ~E3odos(){
    cout << "Katastrafhke h e3odos\n";
}
 
EndiameshEisodos :: ~EndiameshEisodos(){
    for  ( int i = 0;i<Plh8osMeYpallhlo;i++)
        delete TaDiodiaMeYpallhlo[i];
    for (int i = 0;i<Plh8osHlektronikwn;i++)
        delete TaHlektronikaDiodia[i];
    delete []TaDiodiaMeYpallhlo;
    delete []TaHlektronikaDiodia;
    cout << "Katastrafhke mia endiamesh e3odos\n";
}

Autokinhto & PrwthEisodos :: Afairesh(){
    if ( rand ()%2)
        return TaDiodiaMeYpallhlo[rand()%Plh8osMeYpallhlo]->E3odosAutokinhtou();
    else    
          return TaHlektronikaDiodia[rand()%Plh8osHlektronikwn]->E3odosAutokinhtou();
}  

Autokinhto & E3odos :: Afairesh(){
    cout<< " Den yparxoun didodia sthn e3odo wste na afaire8oun autokinhta\n";
    Autokinhto Epistrofhs(-1,-1);
    return Epistrofhs;
}

Autokinhto & EndiameshEisodos :: Afairesh(){
    if ( rand ()%2)
        return TaDiodiaMeYpallhlo[rand()%Plh8osMeYpallhlo]->E3odosAutokinhtou();
    else    
          return TaHlektronikaDiodia[rand()%Plh8osHlektronikwn]->E3odosAutokinhtou();
}

void PrwthEisodos:: Pros8esh(Autokinhto & Neo){
    if ( rand()%2)
        TaDiodiaMeYpallhlo[rand()%Plh8osMeYpallhlo]->EisodosAutokinhtou(Neo);
    else
        TaHlektronikaDiodia[rand()%Plh8osHlektronikwn]->EisodosAutokinhtou(Neo);
}

void E3odos :: Pros8esh(Autokinhto & Neo){
    cout << "Den yparxoun didodia sthn e3odo wste na proste8oun autokinhta\n";
}

void EndiameshEisodos:: Pros8esh(Autokinhto & Neo){
    if ( rand()%2)
        TaDiodiaMeYpallhlo[rand()%Plh8osMeYpallhlo]->EisodosAutokinhtou(Neo);
    else
        TaHlektronikaDiodia[rand()%Plh8osHlektronikwn]->EisodosAutokinhtou(Neo);
}