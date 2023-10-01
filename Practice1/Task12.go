package main

import "fmt"

func main() {
	var cnt uint64 = 0
	var x uint64
	
	fmt.Scan(&x)
	
	for x > 1{
	    if x % 2 == 0{
	        x = x /2
	        cnt++
	    }else{
	        x = 3 * x + 1
	        cnt++
	    }
	}
	fmt.Print(cnt)
}
