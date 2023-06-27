#include "can.h"

void can_init(const char *device, struct can_t *can) {
  can->device = device;
  can->opened = 0;
  can->bytes_exchanged = 0;
}

int can_is_open(struct can_t *can) { return can->opened; }

const char *can_get_device(struct can_t *can) { return can->device; }

int can_open_socket(struct can_t *can) {
  int can_socket;
  struct ifreq ifr;

  can_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
  if (can_socket < 0)
    return -1;

  // If can_socket is set to 0,
  // messages are received from all interfaces (can0, can1, vcan0)
  strcpy(ifr.ifr_name, can->device);
  ioctl(can_socket, SIOCGIFINDEX, &ifr);

  can->address.can_family = AF_CAN;
  can->address.can_ifindex = ifr.ifr_ifindex;

  if (bind(can_socket, (struct sockaddr *)&can->address, sizeof(can->address)) <
      0) {
    return -2;
  }

  can->opened = 1;
  can->sock = can_socket;
  return can_socket;
}

int can_close_socket(struct can_t *can) {
  if (can->opened) {
    if (close(can->sock) < 0) {
      printf("Error closing can socket: %d\n", errno);
      return 0;
    }
  }
  return 1;
}

int can_send(int id, char *data, int len, struct can_t *can) {
  if (len <= 0 || len > 8)
    return -1;

  struct can_frame frame;
  frame.can_id = id;
  frame.can_dlc = len;
  can->bytes_exchanged += len;

  memcpy(frame.data, data, len * sizeof(char));

  return write(can->sock, &frame, sizeof(frame));
}

uint64_t can_get_bytes_exchanged(struct can_t *can) {
  return can->bytes_exchanged;
}

int can_receive(struct can_frame *frame, struct can_t *can) {
  int bytes_read = read(can->sock, frame, sizeof(struct can_frame));
  can->bytes_exchanged += bytes_read;
  return bytes_read;
}

int can_set_filters(struct can_filter *filter, struct can_t *can) {
  return setsockopt(can->sock, SOL_CAN_RAW, CAN_RAW_FILTER, filter,
                    sizeof(filter));
}