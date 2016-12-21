#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main(int argc, char *argv[]){


char *raw, *mpg;

char comando[100];

raw = (char*)malloc(sizeof(char)*strlen(argv[1]));
mpg = (char*)malloc(sizeof(char)*strlen(argv[2]));

strcpy(raw,argv[1]);
strcpy(mpg,argv[2]);

printf("%s,%s\n",raw,mpg);


strcpy(comando,"/usr/bin/ffmpeg -i ");
strcat(comando,raw);
printf("%s\n",comando);

strcat(comando," -c:v  mpeg2video  -s 1280x720 -y ");
strcat(comando,mpg);

printf("%s\n",comando);
system(comando);

}



