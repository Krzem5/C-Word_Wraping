#include <word_wraping.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc,const char** argv){
	const char* str="111 22 33 4444";
	word_wrap_data_t dt;
	wrap_words(str,6,&dt);
	uint32_t* v=dt.l;
	uint32_t i=0;
	while (*str){
		char c=*str;
		if (v&&c==' '){
			i++;
			if (*v==i){
				putchar('\n');
				v++;
				dt.ll--;
				if (!dt.ll){
					v=NULL;
				}
			}
			else{
				putchar(' ');
			}
		}
		else{
			putchar(c);
		}
		str++;
	}
	free(dt.l);
	return 0;
}
