sudo nmcli nm wifi off
sudo rfkill unblock all

sudo ifconfig wlan0 192.168.150.1/24 up
sleep 1
sudo service dnsmasq restart
sudo service hostapd restart
