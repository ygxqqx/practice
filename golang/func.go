package main

import "fmt"

type TwoInts struct {
	a int
	b int
}

func (tn *TwoInts) AddThem() int {
	return tn.a + tn.b
}

func (tn *TwoInts) AddToParam(param int) int {
	return tn.a + tn.b + param
}

func main() {
	func() {
		fmt.Println("========")
	}()
	nums := new(TwoInts)
	nums.a = 11
	nums.b = 45
	fmt.Println(nums.AddThem())
	fmt.Println(nums.AddToParam(1))
	fmt.Println("hello world!")
}
