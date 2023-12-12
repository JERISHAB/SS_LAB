#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *obj;     // 
char record[100],textrecord[100];

int   start,length,  ind, new_loc;

int main(){

    obj = fopen("obj2.txt", "r");
    fscanf(obj, "%s", record);

        printf("Location\tObject Code\n");
        while(record[0] != 'E'){
            ind = 0;
            if (record[0] == 'T'){

                fscanf(obj, "%x\t%x\t%s",&start,&length,textrecord );

                    new_loc = start;

                while(textrecord[ind] != '$'){
                    if(textrecord[ind] == '^'){
                        ind++;
                    }
                    else{
                        printf("%06x  \t   %c%c\n", new_loc, textrecord[ind], textrecord[ind+1]);
                        ind +=2;
                        new_loc += 1;
                    }
                }
            }
            fscanf(obj, "%s", record);
        }
    

    return 0;
}
