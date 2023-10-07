package main
import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func isPalindrome(line string) bool {
    line = strings.ToLower(line)
    is_palindrome := true
    
    i := 0
    for i < len(line) {
        if line[i] == '~' || line[i] == '@' || line[i] == '!' || line[i] == '#' || line[i] == '%' || line[i] == '^' || line[i] == '&' || line[i] == '*' || line[i] == '(' || line[i] == ')' || line[i] == ' ' {
         line = line[:i] + line[(i + 1):]
        } else {
          i++  
        }
    }
    
    for i := 0; i < len(line)/2; i++ {
        if line[i] != line[len(line) - (i + 1)] {
            is_palindrome = false
        }
    }
    
    return is_palindrome
}

func main() {
    line, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isPalindrome( line[:len(line)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
