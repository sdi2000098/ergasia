#include "AttikhOdos.h"

int main (int argc,char * argv[]){
    if (argc != 5){
        cout << "La8os ari8mos parametrwn\n";
        return -1;
    }
    int N = atoi(argv[1]),NSegs = atoi(argv[2]),K = atoi(argv[3]),Percent = atof(argv[4]);
    AttikhOdos NeaAttikh(NSegs,K,Percent);   
    for (int i =0;i<N;i++){
        NeaAttikh.Operate();
    }
    return 0;
}