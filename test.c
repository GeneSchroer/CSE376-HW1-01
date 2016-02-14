#include <stdio.h>
#include <unistd.h>



int main (int argc, char argv[]){



extern int opind;
int i = 0;

for( i; i< argc; ++i){

printf("%c\n", getopt(argc, &argv, "abcd"));


}



return 0;
}
