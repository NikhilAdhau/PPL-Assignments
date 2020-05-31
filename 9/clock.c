#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int sec, min, hr;
pthread_mutex_t secLock, minLock;

void* sec_thread (void* arg) {
	while (1){
		sleep(1);
		pthread_mutex_lock(&secLock);
		sec++;
		pthread_mutex_unlock(&secLock);

	}
}

void* min_thread (void* arg) {
	while (1) {
		if (sec == 60) {
			pthread_mutex_lock(&secLock);
			sec = 0;
			pthread_mutex_unlock(&secLock);
			pthread_mutex_lock(&minLock);
			min++;
			pthread_mutex_unlock(&minLock);
		}
	}
}

void* hr_thread (void* arg) {
	while (1) {
		if (min == 60) {
			pthread_mutex_lock(&minLock);
			min = 0;
			pthread_mutex_unlock(&minLock);
			pthread_mutex_lock(&secLock);
			sec = 0;
			pthread_mutex_unlock(&secLock);
			if (hr == 24)
				hr = 0;
			else
				hr++;
		}
	}
}

void* time_thread (void* arg) {
	printf ("Clock - \n");
	while(1) {
		printf("\r[%02d:%02d:%02d]", hr, min, sec);
	}
}

int main() {
	time_t rawtime;
	struct tm *info;
	time( &rawtime );
	info = localtime( &rawtime );
	sec = info->tm_sec;
	min = info->tm_min;
	hr = info->tm_hour;
	pthread_t one, two, three, four;
	pthread_create (&one, NULL, sec_thread, NULL);
	pthread_create (&two, NULL, min_thread, NULL);
	pthread_create (&three, NULL, hr_thread, NULL);
	pthread_create (&four, NULL, time_thread, NULL);

	pthread_join (one, NULL);
	pthread_join (two, NULL);
	pthread_join (three, NULL);
	pthread_join (four, NULL);

	return 0;
}