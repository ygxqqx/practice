package main

import (
	"fmt"
	"./person"
)

func main() {
	p := new(person.Person)
	p.SetFirstName("Eric")
	fmt.Println(p.FirstName())
}
