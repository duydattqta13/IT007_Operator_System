#include <pthread.h>
#include <stdio.h>

/* attr: Con tro tro toi p_thread_attr_t, no la thuoc tinh duoc dung khi tao tieu trinh moi */
int pthread_attr_destroy(pthread_attr_t *tattr);

int main(){
	pthread_attr_t tattr;
	int ret;
	/* Xoa bo du lieu duoc phan bo trong qua trinh khoi tao */
	ret = pthread_attr_destroy(&tattr);
}
