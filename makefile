
tcpserv:tcpserv.c
	gcc tcpserv.c -o tcpserv -I../unpv13e/lib -L../unpv13e -lunp
tcpcli01:tcpcli01.c
	gcc tcpcli01.c -o tcpcli01 -I../unpv13e/lib -L../unpv13e -lunp
