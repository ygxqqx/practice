package person

type Person struct {
	firstName string
	lastName  string
}

func (person *Person) FirstName() string {
	return person.firstName
}

func (person *Person) SetFirstName(newName string) {
	person.firstName = newName
}
