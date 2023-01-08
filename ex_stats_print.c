#include <stdlib.h>
#include <jemalloc/jemalloc.h>

void func1(void){
    je_malloc(100000); 
}
void func2(void){
    je_malloc(2000);
    func1();  
}
int main(void){

    int i; 
    int* a[10]; 

    for (i = 0;  i < 10; i++){
        a[i] = je_malloc(1000);
    }
    func1();
    func2();

    for(i = 0; i <10; i++){
        je_free(a[i]);
    }
    
    return 0;
}

/*gcc ex_stats_print.c -o ex_stats_print -I`jemalloc-config --includedir` -L`jemalloc-config --libdir` -Wl,-rpath,`jemalloc-config --libdir` -ljemalloc `jemalloc-config --libs`
*/