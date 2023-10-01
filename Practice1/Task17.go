package main
import "fmt"

func main() {
    var n int;
    fmt.Scan(&n)
    
    sourceNumbs := make([]int, n)
    for i := 0; i < n; i++ {
        var z int
        fmt.Scan(&z)
        sourceNumbs[i] = z
    }
    
    var cntOfWater int = 0
    
    // 9
    // 3 1 4 3 6 2 2 1 2
    //   2   1       
    for i := 1; i < (n - 1); i++ {
        
        if sourceNumbs[i] < sourceNumbs[i - 1]  {
            var cnt_of_cons int = 1
        
            var start = i - 1 // 3
        
            for sourceNumbs[i] == sourceNumbs[i + 1] {
                cnt_of_cons += 1
                i += 1
            }
            
            if sourceNumbs[i] < sourceNumbs[i + 1] {
                if sourceNumbs[i + 1] <= sourceNumbs[start] {
                    cntOfWater += cnt_of_cons * (sourceNumbs[i + 1] - sourceNumbs[i])
                } else {
                    cntOfWater += cnt_of_cons * (sourceNumbs[start] - sourceNumbs[i])
                }
            }
        }
    }
    
    fmt.Print(cntOfWater)
}
