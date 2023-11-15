#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"
#define PROGRAM_NAME "myecho"
int main(int argc, char **argv){
	
	bool newline=true;//set to true intialy changed if -n is used
	bool interp=false;
	if (argc==1){
		printf("Usage : %s [OPTIONS]\n",PROGRAM_NAME);
		return 0;
	}
	bool posixly_correct = !!getenv ("POSIXLY_CORRECT");	
       	bool allow=true;
	if (strcmp(argv[1],"-n")==1 && posixly_correct){
		allow=false;
	}
	
	process_command(argv[1]);// for --help or --version
	char C;
	if (allow){//If the POSIXLY_CORRECT environment variable is set, then when echo’s first argument is not -n it outputs option-like arguments instead of treating them as options.
	while (argv[1][0]=='-'){
		C=argv[1][1];
		if(validate_proccess_cmd(C,&newline,&interp)){
			argv++;
			argc--;	
		}
		else{
			argv++;
			argc--;
			break;
		}
	}
	}
	

	argv++;
	argc--;
	//parsed all args

	while (argc>0){		
               	if (interp){
			int size=strlen(argv[0]);
			//printf("size of %s is %d\n",argv[0],size);
			char temp[size];
			char C;
			strcpy(temp,argv[0]);
			for (int i=0;i<size;i++){
				C=temp[i];
				if ('\\'==C){
				    i++;
				    C=temp[i];
				    switch (C){
				        case 'b':C='\b';break;
					case 'a':C='\a';break;
					case 'c':exit(0);break;
					case 'e':C='\e';break;
					case 'f':C='\f';break;
					case 'n':C='\n';break;
					case 'r':C='\r';break;
					case 't':C='\t';break;
					case 'v':C='\v';break;
					case '0':i++;C=base10(proccesschars(temp,&i,3),8); break;
					case 'x':i++;C=base10(proccesschars(temp,&i,2),16);break;
					default: break;
				    }	
				}
				putchar(C);
			}
			argv++;
			argc--;
			if (argc>0){
				putchar(' ');
			}

			
		}
		else{//no options given just print everything
       	        	printf("%s",argv[0]);
			argc--;
			argv++;
			if (argc>0){
				putchar(' ');	
			}
		}
	}

	if (newline){
		printf("\n");
	}
	exit(0);
		

}




