#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
	string name;
	unsigned age;
	char gender;
public:
	Person():
		name(),
		age(0),
		gender(0)
	{}

	Person(string name, unsigned age, char gender):
		name(name),
		age(age),
		gender(gender)
	{}

	virtual void introduce() {
		cout << "My name is " << name << ".\n";
		cout << "I'm " << age << " years old.\n";
		cout << (gender == 'F' ? "I'm a woman.\n" : "I'm a man.\n");

		/*if (gender == 'F')
			cout << "I'm a woman.\n";
		else
			cout << "I'm a man.\n";*/
	}
};

class Student : public Person {
protected:
	unsigned indexNumber;
	string fieldOfStudy;
	string university;
public:
	Student() {

	}

	Student(string name, unsigned age, char gender, unsigned indexNumber, string fieldOfStudy, string university):
		Person(name, age, gender),
		indexNumber(indexNumber),
		fieldOfStudy(fieldOfStudy),
		university(university)
	{}

	virtual void introduce() {
		cout << "My name is " << name << ".\n";
		cout << "I'm " << age << " years old.\n";
		cout << (gender == 'F' ? "I'm a woman.\n" : "I'm a man.\n");
		cout << "Index number: " << indexNumber << "\n";
		cout << "Field of study: " << fieldOfStudy << "\n";
		cout << "University: " << university << "\n";		
	}
};

int main() {
	/*Person p; //("Ania", 24, 'F');
	p.introduce();
	cout << endl;
	Student s("Jan", 54, 'M', 234654, "Computer Science", "AGH");
	s.introduce();*/

	/*Person* p = new Student("Grzegorz", 76, 'M', 7665, "blabla", "blabla");
	p->introduce();*/

	vector<Person*> people;
	people.push_back(new Person("Maria", 66, 'F'));
	people.push_back(new Student("Mariusz", 53, 'M', 6666, "aaa", "bbb"));
	people.push_back(new Person("Klaudia", 12, 'F'));

	//people[0]->age = 9; protected, nie ma dostêpu

	for (Person* p : people) {
		p->introduce();
		cout << endl;
	}
}