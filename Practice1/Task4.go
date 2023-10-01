package main

import "fmt"

func main() {
	var a int32
	var b int32
	
	fmt.Scan(&a, &b)
	
	var res int32 = a * b
	fmt.Print(res)
}
