#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PROGRAM_NAME "myecho"
#include <stdbool.h>
#include <string.h>
#define VERSION 1.0
#define STANDARD "https://www.gnu.org/software/coreutils/manual/html_node/echo-invocation.html#echo-invocation"

void process_command(char command[]){
        if (strcmp(command,"--help")==0){
                printf("no\n");
                exit(0);
        }
        else if (strcmp(command,"--version")==0){
                printf("version %f of %s\n",VERSION,PROGRAM_NAME);
                printf("trying to follow POSIX standard : %s\n",STANDARD);
                exit(0);
        }
}
bool validate_proccess_cmd(char C,bool* newline,bool* interp){
        switch (C){
                case 'n':
                        *newline=false;
                        return true;
                case 'e':
                        *interp=true;
                        return true;
                case 'E':
                        *interp=false;
                        return true;
                        break;
                default:
                        return false;
                        break;
        }




}

int base10(int num,int base){
        //convert number from base to base 10
        int index=0;
        int curr=0;
        int sum=0;
        while (num){
                curr=num%10;
                sum=sum+(curr*(pow(base,index)));
                index++;
                num/=10;
        }
        return sum;
}
int proccesschars(char temp[],int* index,int length){
        char build[length];
        for (int i=0;i<length;i++){
                build[i]=temp[*index];
                (*index)++;
        }
        return atoi(build);

}

