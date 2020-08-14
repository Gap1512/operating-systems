#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>






int main() {
int x = 100;

int rc = fork();

if(rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
  //child
  printf("Old value in child: %d\n", x);
  x = 10;
  printf("New value in child: %d\n", x);
 } else {
  //parent
  printf("Old value in parent: %d\n", x);
  x = 20;
  printf("New value in parent: %d\n", x);
 }
return 0;
}
