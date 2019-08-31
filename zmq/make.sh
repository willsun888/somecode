#!/bin/sh
gcc hwclient.c -o hwclient -I/usr/local/Cellar/zeromq/4.2.2/include -L/usr/local/Cellar/zeromq/4.2.2/lib -lzmq
gcc hwserver.c -o hwserver -I/usr/local/Cellar/zeromq/4.2.2/include -L/usr/local/Cellar/zeromq/4.2.2/lib -lzmq
