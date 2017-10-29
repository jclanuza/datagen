#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define version 1.2

FILE *buffer;

void gendata(int,int,char*);

int main(void)
{
	int data_type, data_size;
	char data_name[50];
	fprintf(stdout,"Precise Data Generator %.1f\n"
		       "------------------------------\n\n",version);
	fprintf(stdout,"Type of size file | (0)Bytes - (1) KB - (2) MB - (3) GB : ");
	scanf("%d",&data_type);
	fprintf(stdout,"File Size: ");
	scanf("%d",&data_size);
	fprintf(stdout,"Name of Data: ");
	scanf("%s",data_name);
	puts("------------------------------\n"
	     "Generating Data, Please wait !");
	gendata(data_type, data_size, data_name);
	
	exit(EXIT_SUCCESS);
}
void gendata(int data_type,int data_size,char *data_name)
{
	buffer = fopen(data_name,"w");
	if(buffer == NULL) { fputs("File Error",stderr); exit(EXIT_FAILURE); }
	switch(data_type)
	{
		case 0: { /* bytes */
			srand(time(NULL));
			for(long long i = 1;i <= data_size;i++)
			putc((char)(65 + rand() % 122),buffer);
			break;
		}
		case 1: { /* Kilobytes */
				#define kb 1024
				srand(time(NULL));
				for(long long i = 1;i <= (data_size * kb);i++)
				putc((char)(65 + rand() % 122),buffer);				
				break;
			}
		case 2: { /* Megabytes */
				#define mb 1048576
				srand(time(NULL));
				for(long long i = 1;i <= (data_size * mb);i++)
				putc((char)(65 + rand() % 122),buffer);				
			break;
		}
		case 3: { /* Gigabytes */
				#define gb 1073741824
				srand(time(NULL));
				for(long long i = 1;i <= (data_size * gb);i++)
				putc((char)(65 + rand() % 122),buffer);	
			break;
		}
		default: {
			fprintf(stdout,"This is not an option bro :v\n");
			break;
		}
	}	
}
