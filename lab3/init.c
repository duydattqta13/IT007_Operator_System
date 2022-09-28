#include <pthread.h>
#include <stdlib.h>

/* tattr: Con Tro tro toi pthread_arrt_t can khoi tao*/
/* Khoi tao thuoc tinh cho gia tri mac dinh */
int pthread_attr_init(pthread_attr_t *tattr);
int main(){
	pthread_attr_t tattr;
	int ret;
	ret = pthread_attr_init(&tattr);
}

