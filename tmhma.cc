#include "tmhma.h"

using namespace std;

Tmhma :: Tmhma(int xwros ,int Thesh) : Xwrhtikothta(xwros),TheshTmhmtatos(Thesh){
    Ari8mosAutokinhtwn = rand()%100+1;
    AutokinhtaTouTmhmatos = new Autokinhto*[Ari8mosAutokinhtwn];
    for ( float i = 0;i<Ari8mosAutokinhtwn*Percent/100;i++){
        int neo = rand()%Ari8mosAutokinhtwn;
        if (AutokinhtaTouTmhmatos[neo]->EinaiEtoimo())
            i--;
        else
            AutokinhtaTouTmhmatos[neo]->KantoEtoimo();
    }
};

PrwtoTmhma :: PrwtoTmhma(Tmhma * Next,int Xwros,int NSegs,int NewK) : Tmhma(Xwros,0),EpomenoTmhma(Next){
    Eisodos::NSegs = NSegs;
    for ( int i = 0 ;i<Ari8mosAutokinhtwn;i++)
        AutokinhtaTouTmhmatos[i] = new Autokinhto(rand()%NSegs+1,0);
    EisodosTmhmatos = new PrwthEisodos(NSegs,NewK);
};

TeleutaioTmhma :: TeleutaioTmhma(Tmhma * Prev,int Xwros,int NSegs) : Tmhma(Xwros,NSegs),ProhgoumenoTmhma(Prev){
    for ( int i = 0 ;i<Ari8mosAutokinhtwn;i++)
        AutokinhtaTouTmhmatos[i] = new Autokinhto(NSegs+1,NSegs);
    EisodosTmhmatos = new E3odos(NSegs);
};

EndiamesoTmhma :: EndiamesoTmhma(Tmhma* Prev,Tmhma* Next,int Xwros,int Thesh,int NSegs,int NewK) :
    Tmhma(Xwros,Thesh),EpomenoTmhma(Next),ProhgoumenoTmhma(Prev){
    for ( int i = 0 ;i<Ari8mosAutokinhtwn;i++)
        AutokinhtaTouTmhmatos[i] = new Autokinhto(rand()%(NSegs-TheshTmhmtatos)+TheshTmhmtatos+1,TheshTmhmtatos);
    EisodosTmhmatos = new EndiameshEisodos(TheshTmhmtatos,NSegs,NewK);
}

Tmhma :: ~Tmhma(){
    delete EisodosTmhmatos;
    for (int i = 0;i<Ari8mosAutokinhtwn;i++)
        delete AutokinhtaTouTmhmatos[i];
    delete []AutokinhtaTouTmhmatos;
}

void PrwtoTmhma :: Exit(){
    int PosaVghkan = 0;
    for (int i = 0;i<Ari8mosAutokinhtwn;i++){
        if (AutokinhtaTouTmhmatos[i]->E3odos() == 1 && AutokinhtaTouTmhmatos[i]->EinaiEtoimo()){
            Autokinhto * ToDelete = AutokinhtaTouTmhmatos[i];
            PosaVghkan++;
            for (int j = i;j<Ari8mosAutokinhtwn-PosaVghkan;j++)
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];
            delete ToDelete;
        }
    }
    int ArxikosAri8mos = Ari8mosAutokinhtwn;
    Ari8mosAutokinhtwn-=PosaVghkan;
    int i;
    for ( i=0;i<Ari8mosAutokinhtwn;i++){
        if (AutokinhtaTouTmhmatos[i]->EinaiEtoimo()){
            if (!Pass(*AutokinhtaTouTmhmatos[i]))
                break;
            Autokinhto * ToDelete = AutokinhtaTouTmhmatos[i];
            PosaVghkan--;
            for (int j = i;j<Ari8mosAutokinhtwn-PosaVghkan;j++)
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];
            delete ToDelete;
        }
    }
    if ( i != Ari8mosAutokinhtwn){
        cout << "Ka8ysterhseis meta ton komvo 1\n" ;
        OlaKala = false;
    }
    Ari8mosAutokinhtwn = ArxikosAri8mos - PosaVghkan;
    if( (AutokinhtaTouTmhmatos=(Autokinhto**)realloc(AutokinhtaTouTmhmatos,Ari8mosAutokinhtwn*sizeof(Autokinhto*)) )== NULL){
        cout << "Error in allocating memory\n";
        exit(-1);
    }
}

void TeleutaioTmhma :: Exit(){
    int PosaVghkan = 0;
    for (int i = 0;i<Ari8mosAutokinhtwn;i++){
        if ( AutokinhtaTouTmhmatos[i]->EinaiEtoimo()){
            Autokinhto * ToDelete = AutokinhtaTouTmhmatos[i];
            PosaVghkan++;
            for (int j = i;j<Ari8mosAutokinhtwn-PosaVghkan;j++)
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];
            delete ToDelete;
        }
    }
    Ari8mosAutokinhtwn-=PosaVghkan;
    if( (AutokinhtaTouTmhmatos=(Autokinhto**)realloc(AutokinhtaTouTmhmatos,Ari8mosAutokinhtwn*sizeof(Autokinhto*)) )== NULL){
        cout << "Error in allocating memory\n";
        exit(-1);
    }
}

void EndiamesoTmhma :: Exit(){
    int PosaVghkan = 0;
    for (int i = 0;i<Ari8mosAutokinhtwn;i++){
        if (AutokinhtaTouTmhmatos[i]->E3odos() == TheshTmhmtatos+1  && AutokinhtaTouTmhmatos[i]->EinaiEtoimo()){
            Autokinhto * ToDelete = AutokinhtaTouTmhmatos[i];
            PosaVghkan++;
            for (int j = i;j<Ari8mosAutokinhtwn-PosaVghkan;j++)
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];
            delete ToDelete;
        }
    }
    int ArxikosAri8mos = Ari8mosAutokinhtwn;
    Ari8mosAutokinhtwn-=PosaVghkan;
    int i;
    for ( i=0;i<Ari8mosAutokinhtwn;i++){
        if (AutokinhtaTouTmhmatos[i]->EinaiEtoimo()){
            if (!Pass(*AutokinhtaTouTmhmatos[i]))
                break;
            Autokinhto * ToDelete = AutokinhtaTouTmhmatos[i];
            PosaVghkan--;
            for (int j = i;j<Ari8mosAutokinhtwn-PosaVghkan;j++)
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];
            delete ToDelete;
        }
    }
    if ( i != Ari8mosAutokinhtwn){
        cout << "Ka8ysterhseis meta ton komvo " << TheshTmhmtatos+1 << "\n" ;
        OlaKala = false;
    }
    Ari8mosAutokinhtwn = ArxikosAri8mos - PosaVghkan;
    if( (AutokinhtaTouTmhmatos=(Autokinhto**)realloc(AutokinhtaTouTmhmatos,Ari8mosAutokinhtwn*sizeof(Autokinhto*)) )== NULL){
        cout << "Provlhma sthn demseush mnhmhs\n";
        exit(-1);
    }
}

bool PrwtoTmhma :: Pass(Autokinhto & NeoAutokinhto){
    return EpomenoTmhma->ValeToAma3i(NeoAutokinhto);
}

bool EndiamesoTmhma :: Pass(Autokinhto & NeoAutokinhto){
    return EpomenoTmhma->ValeToAma3i(NeoAutokinhto);
}

bool TeleutaioTmhma :: Pass(Autokinhto & NeoAutokinhto ){
    return false;
}

bool Tmhma :: ValeToAma3i(Autokinhto & Neo){
    if (Ari8mosAutokinhtwn == Xwrhtikothta)
        return false;
    if ( (AutokinhtaTouTmhmatos = (Autokinhto ** )realloc(AutokinhtaTouTmhmatos,(Ari8mosAutokinhtwn+1)*sizeof(Autokinhto*)) )== NULL){
        cout << "Provlhma sthn demseush mnhmhs\n";
        exit(-1);
    }
    AutokinhtaTouTmhmatos[++Ari8mosAutokinhtwn] = new Autokinhto(Neo);
    AutokinhtaTouTmhmatos[Ari8mosAutokinhtwn]->KantoAnetoimo();
}

void Tmhma :: Enter(){
    int i;
    Autokinhto ** PinakasAutokinhtwn = EisodosTmhmatos->Operate(Ari8mosAutokinhtwn-Xwrhtikothta);
    for ( i=0;i<Ari8mosAutokinhtwn-Xwrhtikothta && PinakasAutokinhtwn[i]->E3odos() != -1;i++)
        ValeToAma3i(*(PinakasAutokinhtwn[i]));
    if ( i != Ari8mosAutokinhtwn - Xwrhtikothta){
        cout << "Ka8ysterhseis sthn eisodo tou komvou " << TheshTmhmtatos << "\n";
        OlaKala = false;
    }
}

void PrwtoTmhma :: Operate(){
    OlaKala = true;
    Exit();
    Enter();
    if (OlaKala)
        cout << "Threite tis apostaseis asfaleias meta ton komvo " << TheshTmhmtatos <<"\n";
}

void EndiamesoTmhma :: Operate(){
    OlaKala = true;
    Exit();
    ProhgoumenoTmhma->Operate();
    Enter();
    if (OlaKala)
        cout << "Threite tis apostaseis asfaleias meta ton komvo " << TheshTmhmtatos <<"\n";
}

void TeleutaioTmhma :: Operate(){
    Exit();
    ProhgoumenoTmhma->Operate();
    Enter();
    cout << "Threite tis apostaseis asfaleias kata thn e3odo\n";
}
