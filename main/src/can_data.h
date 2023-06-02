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

#include "can/lib/primary/c/ids.h"
#include "can/lib/secondary/c/ids.h"

#include "can/lib/primary/c/network.h"
#include "can/lib/secondary/c/network.h"

#include "can.h"
#include "queue.h"



void can_handle_primary(struct can_frame frame);


void update_lv_temp(uint8_t val);





#endif