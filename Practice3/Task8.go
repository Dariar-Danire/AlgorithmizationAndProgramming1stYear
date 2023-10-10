package main
import "fmt"

func count(nums []int, findNum int) int {
    var cnt int = 0
    
    for i := 0; i < len(nums); i++ {
        if nums[i] == findNum {
            cnt++
        }
    }
    
    return cnt
}

func UniqueNumber(nums []int) int {
    var res int;
    
    for i := 0; i < len(nums); i++ {
        if count(nums, nums[i]) % 2 != 0 {
            res = nums[i]
        }
    }
    
    return res
}

func main() {
    
    var n int
    fmt.Scan(&n)
    
    nums := make([]int, n);
    for i := 0; i < n; i++ {
        fmt.Scan(&nums[i])
    }
    
    fmt.Print(UniqueNumber(nums))
    
}
