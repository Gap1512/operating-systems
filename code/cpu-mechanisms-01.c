#include <stdio.h>
#include <sys/time.h>






int main() {
#define N 1000

struct timeval start_time, end_time;
int i;
long elapsed_time;

gettimeofday(&start_time, NULL);

for(i = 1; i <= N; i++){
  read(0, NULL, 0);
 }

gettimeofday(&end_time, NULL);
elapsed_time = end_time.tv_usec - start_time.tv_usec;

printf("Start: %ldms | End: %ldms | Elapsed: %ldms | N: %d | Average Cost %ldms",
       start_time.tv_usec, end_time.tv_usec, elapsed_time, N,
       (elapsed_time/N));
return 0;
}
