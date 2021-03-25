#include "netutils.h"
#include "shared.h"
#include <sys/socket.h>
#include <sys/types.h>

int send_all(const int sockfd, const char *buffer, const int len) {
  int bytes_left = len, ret = 0, total = 0;
  while (total < len) {
    ret = send(sockfd, buffer + total, bytes_left, 0);
    if (ret == -1)
      break;

    total += ret;
    bytes_left -= ret;
  }
  return ret == -1 ? -1 : 0;
}
