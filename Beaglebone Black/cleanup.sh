#! /bin/sh
#
# clean up after the flasher
#
cd /sys/class/gpio
echo 49 > unexport

