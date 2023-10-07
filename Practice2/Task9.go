package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func isLucky(number string) bool {
    is_lucky := true
    
    var num,_ = strconv.Atoi(number)
    
    var a int = num % 10
    var b int = (num / 10) % 10
    var c int = (num / 100) % 10
    var d int = (num / 1000) % 10
    var e int = (num / 10000) % 10
    var f int = (num / 100000) % 10
    
    if (a + b + c) != (d + e + f) {
        is_lucky = false
    }
    
    return is_lucky
}

func main() {
    number, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isLucky( number[:len(number)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
