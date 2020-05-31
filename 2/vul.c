#include <stdio.h>
#include <string.h>
#define SECURITY_CODE "12345"

int check (char *argv){
	int pass = 0;
	char buf[10];
	strcpy (buf, argv[1]);
	if (!strcmp(buf, SECURITY_CODE)) {
		pass = 1;
	}
	
}

int main (int argc, char **argv) {
	if (check(argv[1])) {
		printf ("Access permitted!!!\n");
	}
	else{
		printf("Access denied!!\n");
	}
	check(pass);
	return 0;

}