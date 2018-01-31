#!/bin/sh
case "$1" in
start)
python /opt/domoticz/scripts/python/onAction.py
python /opt/domoticz/scripts/python/offAction.py
;;
stop)
echo "turn off"
;;
reload|restart)
$0 stop
$0 start
;;
*)
echo "Usage: $0 start|stop|restart|reload"
exit 1
esac
exit 0
