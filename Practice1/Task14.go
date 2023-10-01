package main
import "fmt"

func main() {
    var row, col = 1, 1
    fmt.Scan(&row, &col)
    
    fmt.Print("    |")
    for i := 1; i <= col; i++{
        if i > 0 && i < 10{
            fmt.Print("   ", i)
        }
        if i >= 10 && i < 32{
            fmt.Print("  ", i)
        }
    }
    
    fmt.Print("\n   ")
    
    for i := 0; i < (col + col*3 + 2); i++{
        fmt.Print("-")
    }
    
    fmt.Print("\n")
    
    for i := 1; i <= row; i++{
        
        if i > 0 && i < 10{
            fmt.Print("   ", i, "|")
        }
        if i >= 10 && i < 32{
            fmt.Print("  ", i, "|")
        }
        
        for k := 1; k <= col; k++{
            
            if i*k < 10 && i*k >= 0{
                fmt.Print("   ", i*k)
            }
            if i*k >= 10 && i*k < 100{
                fmt.Print("  ", i*k)
            }
            if i*k >= 100 && i*k < 1000{
                fmt.Print(" ", i*k)
            }
        }
        fmt.Print("\n")
    }
}
