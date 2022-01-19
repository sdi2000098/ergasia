#include "AttikhOdos.h"

using namespace std;

AttikhOdos::AttikhOdos(int NNSegs,int NewK,float Percent) : NSegs(NNSegs){
    if (NSegs <=0){
        cout << "Perimena ari8mo tmhmatwn megalytero tou 0\n";
        exit(-1);
    }
    if (Percent <0 || Percent >100){
        cout <<"Perimena pososto meta3y 0 kai 100\n";
        exit(-1);
    }
    if (NewK < 0){
        cout << "Perimena 8etiko K\n";
        exit(-1);
    }
    int xwros;
    Plh8osOxhmatwn = 0;
    TmhmataAttikhs = new Tmhma*[NSegs];
    cout << "Eisagetai thn xwrhtikotha tou prwtou tmhmatos:\n";
    cin >> xwros;
    TmhmataAttikhs[0] = new PrwtoTmhma(xwros,NSegs,NewK,Percent);
    Plh8osOxhmatwn+=TmhmataAttikhs[0]->GetNoOfVehicles(); 
    if (NSegs !=1){    
        for (int i = 1;i<NSegs-1;i++){
            cout << "Eisagetai thn xwrhtikothta tou " << i+1 << " tmhmatos:\n";
            cin >> xwros;
            TmhmataAttikhs[i] = new EndiamesoTmhma(TmhmataAttikhs[i-1],xwros,i,NSegs,NewK,Percent);
            Plh8osOxhmatwn+=TmhmataAttikhs[i]->GetNoOfVehicles();
        }
    }
    cout << "Eisagetai thn xwrhtikotha tou teleutaiou tmhmatos:\n";
    cin >> xwros;
    TmhmataAttikhs[NSegs-1] = new TeleutaioTmhma(TmhmataAttikhs[NSegs-2],xwros,NSegs,NewK,Percent);
    Plh8osOxhmatwn+=TmhmataAttikhs[NSegs-1]->GetNoOfVehicles();
    cout << "To plh8os oxhmatwn sthn attikh odo einai: " << Plh8osOxhmatwn <<"\n";
}

AttikhOdos :: ~AttikhOdos(){
    for (int i=0;i<NSegs;i++)
        delete TmhmataAttikhs[i];
    delete []TmhmataAttikhs;
}

void AttikhOdos :: Operate(){
    TmhmataAttikhs[NSegs-1]->Operate();         // 3ekina thn operate apo to teleutaio tmhma
    Plh8osOxhmatwn = 0;
    for ( int i=0;i<NSegs;i++)
        Plh8osOxhmatwn += TmhmataAttikhs[i]->GetNoOfVehicles();
    cout << "To plh8os oxhmatwn sthn attikh odo einai: " << Plh8osOxhmatwn <<"\n";
}