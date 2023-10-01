package main

import "fmt"
import "math"

func main() {
	var man_in_day = 0.5       //литр
	var oak50_in_age = 20.0    //литр
	var poplar25_in_age = 32.0 //литр

	var man_in_age = man_in_day * 365
	var poplar_for_man = math.Ceil(man_in_age / poplar25_in_age)
	var oak_for_man = math.Ceil(man_in_age / oak50_in_age)

	fmt.Println(man_in_age, poplar_for_man, oak_for_man)
}
