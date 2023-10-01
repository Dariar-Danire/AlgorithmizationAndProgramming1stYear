package main
import "fmt"

func main() {

    var len int
    fmt.Scan(&len)

    sourceNumbs := make([]float32, len)
    resNumbs := make([]float32, len)

    for i := 0; i < len; i++ {
        var num float32
        fmt.Scan(&num)
        sourceNumbs[i] = num
    }

    resNumbs[0] = sourceNumbs[0]
    fmt.Print(resNumbs[0], " ")

    for i := 1; i < (len - 1); i++ {
        resNumbs[i] = (sourceNumbs[i - 1] + sourceNumbs[i] + sourceNumbs[i + 1])/3
        fmt.Print(resNumbs[i], " ")
    }

    resNumbs[len - 1] = sourceNumbs[len - 1]
    fmt.Print(resNumbs[len - 1])
}
