#ifndef CAN_DATA_H
#define CAN_DATA_H

#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <inttypes.h>

#include "steering/steering.h"

// CAN libraries (can_utils)
#include <linux/can.h>
#include <linux/can/raw.h>

//#include "can/lib/primary/c/ids.h"
//#include "can/lib/secondary/c/ids.h"

#include "can/lib/primary/primary_network.h"
#include "can/lib/secondary/secondary_network.h"

#include "can.h"
#include "queue.h"

typedef uint16_t can_id_t;

typedef struct {
  can_id_t id;
  uint8_t size;
  uint8_t data[8];
} can_message_t;


void can_handle_primary(struct can_frame frame);


void update_lv_temp(uint8_t val);


void can_handle_secondary(struct can_frame frame);

char* car_status_to_string(int car_status);



#endif