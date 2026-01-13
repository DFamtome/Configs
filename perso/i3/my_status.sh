#!/bin/sh

echo '{ "version": 1 }'
echo '['
echo '[]'

while :
do
    DATETIME=$(date "+%a %b %d %H:%M")
    
    # Improved Volume Detection
    VOL=$(pactl get-sink-volume @DEFAULT_SINK@ | grep -Po '\d+(?=%)' | head -n 1)
    [ -z "$VOL" ] && VOL="0" # Fallback if empty

    # Improved Battery Detection (Checks for both BAT0 and BAT1)
    if [ -d /sys/class/power_supply/BAT0 ]; then
        BAT=$(cat /sys/class/power_supply/BAT0/capacity)
    else
        BAT=$(cat /sys/class/power_supply/BAT1/capacity)
    fi

    NET=$(nmcli -t -f active,ssid dev wifi | grep '^yes' | cut -d: -f2)
    [ -z "$NET" ] && NET="Disconnected"

    echo ",[{\"full_text\":\" 🌐 $NET \"},{\"full_text\":\" 🔊 $VOL% \"},{\"full_text\":\" 🔋 $BAT% \"},{\"full_text\":\" 📅 $DATETIME \"}]"
    
    sleep 1
done
