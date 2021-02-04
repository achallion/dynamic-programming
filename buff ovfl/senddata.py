#!/usr/bin/python3

import sys
import socket

if len(sys.argv) == 1 or sys.argv[1] == "-h" or sys.argv[1] == "-H" or sys.argv[1] == '--help':
    print("Usage : python3 senddata.py ip port string")
else:
    ip = str(sys.argv[1])
    port = int(sys.argv[2])
    data = str(sys.argv[3])

    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    connect = s.connect((ip,port))
    s.send(data)
    s.close()