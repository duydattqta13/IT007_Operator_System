#include <pthread.h>
#include <stdlib.h>

/* attr: Con tro tro toi p_thread_attr_t, no la thuoc tinh duoc dung khi tao tieu trinh moi
   scope: Gia tri moi cho thuoc tinh co gioi han rang buoc */
int pthread_attr_setscope(pthread_attr_t *tattr, int scope);

int main(){
	pthread_attr_t tattr;
	int ret;
	/*Tao Tieu trinh gioi han*/
	ret = pthread_attr_setscope(&tattr, PTHREAD_SCOPE_SYSTEM);
	/*Tao Tieu trinh khong gioi han*/
	ret = pthread_attr_setscope(&tattr, PTHREAD_SCOPE_PROCESS);
}
