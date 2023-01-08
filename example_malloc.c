#include <stdio.h>
#include <stdlib.h>

//we can even make research on caches to see the behaviour
//give information about the ram size, ram usage, why did we choose this specific sizes etc 
//explain what this code does 
//compiler options for ram usage falan varsa onlara bak ya da optimizayonlarda gelen bir sey varsa
//ben simdilik dumduz massif tutorial ile gidiyorum
//niye extra bytes lar atanmis bunlarin nedeni ne olabilir ==> alignement
//proper make file yaz 
//script yaz makefile i da icinden cagir ve valgrid massif opsiyonlarini gecir 


void func1(void){
    malloc(100000); 
}
void func2(void){
    malloc(2000);
    func1();  
}
int main(void){

    int i; 
    int* a[10]; 

    for (i = 0;  i < 10; i++){
        a[i] = malloc(1000);
    }
    func1();
    func2();

    for(i = 0; i <10; i++){
        free(a[i]);
    }
    
    return 0;
}