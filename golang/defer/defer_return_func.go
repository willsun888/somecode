package main

import (
    "fmt"
    "time"
)
func main() {
    example()
}

func example() {
    var ret int32 = 0
    defer mcall(&ret)()
    fmt.Println("do logic")
    ret = 1
}

func mcall(ret *int32) func() {
    start := time.Now()
    fmt.Println("mcall start")
    return func() {
        fmt.Printf("mcall end, ret:%d, after:%s\n", *ret, time.Since(start))
    }
}

