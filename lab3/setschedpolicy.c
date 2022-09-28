#include <pthread.h>
#include <stdlib.h>

/* attr: Con tro tro toi p_thread_attr_t, no la thuoc tinh duoc dung khi tao tieu trinh moi
   policy: Gia tri moi cho chinh sach lap lich
   	+ SCHED_FIFO: Lap lich First-in first-out
   	+ SCHED_RR: Lap lich Round Robin
   	+ SCHED_OTHER: thuong thi giong voi SCHED_RR
   	+ SCHED_NOCHANGE: Khong thay doi chinh sach
   	+ SCHED_SPORADIC: Lap lich roi rac */
int pthread_attr_setschedpolicy(pthread_attr_t *tattr, int policy);

int main(){
	pthread_attr_t tattr;
	int policy;
	int ret;
	/* Thiet lap chinh sach lap lich den SCHED__FIFO */
	ret = pthread_attr_setschedpolicy(&tattr, SCHED_FIFO);
}
