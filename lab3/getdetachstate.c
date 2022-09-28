#include <pthread.h>
#include <stdlib.h>

/* attr: Con tro tro toi p_thread_attr_t, no la thuoc tinh duoc dung khi tao tieu trinh moi
   detach state: Gia tri moi cho trang thai detach tieu trinh (joinable va detached) */
int pthread_attr_getdetachstate(const pthread_attr_t *tattr, int *detachstate);

int main(){
	pthread_attr_t tattr;
	int detachstate;
	int ret;
	/*Tra ve gia tri trang thai detach cua pthread*/
	ret = pthread_attr_getdetachstate(&tattr, &detachstate);
}
