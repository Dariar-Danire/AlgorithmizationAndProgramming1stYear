package main
import "fmt"

func shift(data []int, steps int) []int {
    res := []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

    for steps > 10 {
        steps -= 10
    }
    
    for steps < -10 {
        steps += 10
    }
    
    if steps > 0 {
        for index := 0; index < 10; index++ {
            if (9 - index) >= steps {
                res[index + steps] = data[index]
            } else {
                res[(index + steps) - 10] = data[index]
            }
        }
    } else if steps < 0 {
        for index := 9; index >= 0; index-- {
            if (index + steps) >= 0 {
                res[index + steps] = data[index]
            } else {
                res[index + 10 + steps] = data[index]
            }
        }
    }
    
    for i := 0; i < 10; i++ {
        data[i] = res[i]
    }
    
    return res
}

func main(){
    var steps int
    fmt.Scan(&steps)

    var data [10]int
    for index := range data{
        fmt.Scan(&data[index])
    }

    shift(data[:], steps);
    for _, value := range data{
        fmt.Printf("%d ", value)
    }
}
