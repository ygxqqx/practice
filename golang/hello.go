package main

import "fmt"
import "example"

func main() {
	isRight := false
	if isRight {
		fmt.Println("hello world!")
		fmt.Println(`This is a raw string \n`)
	}
	example.Hi()
}
