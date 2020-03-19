// Package connpool 连接池
package connpool

import (
	"net"
	"time"
)

// Pool client connection pool
type Pool interface {
	Get(network string, address string, timeout time.Duration) (net.Conn, error)
}
