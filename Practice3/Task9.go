package main
import "fmt"
import "sort"

func PairWithSumEqualX(nums []int, X int) (int, int) {
    var res1, res2 int
    
    sort.Ints(nums)
    
    for i := 0; i < (len(nums) - 1); i++ {
        for k := 1; k < len(nums); k++ {
            if nums[i] + nums[k] == X {
                res1 = nums[i]
                res2 = nums[k]
                break
            }
            
            if nums[i] > X || nums[k] > X {
                break
            }
        }
    }
    
    return res1, res2
}

func main() {
    
    var n, X int
    fmt.Scan(&n, &X)
    
    nums := make([]int, n);
    for i := 0; i < n; i++ {
        fmt.Scan(&nums[i])
    }
    
    var res1, res2 int = PairWithSumEqualX(nums, X)
    
    if res1 <= res2 {
        fmt.Print(res1, res2)
    } else {
        fmt.Print(res2, res1)
    }
    
}
