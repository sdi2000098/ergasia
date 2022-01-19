#include "tmhma.h"

using namespace std;
float Tmhma :: Percent=0;
Tmhma :: Tmhma(int xwros ,int Thesh,float NewPercent) : Xwrhtikothta(xwros),TheshTmhmtatos(Thesh){
    Percent = NewPercent;
    Ari8mosAutokinhtwn = rand()%Xwrhtikothta+1;     // Tyxaia dhmiourgountai autokinhta sto tmhma
    AutokinhtaTouTmhmatos = new Autokinhto*[Ari8mosAutokinhtwn];
};

PrwtoTmhma :: PrwtoTmhma(int Xwros,int NNSegs,int NewK,float NewPercent) : Tmhma(Xwros,0,NewPercent){
    for ( int i = 0 ;i<Ari8mosAutokinhtwn;i++)
        AutokinhtaTouTmhmatos[i] = new Autokinhto(rand()%NNSegs+1,0);
    for ( float i = 0;i<Ari8mosAutokinhtwn*Percent/100;i++){        // Kapoia apo tas autokinhta ginontai etoima
        int neo = rand()%Ari8mosAutokinhtwn;
        if (AutokinhtaTouTmhmatos[neo]->EinaiEtoimo())      // An htan hdh etoimo epanalave
            i--;
        else
            AutokinhtaTouTmhmatos[neo]->KantoEtoimo();
    }
    EisodosTmhmatos = new Eisodos(0,NNSegs,NewK);
    cout << "Kataskeuasthke to prwto tmhma\n";
};
// Idia diadikasia me pio panw
TeleutaioTmhma :: TeleutaioTmhma(Tmhma * Prev,int Xwros,int NSegs,int NewK,float NewPercent) : Tmhma(Xwros,NSegs-1,NewPercent),ProhgoumenoTmhma(Prev){
    for ( int i = 0 ;i<Ari8mosAutokinhtwn;i++)
        AutokinhtaTouTmhmatos[i] = new Autokinhto(NSegs,NSegs-1);
    for ( float i = 0;i<Ari8mosAutokinhtwn*Percent/100;i++){
        int neo = rand()%Ari8mosAutokinhtwn;
        if (AutokinhtaTouTmhmatos[neo]->EinaiEtoimo())
            i--;
        else
            AutokinhtaTouTmhmatos[neo]->KantoEtoimo();
    }
    EisodosTmhmatos = new Eisodos(NSegs-1,NSegs,NewK);
    ProhgoumenoTmhma->OriseEpomeno(this);
    cout << "Kataskeuasthke to teleutaio tmhma\n";
};
// Idia diadikasia me pio panw mono pou twra h thesh dinetai san orisma
EndiamesoTmhma :: EndiamesoTmhma(Tmhma* Prev,int Xwros,int Thesh,int NSegs,int NewK,float NewPercent) :
    Tmhma(Xwros,Thesh,NewPercent),ProhgoumenoTmhma(Prev){
    for ( int i = 0 ;i<Ari8mosAutokinhtwn;i++)
        AutokinhtaTouTmhmatos[i] = new Autokinhto(rand()%(NSegs-TheshTmhmtatos)+TheshTmhmtatos+1,TheshTmhmtatos);
    for ( float i = 0;i<Ari8mosAutokinhtwn*Percent/100;i++){
        int neo = rand()%Ari8mosAutokinhtwn;
        if (AutokinhtaTouTmhmatos[neo]->EinaiEtoimo())
            i--;
        else
            AutokinhtaTouTmhmatos[neo]->KantoEtoimo();
    }
    EisodosTmhmatos = new Eisodos(TheshTmhmtatos,NSegs,NewK);
    ProhgoumenoTmhma->OriseEpomeno(this);
    cout << "Kataskeuasthke to "<< TheshTmhmtatos+1 << "o tmhma\n";
}
// Virtual destruvtor tou tmhmatos, se auth thn fash diagrafei mono ton xwro pou desmeuthke gia thn  eisodo
Tmhma :: ~Tmhma(){
    delete EisodosTmhmatos;
}
// O Destructor ths ka8e ypoklashs katastrefei ta autokinhta tou tmhmatos
EndiamesoTmhma ::~EndiamesoTmhma(){
    for (int i = 0;i<Ari8mosAutokinhtwn;i++)
        delete AutokinhtaTouTmhmatos[i];
    delete []AutokinhtaTouTmhmatos;
    cout << "Katastrafhke to " << TheshTmhmtatos+1 << " tmhma\n";
}

TeleutaioTmhma :: ~TeleutaioTmhma(){
    for (int i = 0;i<Ari8mosAutokinhtwn;i++)
        delete AutokinhtaTouTmhmatos[i];
    delete []AutokinhtaTouTmhmatos;
    cout << "Katastrafhke to teleutaio tmhma\n";
}

PrwtoTmhma :: ~PrwtoTmhma(){
    for (int i = 0;i<Ari8mosAutokinhtwn;i++)
        delete AutokinhtaTouTmhmatos[i];
    delete []AutokinhtaTouTmhmatos;
    cout << "Katastrafhke to prwto tmhma\n";
}

void PrwtoTmhma :: Exit(){      // Ta autokinhta pou einai se katastash etoimothtas e3erxontai
    int PosaVghkan = 0,PosaHtanEtoima=0,PosaVghkanSynolika;
    Autokinhto ** ToDelete = new Autokinhto*[Ari8mosAutokinhtwn];       // Dhmiourgeitai o pinakas me deiktes se autokinhta pou prokeitai na vgoun,to poly to plh8os twn autokinhtwn tou tmhmatos
    for (int i = 0;i<Ari8mosAutokinhtwn-PosaVghkan;i++){            // H metavlhth PosaVghkan voh8a etsi wste na mhn prospa8hsoume na bgaloume autokinhta pou exoun hdh vgei
        if ( AutokinhtaTouTmhmatos[i]->EinaiEtoimo() && AutokinhtaTouTmhmatos[i]->E3odos() == 1){   // Afou vriskomaste sto prwto tmhma osa autokinhta exiun e3odo thn eisodo 1 vgainoun
            PosaHtanEtoima++;
            ToDelete[PosaVghkan++] = AutokinhtaTouTmhmatos[i];
            for (int j = i--;j<Ari8mosAutokinhtwn-PosaVghkan;j++)  // Ta autokinhta metakinountai mia 8es mprosta ston pinaka. To i-- mas diasfalizei oti den 8a paraleipsoume kanena autokinhto
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];    
        }
    }
    for (int i =0;i<PosaVghkan;i++)     // Diagrafei ta autokinhta
        delete ToDelete[i];
    Ari8mosAutokinhtwn-=PosaVghkan;
    PosaVghkanSynolika=PosaVghkan;
    PosaVghkan = 0;
    int i;
    for ( i=0;i<Ari8mosAutokinhtwn-PosaVghkan;i++){     // H idia diadikasia epanalamvanetai alla twra ta autokinhta pou einai etoima pernane sto epomeno tmhma
        if (AutokinhtaTouTmhmatos[i]->EinaiEtoimo()){
            PosaHtanEtoima++;
            if (!Pass(*AutokinhtaTouTmhmatos[i]))       // Ama h Pass epistrepsei timh la8ous shmainei oti to epomeno tmhma gemise
                break;
            ToDelete[PosaVghkan++] = AutokinhtaTouTmhmatos[i];
            for (int j = i--;j<Ari8mosAutokinhtwn-PosaVghkan;j++)
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];
        }
    }
    for (int i =0;i<PosaVghkan;i++)     // Diegrapse apo to trexwn tmhma ta autokinhta pou perasan sto epomeno 
        delete ToDelete[i];
    delete []ToDelete;
    PosaVghkanSynolika+=PosaVghkan;
    if ( PosaVghkanSynolika != PosaHtanEtoima){     // Den perasan osa htan etoima
        cout << "Ka8ysterhseis meta ton komvo 0\n" ;
        cout << Ari8mosAutokinhtwn << "\n";
        OlaKala = false;
    }
    Ari8mosAutokinhtwn -= PosaVghkan;
    if (!Ari8mosAutokinhtwn){   //Katallhla 8a desmeutei o xwros pou apaiteitai gia ta autokinhta
        AutokinhtaTouTmhmatos = NULL;
        return;
    }
    if( (AutokinhtaTouTmhmatos=(Autokinhto**)realloc(AutokinhtaTouTmhmatos,Ari8mosAutokinhtwn*sizeof(Autokinhto*)) )== NULL){
        cout << "Error in allocating memory\n";
        exit(-1);
    }
}
// Idia diadikasia me parapanw mono pou twra to deutero tmhma ths synarthshs den ylopoieitai afou den yparxei epomeno tmhma
void TeleutaioTmhma :: Exit(){
    int PosaVghkan = 0;
    Autokinhto ** ToDelete = new Autokinhto*[Ari8mosAutokinhtwn];
    for (int i = 0;i<Ari8mosAutokinhtwn-PosaVghkan;i++){
        if ( AutokinhtaTouTmhmatos[i]->EinaiEtoimo()){
            ToDelete[PosaVghkan++] = AutokinhtaTouTmhmatos[i];
            for (int j = i--;j<Ari8mosAutokinhtwn-PosaVghkan;j++)
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];
        }
    }
    for (int i =0;i<PosaVghkan;i++)
        delete ToDelete[i];
    delete []ToDelete;
    Ari8mosAutokinhtwn-=PosaVghkan;
    if (!Ari8mosAutokinhtwn){
        AutokinhtaTouTmhmatos = NULL;
        return;
    }
    if( (AutokinhtaTouTmhmatos=(Autokinhto**)realloc(AutokinhtaTouTmhmatos,Ari8mosAutokinhtwn*sizeof(Autokinhto*)) )== NULL){
        cout << "Error in allocating memory\n";
        exit(-1);
    }
    
}
// Akrivws h idia diadikasia me to prwto tmhma mono pou twra koitame an h e3odos tou autokinhtou einai ish me thn thesh tmhmatos +1
void EndiamesoTmhma :: Exit(){
    int PosaVghkan = 0,PosaHtanEtoima=0,PosaVghkanSynolika;
        Autokinhto ** ToDelete = new Autokinhto*[Ari8mosAutokinhtwn];
    for (int i = 0;i<Ari8mosAutokinhtwn-PosaVghkan;i++){
        if ( AutokinhtaTouTmhmatos[i]->EinaiEtoimo() && AutokinhtaTouTmhmatos[i]->E3odos() == TheshTmhmtatos+1){
            PosaHtanEtoima++;
            ToDelete[PosaVghkan++] = AutokinhtaTouTmhmatos[i];
            for (int j = i--;j<Ari8mosAutokinhtwn-PosaVghkan;j++)
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];
        }
    }
    for (int i =0;i<PosaVghkan;i++)
        delete ToDelete[i];
    Ari8mosAutokinhtwn-=PosaVghkan;
    PosaVghkanSynolika=PosaVghkan;
    PosaVghkan = 0;
    int i;
    for ( i=0;i<Ari8mosAutokinhtwn-PosaVghkan;i++){
        if (AutokinhtaTouTmhmatos[i]->EinaiEtoimo()){
            PosaHtanEtoima++;
            if (!Pass(*AutokinhtaTouTmhmatos[i]))
                break;
            ToDelete[PosaVghkan++] = AutokinhtaTouTmhmatos[i];
            for (int j = i--;j<Ari8mosAutokinhtwn-PosaVghkan;j++)
                AutokinhtaTouTmhmatos[j]=AutokinhtaTouTmhmatos[j+1];
        }
    }
    for (int j =0;j<PosaVghkan;j++)
        delete ToDelete[j];
    delete []ToDelete;
    PosaVghkanSynolika+=PosaVghkan;
    if ( PosaVghkanSynolika != PosaHtanEtoima){
        cout << "Ka8ysterhseis meta ton komvo " << TheshTmhmtatos+1 << "\n" ;
        cout << Ari8mosAutokinhtwn <<"\n";
        OlaKala = false;
    }
    Ari8mosAutokinhtwn -= PosaVghkan;
    if (!Ari8mosAutokinhtwn){
        AutokinhtaTouTmhmatos = NULL;
        return;
    }
    if( (AutokinhtaTouTmhmatos=(Autokinhto**)realloc(AutokinhtaTouTmhmatos,Ari8mosAutokinhtwn*sizeof(Autokinhto*)) )== NULL){
        cout << "Provlhma sthn demseush mnhmhs\n";
        exit(-1);
    }
}
// H Pass dexetai ena autokinhto kai xrhsimopoiei mia allh synarthsh gia na valei to ama3i sto epomeno tmhma. 
//Epistrefei false se periptwsh pou gemise to epomeno tmhma
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
    // Dhmiourgei xwro gia to neo autokinhto
    if ( (AutokinhtaTouTmhmatos = (Autokinhto ** )realloc(AutokinhtaTouTmhmatos,(Ari8mosAutokinhtwn+1)*sizeof(Autokinhto*)) )== NULL){
        cout << "Provlhma sthn demseush mnhmhs\n";
        exit(-1);
    }
    AutokinhtaTouTmhmatos[Ari8mosAutokinhtwn] = new Autokinhto(Neo);
    AutokinhtaTouTmhmatos[Ari8mosAutokinhtwn]->KantoAnetoimo();     // Arxika den einai etoimo kai h thesh tou allazei
    AutokinhtaTouTmhmatos[Ari8mosAutokinhtwn++]->Alla3eThnThesh(TheshTmhmtatos);
    return true;        // H eisagwgh petyxe
}

void Tmhma :: Enter(){
    int i;
    Autokinhto ** PinakasAutokinhtwn = EisodosTmhmatos->Operate(Xwrhtikothta-Ari8mosAutokinhtwn,OlaKala);       
    // Zhta apo thn Operate to plh8os twn ama3iwn wste na mhn ypervei thn xwrhtikothta
    for ( i=0; (i<Xwrhtikothta-Ari8mosAutokinhtwn) && (PinakasAutokinhtwn[i]->E3odos() != -1);i++)
        ValeToAma3i(*(PinakasAutokinhtwn[i]));
    // H epanalhpsh auth theleiwnei eite otan gemise to tmhma eite otan den yparxoun alla autokinhta na vgoun apo ta diodia
    // Autokinhta me e3odo -1 shmainei oti einai to teleutaio apo ta diodia
}
// H ylopoihsh ths operate tou tmhmatos vasei thn ekfwnhsh
void PrwtoTmhma :: Operate(){
    OlaKala = true;
    Exit();
    Enter();
    if (OlaKala)
        cout << "Threite tis apostaseis asfaleias meta ton komvo 0\n";
    for ( float i = 0;i<Ari8mosAutokinhtwn*Percent/100;i++){        // To percent % twn autokinhtwn ginontai etoimo
        int neo = rand()%Ari8mosAutokinhtwn;
        if (AutokinhtaTouTmhmatos[neo]->EinaiEtoimo())
            i--;
        else
            AutokinhtaTouTmhmatos[neo]->KantoEtoimo();
    }
}

void EndiamesoTmhma :: Operate(){
    OlaKala = true;
    Exit();
    ProhgoumenoTmhma->Operate();    // Afou vgoun ta autokinhta tou tmhmatos kane thn operate tou prohgoumenou
    Enter();
    if (OlaKala)
        cout << "Threite tis apostaseis asfaleias meta ton komvo " << TheshTmhmtatos <<"\n";
    for ( float i = 0;i<Ari8mosAutokinhtwn*Percent/100;i++){
        int neo = rand()%Ari8mosAutokinhtwn;
        if (AutokinhtaTouTmhmatos[neo]->EinaiEtoimo())
            i--;
        else
            AutokinhtaTouTmhmatos[neo]->KantoEtoimo();
    }    
}

void TeleutaioTmhma :: Operate(){
    OlaKala = true;
    Exit();
    ProhgoumenoTmhma->Operate();
    Enter();
    if (OlaKala)
        cout << "Threite tis apostaseis asfaleias meta ton komvo " << TheshTmhmtatos <<"\n";
    for ( float i = 0;i<Ari8mosAutokinhtwn*Percent/100;i++){
        int neo = rand()%Ari8mosAutokinhtwn;
        if (AutokinhtaTouTmhmatos[neo]->EinaiEtoimo())
            i--;
        else
            AutokinhtaTouTmhmatos[neo]->KantoEtoimo();
    }
}
// Dyo voh8htikes synarthsei pou apla orizoun to epomeno tmhma tou trexwn tmhmatos+

void EndiamesoTmhma ::OriseEpomeno( Tmhma * Epomeno) {
    EpomenoTmhma = Epomeno;
}

void PrwtoTmhma ::OriseEpomeno( Tmhma * Epomeno) {
    EpomenoTmhma = Epomeno;
}
