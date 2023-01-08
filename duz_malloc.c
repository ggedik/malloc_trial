#include <stdlib.h>

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