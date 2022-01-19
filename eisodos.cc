#include "eisodos.h"
#include <cstring>
using namespace std;

int Eisodos::NSegs = 0;
int Eisodos::SeiraYpallhlou = 0;
int Eisodos::SeiraHlektronikou = 0;

Eisodos :: Eisodos (int Th, int NNSegs,int NewK) : Thesh(Th),K(NewK){
    NSegs = NNSegs;
    Plh8osHlektronikwn = rand() % 4 +1;
    Plh8osMeYpallhlo = rand()%6 +1;
    TaDiodiaMeYpallhlo = new DiodioMeYpallhlo*[Plh8osMeYpallhlo];
    TaHlektronikaDiodia = new HelktronikoDiodio*[Plh8osHlektronikwn];
     for ( int i = 0;i<Plh8osMeYpallhlo;i++)
        TaDiodiaMeYpallhlo[i] = new DiodioMeYpallhlo(NSegs,Th);
    for ( int i = 0; i< Plh8osHlektronikwn;i++)
        TaHlektronikaDiodia[i] = new HelktronikoDiodio(NSegs,Th);
    cout << "Kataskeuasthke h " << Thesh+1 <<  "h eisodos\n";
} 

Eisodos :: ~Eisodos(){
    for  ( int i = 0;i<Plh8osMeYpallhlo;i++)
        delete TaDiodiaMeYpallhlo[i];
    for (int i = 0;i<Plh8osHlektronikwn;i++)
        delete TaHlektronikaDiodia[i];
    delete []TaDiodiaMeYpallhlo;
    delete []TaHlektronikaDiodia;
    cout << "Katastrafhke h " << Thesh+1 << " eisodos\n";
}

void Eisodos:: Pros8esh(Autokinhto & Neo){ 
    //Tyxaia prosti8etai ena autokinhto eite se ena hlektroniko eite se ena diodio me ypallhlo
    if ( rand()%2)
        TaDiodiaMeYpallhlo[rand()%Plh8osMeYpallhlo]->EisodosAutokinhtou(Neo);
    else
        TaHlektronikaDiodia[rand()%Plh8osHlektronikwn]->EisodosAutokinhtou(Neo);
}


Autokinhto Eisodos :: AfaireseApoYpallhlo(){
    // H metavlhth SeiraYpallhlou xrhsimopoieitai gia na yparxei mia synexeia oson afora to poio diodio 
    // e3agei to autokinhto wste na vgainoun pio "omala" ta autokinhta kai oxi ola apo ena diodio
    for (int i=0;i<Plh8osMeYpallhlo;i++){   // Diatrexoume ola ta diodia mexri na vroume autokinhta me e3odo != -1
        if (SeiraYpallhlou>=Plh8osMeYpallhlo)
            SeiraYpallhlou=0;
        Autokinhto GiaEpistrofh = TaDiodiaMeYpallhlo[SeiraYpallhlou++]->E3odosAutokinhtou(); 
        if ( GiaEpistrofh.E3odos() != -1)
            return GiaEpistrofh;
    }
    Autokinhto GiaEpistrofh(-1,-1);
    return GiaEpistrofh;
}

Autokinhto  Eisodos :: AfaireseApoHlektroniko(){    // Idia logika me thn parapanw synarthsh
    for (int i=0;i<Plh8osHlektronikwn;i++){
        if (SeiraHlektronikou >= Plh8osHlektronikwn)
            SeiraHlektronikou = 0;
        Autokinhto GiaEpistrofh = TaHlektronikaDiodia[SeiraHlektronikou++]->E3odosAutokinhtou();
        if ( GiaEpistrofh.E3odos() != -1 )
            return GiaEpistrofh;
    }
    Autokinhto GiaEpistrofh(-1,-1);
    return GiaEpistrofh;
}

Autokinhto ** Eisodos :: Operate(int PosaNaVgoun,bool & OlaKala){
    if ( PosaNaVgoun == 0)  return NULL;
    int PosaVghkan=0,i;
    Autokinhto ** PinakasEpistrofhs = new Autokinhto*[PosaNaVgoun];
    bool Stop;
    for ( i =0;i<K;i++){
        Stop = true;    // Se periptwsh pou den yparxei allo ama3i na vgei apo thn eisodo h metavlhth paramenei true
        Autokinhto ApoYpallhlo = AfaireseApoYpallhlo();     // Vgazei ena autokinhto apo ta diodia me ton ypallhlo
        if (ApoYpallhlo.E3odos()!=-1){
            PinakasEpistrofhs[PosaVghkan] = new Autokinhto(ApoYpallhlo);    // Pros8etei ena autokinhto ston pinaka
            PinakasEpistrofhs[PosaVghkan++]->Alla3eThnThesh(Thesh);   // Allazei katallhla thn thesh tou autokinhtou
            Stop = false;
            if (PosaVghkan == PosaNaVgoun)
                break;
        }
        // H parapanw diadikasia epanalamvanetai kai gia dyo hlektronika
        Autokinhto ApoHlektroniko = AfaireseApoHlektroniko();   
        if (ApoHlektroniko.E3odos()!=-1){
            PinakasEpistrofhs[PosaVghkan] = new Autokinhto(ApoHlektroniko);
            PinakasEpistrofhs[PosaVghkan++]->Alla3eThnThesh(Thesh);
            Stop = false;
            if (PosaVghkan == PosaNaVgoun)
                break;
        }
        ApoHlektroniko = AfaireseApoHlektroniko();
        if (ApoHlektroniko.E3odos()!=-1){
            PinakasEpistrofhs[PosaVghkan]= new Autokinhto(ApoHlektroniko);
            PinakasEpistrofhs[PosaVghkan++]->Alla3eThnThesh(Thesh);
            Stop = false;
            if (PosaVghkan == PosaNaVgoun)
                break;
        }
        if (Stop)
            break;
    }
    if ( PosaNaVgoun == PosaVghkan){    // Auto shmainei oti yparxoun kai alla diodia pou perimenoun sta diodia
        OlaKala=false;
        cout << "Ka8ysterhseis sthn eisodo tou komvou " << Thesh<< "\n";
        K--;
        return PinakasEpistrofhs;
    }
    // Vriskomaste sthn periptwsh pou vghkan ola ta autokinhta tou diodiou
    //Pros8etoume ena autokinhto me e3odo -1 ston pinaka to opoio shmatodotei to telos tou pinaka
    PinakasEpistrofhs[PosaVghkan] = new Autokinhto(-1,-1);   
    K++;
    int limit = rand()%66;      // Tyxaia prosti8entai autokinhta sta diodia
    for ( int i =0;i<limit;i++){
        Autokinhto Neo(rand()%(NSegs+1-Thesh) +Thesh+1,-1);
        Pros8esh(Neo);
    }
    PinakasEpistrofhs = (Autokinhto**)realloc(PinakasEpistrofhs,(PosaVghkan+1)*sizeof(Autokinhto *));
    return PinakasEpistrofhs;
}

