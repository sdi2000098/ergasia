#include "diodio.h"

class Eisodos{
    private:
        int Thesh;
        int K;
        DiodioMeYpallhlo ** TaDiodiaMeYpallhlo;
        HelktronikoDiodio ** TaHlektronikaDiodia;
        int Plh8osMeYpallhlo,Plh8osHlektronikwn;        //Diodiwn
    public :
        Eisodos(int Th,int NNSegs,int NewK);
        ~Eisodos();
        void Pros8esh(Autokinhto &) ;
        Autokinhto  AfaireseApoYpallhlo();      // Oi dyo synarthseis afaireshs epistrefoun autokinhto me e3odo -1 se
        Autokinhto  AfaireseApoHlektroniko() ;  // periptwsh pou den yparxei autokinhto na afairesoun apo to diodio
        Autokinhto ** Operate(int PosaNaVgoun,bool & OlaKala);  
        // H operate pairnei ws parametrous to plh8os twn autokinhtwn pou prepei na vgoun kai mia anafora se mia bool
        // H teleutaia einai ypeu8hnh gia thn swsth emfanish twn mhnymatwn
        // Epistrefei enan pinaka me autokinhta ta opoia vghkan apo thn eisodo (dhladh apo ta diodia ths eisodou)
        static int NSegs,SeiraYpallhlou,SeiraHlektronikou;
        // H dyo teleutaies metavlhtes voh8ane wste ka8e fora na e3erxetai ama3i apo diaforetiko diodio       
};
