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

strcat(comando," -c:v  copy  -flags -global_header -map 0 -f segment -segment_time 10 -segment_list ");
strcat(comando,mpg);
strcat(comando," -segment_format mpegts stream%02d.ts");
printf("%s\n",comando);
system(comando);

}



