// clang-format off
#include "types.h"
#include "stat.h"
#include "pstat.h"
#include "user.h"
// clang-format on

int main(int argc, char *argv[]) {
  struct pstat proc = {0};
  if(getpinfo(&proc) < 0) {
    printf(1, "getpinfo failed\n");
    return -1;
  }
  printf(1, "pid  priority  name\n");
  for (int i = 0; i < 64; i++) {
    if (proc.inuse[i]) {
      printf(1, "%d  %d  %s\n", proc.pid[i], proc.priority[i], proc.name[i]);
    }
  }
  exit();
}
