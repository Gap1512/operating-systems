#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>






int main() {
int file = open("./cpu-api-02.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
assert(file > -1);

int rc = fork();
int counter = 0;

if(rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
  //child
  counter = write(file, "print from child\n", 17);
  assert(counter == 17);
  close(file);
 } else {
  //parent
  counter = write(file, "print from parent\n", 18);
  assert(counter == 18);
  close(file);
 }
return 0;
}
