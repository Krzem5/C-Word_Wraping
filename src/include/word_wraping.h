#ifndef __WORD_WRAPING_H__
#define __WORD_WRAPING_H__ 1
#include <stdint.h>



typedef struct __WORD_WRAP_DATA{
	uint32_t ll;
	uint32_t* l;
} word_wrap_data_t;



void wrap_words(const char* dt,uint32_t l,word_wrap_data_t* o);



#endif
