#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <linux/input.h>
#include <time.h>
#include <termios.h>
#include <linux/uinput.h>

static struct input_event evt;
static int fd;

int open_mice(void)
{
  fd = open("/dev/input/event0", O_RDWR );
  return fd;
}

void close_mice(int fd)
{
  close(fd);
}

struct input_event* read_event(int fd_lua)
{
  if ( read(fd, &evt, sizeof(evt)) < 0 )
    perror("can't read mice");
  return &evt;
}

