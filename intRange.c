#include <stdio.h>

void main(int argc, char **argv){
	signed int a = 0;
	for(a; a < 256; a++){
		printf( "%d\n", sizeof(a) );
	}
}