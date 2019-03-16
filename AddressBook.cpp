#include <cassert> //assert
#include <cstdlib> //srand, rand
#include <ctime> //time
#include <iomanip> //setw
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





struct Person * addPerson(struct Person *head, struct Person *source);
    /**
     * Precondition: head is a Person LinkedList,
     *  and source is a Person node to be added to the end of head.
     * Postcondition: source is added to the end of head.
     * Returns: a pointer to the head Person node of the provided linkedlist
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





struct Person* searchPerson(struct Person *head, string query);
    /**
     * Precondition: head is a pointer to a Person LinkedList,
     *  and query is a string containing search terms to identify a Person object.
     * Return: a Person linkedlist of Person objects that contain matches with the query string,
     *  if there are no matches, a Person pointer pointing to null is returned.
     */





int compare(struct Person *src, struct Person *other);
    /**
     * Precondition: src and other are well-define Person objects
     * Postcondition: src and other are compared by lastname, firstname, phone, then address.
     * Return: a negative integer if src is smaller than other,
     *  a positive integer if greater,
     *  or a 0 if they are equal.
     */





struct Person * sort(struct Person *head);
    /**
     * Precondition:
     * Postcondition:
     * Return: 
     */





string toString(struct Person *person);
    /**
     * Preconditon: person is null, or properly initialized.
     * Return: an empty string if person is NULL,
     *  otherwise return a string representation of a Person object.
     */





void printAddressBook(struct Person *head, const string title);
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





string getRandFirstName();
    /**
     * Helper function to randomly generate a first name.
     * Return: a randomly chosen first name from a list of 50.
     */





string getRandLastName();
    /**
     * Helper function to randomly generate a last name.
     * Return: a randomly chosen last name from a list of 50.
     */





string getRandPhone();
    /**
     * Helper function to randomly generate a phone number.
     * Return: a random string containing a phone number with the format "(###) ###-####".
     */





string getRandAddress();
    /**
     * Helper function to randomly generate a street address.
     * Return: a randomly chosen street address from a list of 50.
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





struct Person * addPerson(struct Person *head, struct Person *source) {
    return addPerson(head, source->firstname, source->lastname, source->phone, source->address);
}





string toString(struct Person *person) {
    return ( (person == NULL) ? "" :
            person->lastname + ", "
            + person->firstname + ". "
            + person->phone + ". "
            + person->address + "."
        );
}





void printAddressBook(struct Person *head, const string title) {
    cout << "==============================================\n"
        << "\t\t" << title << "\n"
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





struct Person* searchPerson(struct Person *head, string query) {
    struct Person *results = NULL;
    if (head != NULL && query.length() != 0) {
        struct Person *current = head;
        while (current != NULL) {
            string person_str = toString(current);
            if (person_str.find(query) != string::npos)
                results = addPerson(results, current);
            current = current->next;
        }
        return results;
    }
    return results;
}





int compare(struct Person *src, struct Person *other) {
    //Primary Sort: By Last Name
    if (src->lastname < other->lastname)
        return -1;
    else if (src->lastname > other->lastname)
        return 1;
    else {
        //assert (src->lastname == other->lastname);
        //Secondary Sort: By First Name
        if (src->firstname < other->firstname)
            return -1;
        else if (src->firstname > other->firstname)
            return 1;
        else {
            //assert (src->firstname == other->firstname);
            //Tertiary Sort: By Phone Number
            if (src->phone < other->phone)
                return -1;
            else if (src->phone > other->phone)
                return 1;
            else {
                //assert (src->phone == other->phone);
                //Quarternary Sort: By Address
                if (src->address < other->address)
                    return -1;
                else if (src->address > other->address)
                    return 1;
                else {
                    //assert (src->address == other->address);
                    return 0;
                }
            } 
        }
    }
}





struct Person * sort(struct Person *head) {
    if (head == NULL || head->next == NULL)
        return head; //Ignore empty list, or singletons.
    else {
        //There are at least 2 nodes.
        struct Person *current = head,
                      *next,
                      *prev;
        int len = 0;
        while (current != NULL) {
            len++;
            current = current->next;
        }
        //Bubble Sort
        for (int i = 0; i < len; i++) {
            prev = head;
            current = head->next;
            next = head->next->next;
            //If the first two nodes need to swap, head needs to be updated.
            if (compare(prev, current) > 0) {
                head = current;
                current->next = prev;
                prev->next = next;
                //Re-align the pointers
                prev = head;
                current = head->next;
                next = head->next->next;
            }
            while (next != NULL) {
                if (compare(current, next) > 0) {
                    struct Person *tmp = next->next;
                    prev->next = next;
                    next->next = current;
                    current->next = tmp;
                    //Re-aligni pointers
                    current = prev->next;
                    next = prev->next->next;
                }
                prev = prev->next;
                current = current->next;
                next = next->next;
            }
        }
    }
    return head;
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





string getRandFirstName() {
    int randomIndex = rand()%50;
    string firstNames[50] = {
        "Lakenya",
        "Anita",
        "Sherita",
        "Ezra",
        "Margeret",
        "Rosena",
        "Meridith",
        "Taren",
        "Velma",
        "Audra",
        "Shara",
        "Madison",
        "Bonny",
        "Helen",
        "Farah",
        "Danita",
        "Noel",
        "Marisha",
        "Tatum",
        "Catrice",
        "Laree",
        "Sanjuana",
        "Fidel",
        "Sang",
        "Teressa",
        "Maris",
        "Breanne",
        "Lady",
        "Elia",
        "Kelle",
        "Brandie",
        "Christy",
        "Kathlyn",
        "Fiona",
        "Eula",
        "Magnolia",
        "Jerrie",
        "Luci",
        "Pearline",
        "Giuseppina",
        "Michal",
        "Chase",
        "Jamie",
        "Rozella",
        "Arlinda",
        "Karena",
        "Jeanetta",
        "Aurelio",
        "Tonda",
        "Crista"
    };
    return firstNames[randomIndex];
}





string getRandLastName() {
    int randomIndex = rand()%50;
    string lastNames[50] = {
        "English",
        "Hall",
        "Levine",
        "Bright",
        "Mcdaniel",
        "Nash",
        "Day",
        "Bullock",
        "Robles",
        "Norman",
        "Tate",
        "Byrd",
        "Chavez",
        "Graham",
        "Donovan",
        "Holmes",
        "Fisher",
        "Briggs",
        "Ware",
        "Clark",
        "Williams",
        "Fleming",
        "Charles",
        "Myers",
        "Baldwin",
        "Doyle",
        "Mcclain",
        "Orr",
        "Floyd",
        "Whitehead",
        "Melendez",
        "Callahan",
        "Mathis",
        "Randall",
        "Collier",
        "Valentine",
        "Friedman",
        "Jacobs",
        "Castaneda",
        "Howe",
        "Gallegos",
        "Reid",
        "Riley",
        "Washington",
        "Hendrix",
        "Mcmahon",
        "Pollard",
        "Gregory",
        "Goodwin",
        "Everett"
    };
    return lastNames[randomIndex];
}





string getRandPhone() {
    return "(" + to_string(rand()%900+100) + ") " + to_string(rand()%900+100) + "-" + to_string(rand()%10000+1000);
}





string getRandAddress() {
    int randomIndex = rand()%50;
    string address[50] = {
        "8684 Olive St. Floral Park, NY 11001",
        "28 Creek Ave. Milton, MA 02186",
        "773 Westminster St. Corona, NY 11368",
        "167 S. Andover Ave. Youngstown, OH 44512",
        "7658 North Hillcrest Lane everly, MA 01915",
        "96 Glenwood Ave. Norwalk, CT 06851",
        "9508 Kingston Drive evern, MD 21144",
        "552 Sunbeam Rd. Parkville, MD 21234",
        "5 Livingston Street est New York, NJ 07093",
        "6 High Ridge St. Greer, SC 29650",
        "868 W. Surrey Ave. Horn Lake, MS 38637",
        "999 Ann Drive arpentersville, IL 60110",
        "7218 Arrowhead Street ummelstown, PA 17036",
        "7300 South Lakeview Street outhfield, MI 48076",
        "85 Creek Rd. Bridgewater, NJ 08807",
        "40 Hickory Court verett, MA 02149",
        "97 John Street hevy Chase, MD 20815",
        "9013 Kingston Ave. Wilkes Barre, PA 18702",
        "7744 Catherine Ave. Fort Lauderdale, FL 33308",
        "9280 Evergreen St. Villa Rica, GA 30180",
        "884 Canterbury Street airfax, VA 22030",
        "9714 Edgewater Rd. Silver Spring, MD 20901",
        "9598 Ashley Rd. Newark, NJ 07103",
        "234 Trout Drive ake Charles, LA 70605",
        "523 Manor Station Drive indsor, CT 06095",
        "9016 Vine St. Richmond, VA 23223",
        "8889 Rockledge St. Glen Ellyn, IL 60137",
        "46 East Glenlake Ave. Collierville, TN 38017",
        "5 S. Sherwood Rd. Toms River, NJ 08753",
        "263 2nd Dr. Anaheim, CA 92806",
        "8049 South Prairie St. Santa Clara, CA 95050",
        "1 Atlantic St. Superior, WI 54880",
        "9 Mayfield St. North Haven, CT 06473",
        "875 Smith Street enatchee, WA 98801",
        "686 Wood St. Hobart, IN 46342",
        "836 South Jefferson St. New Lenox, IL 60451",
        "472 Brown St. Cherry Hill, NJ 08003",
        "64 Inverness St. Oklahoma City, OK 73112",
        "5 Canal Ave. Kalamazoo, MI 49009",
        "758 Cherry Dr. Norcross, GA 30092",
        "7473 Hilltop Lane rankfort, KY 40601",
        "454 Livingston St. Appleton, WI 54911",
        "328C Glen Ridge Dr. Ypsilanti, MI 48197",
        "64 E. High Noon Dr. Woodhaven, NY 11421",
        "768 Courtland St. Oakland, CA 94603",
        "8427 W. Lakeshore St. Apex, NC 27502",
        "8473 Union Ave. Clermont, FL 34711",
        "424 Mayfield Street umberland, RI 02864",
        "65 W. Stonybrook Ave. Tualatin, OR 97062",
        "895 Cedar Drive ort Orange, FL 32127"
    };
    return address[randomIndex];
}





int main() {
    srand (time(NULL));

    const string ADDRESS_BOOK = "Address Book";
    const string SEARCH_RESULTS = "Search Results";
    struct Person *AddressBook = NULL;
    struct Person *searchResults = NULL;

    //Add some entries to the AddressBook
    for (int i = 0; i < 10; i++)
        AddressBook = addPerson(AddressBook, getRandFirstName(), getRandLastName(), getRandPhone(), getRandAddress());
    printAddressBook(AddressBook, ADDRESS_BOOK);

    cout << "Search (Case-Sensitive): ";
    string searchTerms;
    getline(cin, searchTerms);
    cout << "Searching for: " << searchTerms << endl;
    searchResults = searchPerson(AddressBook, searchTerms);
    printAddressBook(searchResults, SEARCH_RESULTS);
    if (searchResults == NULL && searchTerms.find(" ") != string::npos)
        cout << "No results were found. Try narrowing the search. e.g. Just one word.\n";
    searchResults = destroyPersonLinkedList(searchResults);

    AddressBook = sort(AddressBook);
    printAddressBook(AddressBook, ADDRESS_BOOK);

    //Memory cleanup.
    AddressBook = destroyPersonLinkedList(AddressBook);

    return 0;
}





