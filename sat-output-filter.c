#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

if (argc < 2) {
        printf("You need at least one argument.\n");
        return 1;
} else {
	for(int i = 1; i < argc; i++) {
		if(strcmp(&argv[i][0], "~") == 0){
			printf("%s\n",argv[i]);
		}	
	} 
}
return 0;

}

