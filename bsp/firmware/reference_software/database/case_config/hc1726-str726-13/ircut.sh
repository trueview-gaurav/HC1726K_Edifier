#!/bin/sh
# IR CUT filter control test
# Usage: ./ircut.sh <day|night|idle>

GPIO_P=41
GPIO_N=42
GPIO_PATH="/sys/class/gpio"

gpio_export() {
    if [ ! -d "$GPIO_PATH/gpio$1" ]; then
        echo "$1" > "$GPIO_PATH/export"
        sleep 0.1
    fi
    echo "out" > "$GPIO_PATH/gpio$1/direction"
}

gpio_set() {
    echo "$2" > "$GPIO_PATH/gpio$1/value"
}

gpio_export $GPIO_P
gpio_export $GPIO_N

case "$1" in
    day)
        gpio_set $GPIO_N 0 && gpio_set $GPIO_P 1
        echo "IR CUT => Day mode (Filter IN)"
        ;;
    night)
        gpio_set $GPIO_P 0 && gpio_set $GPIO_N 1
        echo "IR CUT => Night mode (Filter OUT)"
        ;;
    idle)
        gpio_set $GPIO_P 0 && gpio_set $GPIO_N 0
        echo "IR CUT => Idle"
        ;;
    *)
        echo "Usage: $0 <day|night|idle>"
        exit 1
        ;;
esac

# Return to idle after 200ms pulse
sleep 0.2
gpio_set $GPIO_P 0
gpio_set $GPIO_N 0
echo "IR CUT => Returned to idle"
