#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>






int main() {
#define N 1000

struct timeval start_time, end_time;
long elapsed_time;
int i, fd1[2], fd2[2], rc1, rc2;

rc1 = fork();

if ((pipe(fd1) == -1) || (pipe(fd2) == -1)) {
  fprintf(stderr, "pipe failed\n");
  exit(1);
 }

if (rc1 < 0) {
  fprintf(stderr, "fork 1 failed\n");
  exit(1);
 } else if (rc1 == 0) {
  for(i = 1; i <= N; i++){
    close(fd2[0]);
    close(fd1[1]);
    read(fd1[0], NULL, 0);
    write(fd2[1], NULL, 0);
  }
 } else {
  rc2 = fork();

  if (rc2 < 0) {
    fprintf(stderr, "fork 2 failed\n");
    exit(1);
  } else if (rc2 == 0) {
    for(i = 1; i <= N; i++){
      close(fd2[1]);
      close(fd1[0]);
      read(fd2[0], NULL, 0);
      write(fd1[1], NULL, 0);
    }
  } else {
    gettimeofday(&start_time, NULL);

    wait(NULL);

    gettimeofday(&end_time, NULL);
    elapsed_time = end_time.tv_usec - start_time.tv_usec;

    close(fd1);
    close(fd2);

    printf("Start: %ldms | End: %ldms | Elapsed: %ldms | N: %d | Average Cost %ldms",
	   start_time.tv_usec, end_time.tv_usec, elapsed_time, N,
	   (elapsed_time/N));
  }
 }
return 0;
}
