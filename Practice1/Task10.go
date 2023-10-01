package main

import "fmt"

func main() {
	var a, b, c string
	fmt.Scan(&a, &b, &c)
	
	if a == "Да"{
	    if b == "Да"{
	        if c == "Да"{
	            fmt.Print("Утка")
	        }else{
	            fmt.Print("Пингвин")
	        }
	    }else{
	        if c == "Да"{
	            fmt.Print("Плезиозавры")
	        }else{
	           fmt.Print("Дельфин") 
	        }
	    }
	}else{
	    if b == "Да"{
	        if c == "Да"{
	            fmt.Print("Страус")
	        }else{
	            fmt.Print("Курица")
	        }
	    }else{
	        if c == "Да"{
	            fmt.Print("Жираф")
	        }else{
	            fmt.Print("Кот")
	        }
	    }
	}
}
