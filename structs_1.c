#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Address {
	char *line1;
	char *line2;
	char *city;
	char *province;
	char *country;
} Address;

typedef struct Person {
	const char *firstName;
	const char *lastName;
	int age;
	const char sex;
	bool relStatus;
	Address address;
} Person;

void printAddress(Address address);

void printPerson( Person newPerson ){
	printf("First Name: %s\n", newPerson.firstName);
	printf("Last Name: %s\n", newPerson.lastName);
	printf("Age: %d\n", newPerson.age);
	printf("Sex: %c\n", newPerson.sex);
	printf("In A Relationship: ");
	if( newPerson.relStatus ){
		printf("Yes\n");
	} else {
		printf("No.\n");
	}
	printAddress( newPerson.address );
}
void printAddress(Address address){
	printf("Address Line 1: %s\n", address.line1);
	printf("Address Line 2: %s\n", address.line2);
	printf("Province: %s\n", address.province);
	printf("City: %s\n", address.city);
	printf("Country: %s\n", address.country);
}
void birthDay( Person *person ){
	person->age += 1;
}

void setAddress( Person *person, Address address){
	person->address = address;
}

void main() {
	Person person = { "Ian", "Salazar", 19, 'M', false};
	Address address = { "Unit G4, Whitehouse", "Ruby Street, Umali Subdivision, Brgy. Batong Malake", "Los Banos", "Laguna", "Philippines"};
	setAddress(&person, address);
	printPerson( person );
	birthDay( &person );
	printPerson( person );
}