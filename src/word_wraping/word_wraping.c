#include <word_wraping.h>
#include <stdint.h>
#include <stdlib.h>



void wrap_words(const char* dt,uint32_t w,word_wrap_data_t* o){
	uint32_t* l=malloc(sizeof(uint32_t));
	uint32_t ll=1;
	const char* s=dt;
	uintptr_t st=(uintptr_t)dt;
	while (*s){
		if (*s==' '){
			*(l+ll-1)=(uint32_t)((uintptr_t)s-st)+1;
			do{
				s++;
			} while (*s==' ');
			if (!(*s)){
				goto _skip_last;
			}
			ll++;
			l=realloc(l,ll*sizeof(uint32_t));
			st=(uintptr_t)s;
			continue;
		}
		s++;
	}
	*(l+ll-1)=(uint32_t)((uintptr_t)s-st)+1;
_skip_last:;
	uint32_t* sc=malloc(ll*sizeof(uint32_t));
	*(sc+ll-1)=0;
	o->l=malloc(ll*sizeof(uint32_t));
	*(o->l+ll-1)=ll;
	uint32_t i=ll-1;
	while (i){
		i--;
		*(sc+i)=UINT32_MAX;
		uint32_t j=-1;
		for (uint32_t k=i;k<ll;k++){
			j+=*(l+k);
			if (j>w){
				break;
			}
			uint32_t c_sc=(k==ll-1?0:(w-j)*(w-j)*(w-j)+(*(sc+k+1)));
			if (c_sc<*(sc+i)){
				*(sc+i)=c_sc;
				*(o->l+i)=k+1;
			}
		}
	}
	free(l);
	free(sc);
	i=0;
	uint32_t j=0;
	while (i<ll){
		i=*(o->l+i);
		j++;
	}
	o->ll=j;
}
