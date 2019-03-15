#include <iomanip>
#include <string>
#include <iostream>
using namespace std;





struct Person {
    string firstname;
    string lastname;
    string phone;
    string address;
    struct Person* next;
};





struct Person * addPerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address );
    /* Precondition:
     *  head: Is the head node of a linked list.
     *      Contains NULL if empty.
     *  _firstname: is the first name of the new person to be added
     *  _lastname: is the last name of the new person to be added
     *  _phone: is the phone number of the new person to be added
     *  _address: is the address of the new person to be added
     *  All provided arguments are assumed to be non-null.
     *
     * Postcondition:
     *  A new Person node is appended to the end of head linked list.
     *  The new person node is pointing to NULL as next.
     *
     * Return:
     *  Returns the head node of the linked list.
     */





void updatePerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address );
    /**
     * Precondition:
     * Postcondition:
     */





void deletePerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address );
    /**
     * Precondition:
     * Postcondition:
     */





void searchPerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address );
    /**
     * Precondition:
     * Postcondition:
     */





string toString(struct Person *person);
    /**
     * Preconditon: person is null, or properly initialized.
     * Return: an empty string if person is NULL,
     *  otherwise return a string representation of a Person object.
     */





void printAddressBook(struct Person *head);
    /**
     * Precondition: head is NULL, or a linkedlist of Person objects.
     * Postcondition: print a textual representation of the address book to stdout.
     */





struct Person* destroyPersonLinkedList(struct Person *head);
    /**
     * Precondition: head is a pointer to a linkedlist of Person objects
     * Postcondition: all Person nodes of the linkedlist AddressBook will be deallocated from the heap.
     * Returns: the head node, which should be a NULL.
     */





struct Person * addPerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address ) {
    if (head == NULL) {
        struct Person *person = new Person;
        person->firstname = _firstname;
        person->lastname = _lastname;
        person->phone = _phone;
        person->address = _address;
        person->next = NULL;
        return person;
    } else {
        struct Person *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new Person;
        curr = curr->next;
        curr->firstname = _firstname;
        curr->lastname = _lastname;
        curr->phone = _phone;
        curr->address = _address;
        curr->next = NULL;
        return head;
    }
}





string toString(struct Person *person) {
    return ( (person == NULL) ? "" :
            person->lastname + ", "
            + person->firstname + ". "
            + person->phone + ". "
            + person->address + "."
        );
}





void printAddressBook(struct Person *head) {
    cout << "==============================================\n"
        << "\t\tAddress Book\n"
        << "==============================================\n";
    if (head == NULL) 
        cout << "(Empty)\n";
    else {
        struct Person *current = head;
        int index = 0;
        while (current != NULL) {
            cout << setw(4) << ++index << ": "
                << toString(current) << endl;
            current = current->next;
        }
    }
}





void updatePerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address ) {
    ;
}





void deletePerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address ) {
    ;
}





void searchPerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address ) {
    ;
}





struct Person* destroyPersonLinkedList(struct Person *head) {
    if (head != NULL) {
        struct Person *current = head;
        while (head != NULL) {
            head = head->next;
            delete current;
            current = head;
        }
    }
    return head;
}





int main() {
    struct Person *AddressBook = NULL;

    //Add a couple entries to the AddressBook
    AddressBook = addPerson(AddressBook, "Bob", "Doe", "(415) 123-4567", "123 Fake St");
    addPerson(AddressBook, "Bob", "Doe", "(415) 123-4567", "123 Fake St");

    printAddressBook(AddressBook);

    //Deallocate memory claimed by AddressBook.
    AddressBook = destroyPersonLinkedList(AddressBook);

    //Test if AddressBook has been deallocated.
    printAddressBook(AddressBook);

    return 0;
}





