#! /bin/sh
#
# flash a gpio-based LED every second
#
cd /sys/class/gpio
echo 49 > export
cd gpio49
echo out > direction
while :
do
    echo 1 > value
    sleep 1
    echo 0 > value
    sleep 1
done
