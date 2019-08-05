#!/bin/sh

go test -gcflags "-m -m" -run none -bench . -benchmem -memprofile mem.out $1
