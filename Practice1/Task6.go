package main

import "fmt"

func main() {
	var N uint64
	fmt.Scan(&N)
	
	var num5000 uint64 = N/5000
	var num1000 uint64 = (N - num5000*5000)/1000
	var num500 uint64 = (N - num5000*5000 - num1000*1000)/500
	var num200 uint64 = (N - num5000*5000 - num1000*1000 - num500*500)/200
	var num100 uint64 = (N - num5000*5000 - num1000*1000 - num500*500 - num200*200)/100
	
	fmt.Print(num5000, num1000, num500, num200, num100)
}
