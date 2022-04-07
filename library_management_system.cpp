#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>   //Importing library for file handling
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>


/* ********************* ASCII Arts ********************* */

const char *LIBRARY = "\n\
     ____________________________________________________\n\
    |____________________________________________________|\n\
    | __     __   ____   ___ ||  ____    ____     _  __  |\n\
    ||  |__ |--|_| || |_|   |||_|**|*|__|+|+||___| ||  | |\n\
    ||==|^^||--| |=||=| |=*=||| |~~|~|  |=|=|| | |~||==| |\n\
    ||  |##||  | | || | |JRO|||-|  | |==|+|+||-|-|~||__| |\n\
    ||__|__||__|_|_||_|_|___|||_|__|_|__|_|_||_|_|_||__|_|\n\
    ||_______________________||__________________________|\n\
    | _____________________  ||      __   __  _  __    _ |\n\
    ||=|=|=|=|=|=|=|=|=|=|=| __..\\/ |  |_|  ||#||==|  / /|\n\
    || | | | | | | | | | | |/\\ \\  \\|++|=|  || ||==| / / |\n\
    ||_|_|_|_|_|_|_|_|_|_|_/_/\\_.___\\__|_|__||_||__|/_/__|\n\
    |____________________ /\\~()/()~//\\ __________________|\n\
    | __   __    _  _     \\_  (_ .  _/ _    ___     _____|\n\
    ||~~|_|..|__| || |_ _   \\ //\\\\ /  |=|__|~|~|___| | | |\n\
    ||--|+|^^|==|1||2| | |__/\\ __ /\\__| |==|x|x|+|+|=|=|=|\n\
    ||__|_|__|__|_||_|_| /  \\ \\  / /  \\_|__|_|_|_|_|_|_|_|\n\
    |_________________ _/    \\/\\/\\/    \\_ _______________|\n\
    | _____   _   __  |/      \\../      \\|  __   __   ___|\n\
    ||_____|_| |_|##|_||   |   \\/ __|   ||_|==|_|++|_|-|||\n\
    ||______||=|#|--| |\\   \\   o    /   /| |  |~|  | | |||\n\
    ||______||_|_|__|_|_\\   \\  o   /   /_|_|__|_|__|_|_|||\n\
    |_________ __________\\___\\____/___/___________ ______|\n\
    |__    _  /    ________     ______           /| _ _ _|\n\
    |\\ \\  |=|/   //    /| //   /  /  / |        / ||%|%|%|\n\
    | \\/\\ |*/  .//____//.//   /__/__/ (_)      /  ||=|=|=|\n\
  __|  \\/\\|/   /(____|/ //                    /  /||~|~|~|__\n\
    |___\\_/   /________//   ________         /  / ||_|_|_|\n\
    |___ /   (|________/   |\\_______\\       /  /| |______|\n\
        /                  \\|________)     /  / | |\n\
";

const char *WELCOME = "\n\
 __      __       .__                                \n\
/  \\    /  \\ ____ |  |   ____  ____   _____   ____   \n\
\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\  \n\
 \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/  \n\
  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  > \n\
       \\/       \\/          \\/            \\/     \\/  \n\
";

const char *BOOK = "\n\
            /;\n\
           / |'-,.\n\
          /  '    `\"---,.__\n\
         /  '    ,'     ,  '\"--,\"|\n\
        /  '    ,     ,'     ,\"::|\n\
       /  '   ,'    ,      ,\"::::|\n\
      /  '   ,    ,'     ,\"::::::L\n\
     /  '  ,'   ,'     ,\"::::::::L\n\
    /  '  ,    ,     ,\":::::::::J\n\
    k-,._    ,'   _.\":::::::::::J\n\
     \\.  `\"----'\"\".J::::::::::::|\n\
      \\.    .-,    .L:::::::::::|\n\
       \\.  (       .J:::::::::::!\n\
        \\.  `--     .L:::::::::/\n\
         \\.   .-.   .|::::::::/\n\
          \\. (   )  .J:::::::/\n\
           \\. `-'    .L:::::/\n\
            \\.  L    .|::::/\n\
             \\. !__  .J:::/\n\
              \\.  __  .L:/\n\
               \\. L_) .|/\n\
                `-,__,-'\n\
";

const char *SEARCH = "\n\
         _.-----._\n\
       .'.-'''''-.'._\n\
      //`.: :'    `\\\\\\\n\
     ;; '           ;;'.__.===============,\n\
     ||             ||  __                 )\n\
     ;;             ;;.'  '==============='\n\
      \\\\           ///\n\
       ':.._____..:'~\n\
         `'-----'`\n\
";

const char *NOTFOUND = "\n\
███╗░░██╗░█████╗░████████╗██╗░░██╗██╗███╗░░██╗░██████╗░  ███████╗░█████╗░██╗░░░██╗███╗░░██╗██████╗░\n\
████╗░██║██╔══██╗╚══██╔══╝██║░░██║██║████╗░██║██╔════╝░  ██╔════╝██╔══██╗██║░░░██║████╗░██║██╔══██╗\n\
██╔██╗██║██║░░██║░░░██║░░░███████║██║██╔██╗██║██║░░██╗░  █████╗░░██║░░██║██║░░░██║██╔██╗██║██║░░██║\n\
██║╚████║██║░░██║░░░██║░░░██╔══██║██║██║╚████║██║░░╚██╗  ██╔══╝░░██║░░██║██║░░░██║██║╚████║██║░░██║\n\
██║░╚███║╚█████╔╝░░░██║░░░██║░░██║██║██║░╚███║╚██████╔╝  ██║░░░░░╚█████╔╝╚██████╔╝██║░╚███║██████╔╝\n\
╚═╝░░╚══╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝╚═╝░░╚══╝░╚═════╝░  ╚═╝░░░░░░╚════╝░░╚═════╝░╚═╝░░╚══╝╚═════╝░\n\
";

/* *********** HELPER FUNCTIONS *********** */

void toCopy()
{
    std::string line;
    //For writing text file
    //Creating ofstream & ifstream class object
    std::ifstream ini_file ("temp.txt");
    std::ofstream out_file ("books_data.txt");
 
    if(ini_file && out_file)
    {
 
        while(getline(ini_file,line))
        {
            out_file << line << "\n";
        }
    } 
    else 
    {
        //Something went wrong
        printf("Cannot Read File");
    }
    //Closing file
    ini_file.close();
    out_file.close();
}

void updatedatabase(std::string a){
    std::string item_name;
    std::ifstream nameFileout;

    nameFileout.open("books_data.txt");
    std::string to_write="";
    while (std::getline(nameFileout, item_name))
    {

        // Write to the file
        std::string title = a;
         
        std::string s = item_name.substr(item_name.find(':')+2);
        if(s == title)
        {
            int r=3;
            while(r>0)
            {
                std::getline(nameFileout, item_name);
                r--;
            }
            continue;
        }
        to_write += item_name;
        to_write += "\n";
    }
    std::ofstream MyFile("temp.txt");
    MyFile <<to_write<<"\n";
    MyFile.close();
    nameFileout.close();
    toCopy();
}

// User Class and its child classes - Librarian, Professor, and Student
class User {
    protected:
        char name[100];  // Store student's name
        char id[100];  // Store user's ID
        char password[500]; // Store user's password
    public:
        /* *************** LOGIN AND REGISTRATION *************** */

        // Function to check validity od username and password for logging in
        std::string usn;   // Store username
        int tm;

        void valid(std::string str, std::string role) //function declaration for keeping records   
        {
            std::string dir, user;
            std::ifstream file;
            dir = str + role +".txt";   // Directory (file name) to store user credentials
            file.open(dir.c_str());
            if(!file.is_open() && file.fail())
            {
                //file.close();
                return;
            }
            else
            {
                tm++;
                if(tm==3)
                {
                    std::cout<<"\nThis Username Already Exists\nPlease Try Again.";
                    //file.close();
                    return;
                }
                std::cout<<"\nThis Username Already Exists!\nCreate A Username:";
                std::cin>>usn;
                //file.close();
                valid(usn, role);
            }
        };


        // Function for implementing login and registration
        int login_register(std::string role)   // Takes the role of the user as input
        {
            // Choice for login or register
            int choice, i, exit=0;
            std::string ans, psd, name, fname, bio, usern, pw, line, nusn, rol;
            std::ofstream fileo;
            std::ifstream filei;
            std::cout << "-----------------------Welcome to our Library Management System!-----------------------\n";
            while(exit==0)
            {
                std::cout << "\nChoose one option:\n1. SignIn (Press 1 to select this)\n2. Register (Press 2 to select this)\nPress Any key and Enter to exit\n";
                std::cin >> choice;
                if(choice==1)
                {
                    std::cout << "Enter your username: ";
                    std::cin >> usn;
                    std::cout << "\nEnter your password: ";
                    std::cin >> psd;
                    fname = usn + role + ".txt";  // Store credentials
                    filei.open(fname.c_str());
                    if(!filei.is_open() && filei.fail())
                    {
                        std::cout<<"\nYou are not registered, please register before logging in.";
                        filei.close();
                        continue;
                    }
                    getline(filei, usern);
                    getline(filei, line);
                    getline(filei, pw);
                    getline(filei, rol);
                    if (usn == usern && psd == pw && role == rol)
                    {
                        std::cout<<"\nYou are successfully logged in:)\n";

                        // Printing ASCII art
                        printf("%s\n", WELCOME);

                        std::cout << "\nYOUR PROFILE SAYS:\n";
                        std::cout << "Username: " << usern << std::endl;
                        std::cout<<"Name: "<<line<<std::endl;
                        std::cout<<"Role: "<<line<<std::endl;
                        getline(filei,line);
                        std::cout<<"Bio: "<<line<<std::endl;
                        filei.close();
                        break;
                    }
                    else{
                        std::cout<<"\nWrong Username or Password!\nPlease Try Again.\n";
                    }
                    // cout<<endl;
                }
                else if(choice==2)
                {
                    std::cout<<"\nEnter your name: ";
                    std::cin.ignore();
                    getline(std::cin,name);
                    std::cout<<"\nCreate a username: ";
                    std::cin>>usn;
                    tm=0;
                    valid(usn, role);
                    if(tm>=3)
                    {
                        continue;
                    }
                    std::cout<<"\nCreate a password: ";
                    std::cin>>psd;
                    fname=usn + role +".txt";
                    //cout<<fname;
                    fileo.open(fname.c_str());
                    fileo<<usn<<std::endl<<name<<std::endl<<psd<<std::endl<<role<<std::endl;
                    std::cout<<"\nYOU ARE SUCCESSFULLY REGISTERED AS A " << role << " :)\n";
                    
                    // Adding bio for users
                    std::cout<<"\nAdd your bio and press enter when you are done: ";
                    std::cin.ignore();
                    getline(std::cin,bio);
                    fileo<<bio<<std::endl;
                    std::cout<<"\nYour bio is saved as: "<<bio<<std::endl;
                    fileo.close();

                    std::cout << "\n----------YOU CAN NOW LOGIN WITH YOUR USERNAME AND PASSWORD----------\n";
                }
                else
                {
                    exit = 1;
                    break;
                }
            }
            return exit;
        };
};


// Book Class
class Book {
    public:
        char title[100]; // Stores the title of the book
        char author[100]; // Stores the author of the book
        char isbn[100]; // Stores the ISBN of the book
        char publication[100]; // Stores the publication of the book

        void request_book(){
            // This function is for the users to request books
        };

        void show_duedate(){
            // This function shows the due date to return the books for the professors and students
        };
};


// Book Database Class 
class Book_database {
    public:
        // std::vector<std::string> book_list{}; // Array of Strings to store the list of books in the library
        std::string title, author, isbn, publication, fname;
        std::ifstream filei;
        std::ofstream fileo;

        void search_books(){
            // This function is to search for books
            // Printing ASCII art
            printf("%s\n", SEARCH);
            fname = "books_data.txt";  // File storing all the book data
            std::string name;
            int number = 0; // To count the number of books searched
            std::cout << "\nEnter Book's Name : ";
            std::cin >> name;
            filei.open(fname.c_str());
            std::cout << "\n\n----------- SEARCH RESULTS ------------\n";
            while (!filei.eof())
            {
                getline(filei, title);
                getline(filei, author);
                getline(filei, isbn);
                getline(filei, publication);

                // Convert to lowercase
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                std::string title1 = title;
                title1.erase(title1.find("Title : "), 8);
                std::transform(title1.begin(), title1.end(), title1.begin(), ::tolower);
                if ((name == title1) || (title1.find(name) != std::string::npos))
                {
                    number++;
                    std::cout << "\n---------- " << number << " ----------\n";
                    std::cout << title << std::endl;
                    std::cout << author << std::endl;
                    std::cout << isbn << std::endl;
                    std::cout << publication << std::endl;
                }
            };
            if (number == 0){
                // Printing ASCII art
                printf("%s\n", NOTFOUND);
            }
        };

        void display_all_books(){
            // This function displays all the books
            // Printing ASCII art
            printf("%s\n", BOOK);
            fname = "books_data.txt";  // File storing all the book data

            int book_number = 0;
            filei.open(fname.c_str());
            while (!filei.eof()){
                book_number++;
                getline(filei, title);
                getline(filei, author);
                getline(filei, isbn);
                getline(filei, publication);
                std::cout << "\n---------- " << book_number << " ----------\n";
                std::cout << title << std::endl;
                std::cout << author << std::endl;
                std::cout << isbn << std::endl;
                std::cout << publication << std::endl;
            };
        };

        void add_books(){
            // This function is to add new books to the library
            fname = "books_data.txt";  // File storing all the book data

            std::cout << "\nEnter Title of Book : ";
            std::cin >> title;
            std::cout << "\nEnter Authors of Book : ";
            std::cin >> author;
            std::cout << "\nEnter ISBN of Book : ";
            std::cin >> isbn;
            std::cout << "\nEnter Publisher of Book : ";
            std::cin >> publication;
            fileo.open(fname, std::ios::app);
            fileo<<"\nTitle : "<<title<<std::endl<<"Authors : "<<author<<std::endl<<"ISBN : "<<isbn<<std::endl<<"Publisher : "<<publication;
            std::cout<<"\nSuccessfully Added a New Book :)\n";
        };

        std::string title12, author1, isbn1, publication1;
        void update_books(){
            // This function is to update the information about the books
            fname = "books_data.txt";  // File storing all the book data
            std::string name;
            int number = 0; // To count the number of books searched
            std::cout << "\nEnter Book's Name : ";
            std::cin >> name;
            filei.open(fname.c_str());
            std::cout << "\n\n----------- CHOOSE THE BOOK YOU WANT TO UPDATE ------------\n";
            std::ofstream fileout("temp.txt");  //Temporary file
            while (!filei.eof())
            {
                std::string choice;
                getline(filei, title);
                getline(filei, author);
                getline(filei, isbn);
                getline(filei, publication);

                // Convert to lowercase
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                std::string title1 = title;
                title1.erase(title1.find("Title : "), 8);
                std::transform(title1.begin(), title1.end(), title1.begin(), ::tolower);
                if ((name == title1) || (title1.find(name) != std::string::npos))
                {
                    number++;
                    std::cout << "\n---------- " << number << " ----------\n";
                    std::cout << title << std::endl;
                    std::cout << author << std::endl;
                    std::cout << isbn << std::endl;
                    std::cout << publication << std::endl;
                    std::cout << "\n\nDo you want to update this book? [Y/N] : ";
                    std::cin >> choice;
                    if ((choice == "Y") || (choice == "y")){
                        std::cout << "\nEnter New Title of Book (Leave blank if you don't want to update this) : ";
                        std::cin >> title12;
                        std::cout << "\nEnter New Authors of Book (Leave blank if you don't want to update this) : ";
                        std::cin >> author1;
                        std::cout << "\nEnter New ISBN of Book (Leave blank if you don't want to update this) : ";
                        std::cin >> isbn1;
                        std::cout << "\nEnter New Publisher of Book (Leave blank if you don't want to update this) : ";
                        std::cin >> publication1;
                    }
                }
            };
        };

        void delete_books(){
            // This function is to delete any of the books present
            fname = "books_data.txt";  // File storing all the book data
            std::string name;
            int number = 0; // To count the number of books searched
            std::cout << "\nEnter Book's Name : ";
            std::cin >> name;
            filei.open(fname.c_str());
            std::cout << "\n\n----------- CHOOSE THE BOOK YOU WANT TO DELETE ------------\n";
            std::ofstream fileout("temp.txt");  //Temporary file
            while (!filei.eof())
            {
                std::string choice;
                getline(filei, title);
                getline(filei, author);
                getline(filei, isbn);
                getline(filei, publication);

                // Convert to lowercase
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                std::string title1 = title;
                title1.erase(title1.find("Title : "), 8);
                std::transform(title1.begin(), title1.end(), title1.begin(), ::tolower);
                if ((name == title1) || (title1.find(name) != std::string::npos))
                {
                    number++;
                    std::cout << "\n---------- " << number << " ----------\n";
                    std::cout << title << std::endl;
                    std::cout << author << std::endl;
                    std::cout << isbn << std::endl;
                    std::cout << publication << std::endl;
                    std::cout << "\n\nDo you want to update this book? [Y/N] : ";
                    std::cin >> choice;
                    if ((choice == "Y") || (choice == "y")){
                        updatedatabase(title);
                    }
                }
            };
        };
};


// User Database class
class User_database {
    private:
        // std::vector<std::string> user_list{}; // Array of Strings to store the list of users

        void search_user(){
            // This function is to search for books
        };

        void add_user(){
            // This function is to add new books to the library
        };

        void update_user(){
            // This function is to update the information about the books
        };

        void delete_user(){
            // This function is to delete any of the books present
        };
};


class Professor : public User {
    public:
        double fine_amount;  // Store the fine amount generated
        // std::vector<std::string> book_list{}; // Array of Strings to store the list of books the professor has

        int choice(){
            int choice = 0, exit = 0, logout = 0;  // To store the choice

            while (exit == 0)
            {
                std::cout << "\n\n------------PROFESSOR MENU------------\n\n";
                std::cout << "1. See Book List\n2. List Books in Possession\n3. Search Book\n4. Issue Book\n5. Check Fine Generated\n6. Clear Fine Amount\n7. Logout\n";
                std::cin >> choice;

                Book_database books;
                if (choice == 1)
                {
                    books.display_all_books();
                }
                else if (choice == 3)
                {
                    books.search_books();
                }
                else if (choice == 7)
                {
                    logout = 1;
                    exit = 1;
                }
            }
            return logout;
        };

        void calculate_fine(){
            // Function to calculate the fine generated.
            /*
            - Can issue a book for 60 days. 
            - Fine is 5 rupees/day after due date.
            */
        };

        void clear_fine_amount(){
            // Function to clear all dues
            std::cout << "All Dues Cleared";
            fine_amount = 0;
        };
};

class Student : public User {
    public:
        double fine_amount;  // Store the fine amount generated
        // std::vector<std::string> book_list{}; // Array of Strings to store the list of books the student has

        int choice(){
            int choice = 0, exit = 0, logout = 0;  // To store the choice

            while (exit == 0)
            {
                std::cout << "\n\n------------STUDENT MENU------------\n\n";
                std::cout << "1. See Book List\n2.List Books in Possession\n3.Search Book\n4.Issue Book\n5.Check Fine Generated\n6.Clear Fine Amount\n7.Logout\n";
                std::cin >> choice;

                Book_database books;
                if (choice == 1){
                    books.display_all_books();
                }
                else if (choice == 3){
                    books.search_books();
                }
                else if (choice == 7)
                {
                    logout = 1;
                    exit = 1;
                }
            };
            return logout;
        };

        void calculate_fine(){
            // Function to calculate the fine generated.
            /*
            - Can issue a book for 30 days. 
            - Fine is 2 rupees/day after due date.
            */
        };

        void clear_fine_amount(){
            // Function to clear all dues
            std::cout << "All Dues Cleared";
            fine_amount = 0;
        };
};

class Librarian : public User {
    public:
        int choice(){
            int choice = 0, exit = 0, logout = 0;  // To store the choice

            while (exit == 0)
            {
                std::cout << "\n\n------------LIBRARIAN MENU------------\n\n";
                std::cout << "1. See Book List\n2. See User List\n3. Add Book\n4. Update Existing Book\n5. Delete Book\n6. Add User\n7. Update Existing User\n8. Delete User\n9. Logout\n";
                std::cin >> choice;

                Book_database books;
                
                if (choice == 1){
                    books.display_all_books();
                }
                else if (choice == 3){
                    books.add_books();
                }
                else if (choice == 4){
                    books.update_books();
                }
                else if (choice == 5){
                    books.delete_books();
                }
                else if (choice == 9)
                {
                    logout = 1;
                    exit = 1;
                }
            };
            return logout;
        };
};



// Main Function
int main(){
    int choice = 0;  // To choose the role of the user

    // Printing ASCII art
    printf("%s\n", LIBRARY);
    std::cout << "-----------------------WELCOME TO IIT KANPUR LIBRARY-----------------------" << std::endl;

    std::cout << "Choose your role :\n1.Professor (Press 1 to select this role)\n2.Student (Press 2 to select this role)\n3.Librarian (Press 3 to select to role)\nPress any other key and Enter to exit the application...\n";
    std::cin >> choice;

    int exit = 0;

    if (choice == 1){
        Professor professor;
        exit = professor.login_register("PROFESSOR");
        if (exit == 1){
            return 0;
        }
        int logout = professor.choice();
        if (logout == 1){
            exit = professor.login_register("PROFESSOR");
        }
    }
    else if (choice == 2){
        Student student;
        exit = student.login_register("STUDENT");
        if (exit == 1){
            return 0;
        }
        int logout = student.choice();
        if (logout == 1){
            exit = student.login_register("STUDENT");
        }
    }
    else if (choice == 3)
    {
        Librarian librarian;
        exit = librarian.login_register("LIBRARIAN");
        if (exit == 1){
            return 0;
        }
        int logout = librarian.choice();
        if (logout == 1){
            exit = librarian.login_register("LIBRARIAN");
        }
    }
    else
    {
        return 0;
    }

    return 0;
};