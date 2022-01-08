#include "eisodos.h"
#include <cstring>
using namespace std;

Eisodos::Eisodos(int Th,int NewK) : Thesh(Th),K(NewK){
}

PrwthEisodos::PrwthEisodos(int NSegs,int NewK) : Eisodos(0,NewK){
    SeiraYpallhlou = SeiraHlektronikou =0;
    Plh8osHlektronikwn = rand() % 4 +1;
    Plh8osMeYpallhlo = rand()%6 +1;
    TaDiodiaMeYpallhlo = new DiodioMeYpallhlo*[Plh8osMeYpallhlo];
    TaHlektronikaDiodia = new HelktronikoDiodio*[Plh8osHlektronikwn];
    for ( int i = 0;i<Plh8osMeYpallhlo;i++)
        TaDiodiaMeYpallhlo[i] = new DiodioMeYpallhlo(NSegs,0);
    for ( int i = 0; i< Plh8osHlektronikwn;i++)
        TaHlektronikaDiodia[i] = new HelktronikoDiodio(NSegs,0);
    cout << "Kataskeuasthke h prwth eisodos\n";
}

E3odos::E3odos(int NSegs):   Eisodos(NSegs+1,0){
    cout << "Kataskeuasthke h e3odos\n";
}

EndiameshEisodos :: EndiameshEisodos (int Th, int NSegs,int NewK) : Eisodos(Th,NewK){
    SeiraYpallhlou = SeiraHlektronikou =0;
    Plh8osHlektronikwn = rand() % 4 +1;
    Plh8osMeYpallhlo = rand()%6 +1;
    TaDiodiaMeYpallhlo = new DiodioMeYpallhlo*[Plh8osMeYpallhlo];
    TaHlektronikaDiodia = new HelktronikoDiodio*[Plh8osHlektronikwn];
     for ( int i = 0;i<Plh8osMeYpallhlo;i++)
        TaDiodiaMeYpallhlo[i] = new DiodioMeYpallhlo(NSegs,Th);
    for ( int i = 0; i< Plh8osHlektronikwn;i++)
        TaHlektronikaDiodia[i] = new HelktronikoDiodio(NSegs,Th);
    cout << "Kataskeuasthke h prwth eisodos\n";

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

Autokinhto & PrwthEisodos :: AfaireseApoYpallhlo(){
    for (int i=0;i<Plh8osMeYpallhlo;i++){
        Autokinhto GiaEpistrofh = TaDiodiaMeYpallhlo[SeiraYpallhlou++]->E3odosAutokinhtou();
        if ( GiaEpistrofh.E3odos() != -1 || i == Plh8osMeYpallhlo-1)
            return GiaEpistrofh;
        if (SeiraYpallhlou == Plh8osMeYpallhlo)
            SeiraYpallhlou = 0;
    }
}
Autokinhto & E3odos :: AfaireseApoYpallhlo(){
    cout << "Den yparxoun tameia sthn e3odo\n";
    Autokinhto GiaEpistrofh(-1,-1);
    return GiaEpistrofh;
}

Autokinhto & EndiameshEisodos :: AfaireseApoYpallhlo(){
    for (int i=0;i<Plh8osMeYpallhlo;i++){
        Autokinhto GiaEpistrofh = TaDiodiaMeYpallhlo[SeiraYpallhlou++]->E3odosAutokinhtou();
        if ( GiaEpistrofh.E3odos() != -1 || i == Plh8osMeYpallhlo-1)
            return GiaEpistrofh;
        if (SeiraYpallhlou == Plh8osMeYpallhlo)
            SeiraYpallhlou = 0;
    }
}

Autokinhto & PrwthEisodos :: AfaireseApoHlektroniko(){
    for (int i=0;i<Plh8osHlektronikwn;i++){
        Autokinhto GiaEpistrofh = TaHlektronikaDiodia[SeiraHlektronikou++]->E3odosAutokinhtou();
        if ( GiaEpistrofh.E3odos() != -1 || i == Plh8osHlektronikwn-1)
            return GiaEpistrofh;
        if (SeiraHlektronikou == Plh8osHlektronikwn)
            SeiraHlektronikou = 0;
    }
}

Autokinhto & EndiameshEisodos :: AfaireseApoHlektroniko(){
    for (int i=0;i<Plh8osHlektronikwn;i++){
        Autokinhto GiaEpistrofh = TaHlektronikaDiodia[SeiraHlektronikou++]->E3odosAutokinhtou();
        if ( GiaEpistrofh.E3odos() != -1 || i == Plh8osHlektronikwn-1)
            return GiaEpistrofh;
        if (SeiraHlektronikou == Plh8osHlektronikwn)
            SeiraHlektronikou = 0;
    }
}

Autokinhto & E3odos :: AfaireseApoHlektroniko(){
    cout << "Den yparxoun tameia sthn e3odo\n";
    Autokinhto GiaEpistrofh(-1,-1);
    return GiaEpistrofh;
}

Autokinhto ** Eisodos :: Operate(int PosaNaVgoun){
    if ( PosaNaVgoun == 0)  return NULL;
    int PosaVghkan=0;
    Autokinhto ** PinakasEpistrofhs = new Autokinhto*[PosaNaVgoun];
    for (int i =0;i<K;i++){
        Autokinhto ApoYpallhlo = AfaireseApoYpallhlo();
        PinakasEpistrofhs[PosaVghkan++] = new Autokinhto(ApoYpallhlo);
        if (PosaVghkan == PosaNaVgoun)
            break;
        Autokinhto ApoHlektroniko = AfaireseApoHlektroniko();
        PinakasEpistrofhs[PosaVghkan++] = new Autokinhto(ApoHlektroniko);
        if (PosaVghkan == PosaNaVgoun)
            break;
        ApoHlektroniko = AfaireseApoHlektroniko();
        PinakasEpistrofhs[PosaVghkan++] = new Autokinhto(ApoHlektroniko);
        if (PosaVghkan == PosaNaVgoun)
            break;
    }
    if ( PosaNaVgoun == PosaVghkan){
        K--;
        return PinakasEpistrofhs;
    }
    PinakasEpistrofhs[PosaVghkan] = new Autokinhto(-1,-1);
    K++;
    int limit = rand()%66;
    for ( int i =0;i<limit;i++){
        Autokinhto Neo(rand()%(NSegs+1-Thesh) +Thesh+1,-1);
        Pros8esh(Neo);
    }
    PinakasEpistrofhs = (Autokinhto**)realloc(PinakasEpistrofhs,(PosaVghkan+1)*sizeof(Autokinhto *));
    return PinakasEpistrofhs;
}

