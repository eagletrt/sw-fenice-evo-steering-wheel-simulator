#! /bin/sh

sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link add dev vcan1 type vcan

sudo ip link set vcan0 up
sudo ip link set vcan1 up
