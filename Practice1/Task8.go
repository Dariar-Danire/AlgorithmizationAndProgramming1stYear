package main

import "fmt"

func main() {
	var a, b, c int64
	fmt.Scan(&a, &b, &c)
	
	var temp_max int64
	if a > b{
	    temp_max = a
	}else{
	    temp_max = b
	}
	
	if temp_max > c{
	    fmt.Print(temp_max)
	}else{
	    fmt.Print(c)
	}
}
