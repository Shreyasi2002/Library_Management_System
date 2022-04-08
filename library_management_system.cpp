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
#include <sstream>
#include "TextTable.h"

/* ************** REFERENCES ****************** */
/*
The `TextTable.h` is taken from https://github.com/haarcuba/cpp-text-table 
*/



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

int NUMBER_OF_LINES = 0;

int count_lines()
{
    // This function counts the lines present in books_data.txt
    std::ifstream myfile("copy.txt");
    std::string line;
    size_t count = 0;
    while ( getline(myfile, line) )
    {
        ++count;
    }
    return count;
}

void delete_last_line(std::string filename){
    std::ifstream fileIn(filename);  // Open for reading
    std::stringstream buffer;  // Store contents in a std::string
    buffer << fileIn.rdbuf();
    std::string contents = buffer.str();

    fileIn.close();
    contents.pop_back();  // Remove last character

    std::ofstream fileOut(filename , std::ios::trunc);  // Open for writing (while also clearing file)
    fileOut << contents;  // Output contents with removed character
    fileOut.close(); 
};

void get_last_lines(std::string file){
    // This function reads the last n lines from a file (discards the previous lines)
    std::ifstream myfile("copy.txt");
    std::ofstream fileo(file);
    int count = count_lines();
    std::string line;
    for ( int i = 0; i < count - NUMBER_OF_LINES; ++i )
    {
        getline(myfile, line); /* read and discard: skip line */
    }
    while (getline(myfile, line))
    {
        fileo << line << "\n";
    }
    remove("copy.txt");
    fileo.close();
};

// User Class and its child classes - Librarian, Professor, and Student
class User {
    protected:
        char name[100];  // Store student's name
        char id[100];  // Store user's ID
        char password[500]; // Store user's password
    public:
        /* *************** LOGIN AND REGISTRATION *************** */

        // Function to check validity of username and password for logging in
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
            std::ofstream user_file;
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
                        getline(filei,line);
                        std::cout<<"Bio: "<<line<<std::endl;
                        filei.close();
                        break;
                    }
                    else
                    {
                        std::cout<<"\nWrong Username or Password!\nPlease Try Again.\n";
                    }
                    // cout<<endl;
                }
                else if(choice==2)
                {
                    user_file.open("user_data.txt", std::ios::app);
                    std::cout << "\nEnter your name: ";
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
                    user_file<<usn<<std::endl<<name<<std::endl<<role<<std::endl;
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
            std::cin.ignore();
            getline(std::cin, name);
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
            std::cin.ignore();
            getline(std::cin, title);
            std::cout << "\nEnter Authors of Book : ";
            std::cin.ignore();
            getline(std::cin, author);
            std::cout << "\nEnter ISBN of Book : ";
            std::cin >> isbn;
            std::cout << "\nEnter Publisher of Book : ";
            std::cin.ignore();
            getline(std::cin, publication);
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
            std::cin.ignore();
            getline(std::cin, name);
            filei.open(fname.c_str());

            // Create a copy of the file `books_data.txt`
            std::ofstream out_file {"copy.txt"};
            std::string copy_line;
            while(getline(filei, copy_line)){
                out_file << copy_line << '\n';
                NUMBER_OF_LINES++;
            }
            filei.close();
            out_file.close();

            filei.open(fname.c_str());

            std::cout << "\n\n----------- CHOOSE THE BOOK YOU WANT TO UPDATE ------------\n";
            while (!filei.eof())
            {
                // Debugging
                printf("");
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
                    std::string line;
                    std::vector<std::string> lines;
                    number++;
                    std::cout << "\n---------- " << number << " ----------\n";
                    std::cout << title << std::endl;
                    std::cout << author << std::endl;
                    std::cout << isbn << std::endl;
                    std::cout << publication << std::endl;
                    std::cout << "\n\nDo you want to update this book? [Y/N] : ";
                    std::cin >> choice;
                    if ((choice == "Y") || (choice == "y")){
                        std::cout << "\nEnter New Title of Book (Type `none` if you don't want to update this) : ";
                        std::cin.ignore();
                        getline(std::cin, title12);
                        if (title12 != "none"){
                            std::fstream file("copy.txt", std::ios::in);
                            title12 = "Title : " + title12;
                            while(std::getline(file, line)) {
                                // std::cout << line << std::endl;

                                std::string::size_type pos = 0;

                                while ((pos = line.find(title, pos)) != std::string::npos){
                                    line.replace(pos, line.size(), title12);
                                    pos += title12.size();
                                }

                                lines.push_back(line);
                            }
                            file.close();
                            file.open("copy.txt", std::ios::out | std::ios::trunc);

                            for(const auto& i : lines) {
                                file << i << std::endl;
                            }
                            file.close();
                        }
                        std::cout << "\nEnter New Authors of Book (Type `none` if you don't want to update this) : ";
                        std::cin.ignore();
                        getline(std::cin, author1);
                        if (author1 != "none"){
                            std::fstream file("copy.txt", std::ios::in);
                            author1 = "Authors : " + author1;
                            while(std::getline(file, line)) {
                                // std::cout << line << std::endl;

                                std::string::size_type pos = 0;

                                while ((pos = line.find(author, pos)) != std::string::npos){
                                    line.replace(pos, line.size(), author1);
                                    pos += author1.size();
                                }

                                lines.push_back(line);
                            }
                            file.close();
                            file.open("copy.txt", std::ios::out | std::ios::trunc);

                            for(const auto& i : lines) {
                                file << i << std::endl;
                            }
                            file.close();
                        }
                        std::cout << "\nEnter New ISBN of Book (Type `none` if you don't want to update this) : ";
                        std::cin >> isbn1;
                        if (isbn1 != "none"){
                            std::fstream file("copy.txt", std::ios::in);
                            isbn1 = "ISBN : " + isbn1;
                            while(std::getline(file, line)) {
                                // std::cout << line << std::endl;

                                std::string::size_type pos = 0;

                                while ((pos = line.find(isbn, pos)) != std::string::npos){
                                    line.replace(pos, line.size(), isbn1);
                                    pos += isbn1.size();
                                }

                                lines.push_back(line);
                            }
                            file.close();
                            file.open("copy.txt", std::ios::out | std::ios::trunc);

                            for(const auto& i : lines) {
                                file << i << std::endl;
                            }
                            file.close();
                        }
                        std::cout << "\nEnter New Publisher of Book (Type `none` if you don't want to update this) : ";
                        std::cin.ignore();
                        getline(std::cin, publication1);
                        if (publication1 != "none"){
                            std::fstream file("copy.txt", std::ios::in);
                            publication1 = "Publisher : " + publication1;
                            while(std::getline(file, line)) {
                                // std::cout << line << std::endl;

                                std::string::size_type pos = 0;

                                while ((pos = line.find(publication, pos)) != std::string::npos){
                                    line.replace(pos, line.size(), publication1);
                                    pos += publication1.size();
                                }

                                lines.push_back(line);
                            }
                            file.close();
                            file.open("copy.txt", std::ios::out | std::ios::trunc);

                            for(const auto& i : lines) {
                                file << i << std::endl;
                            }
                            file.close();
                        }
                        printf("\n---------------- BOOK SUCCESSFULLY UPDATED ----------------\n");
                    }
                    
                }
            };
            // Get the last lines from `copy.txt` and keep it in `books_data.txt`
            filei.close();
            get_last_lines("books_data.txt");
            delete_last_line("books_data.txt");
            if (number == 0)
            {
                // Printing ASCII art
                printf("%s\n", NOTFOUND);
            }
        };

        void delete_books(){
            // This function is to delete any of the books present
            fname = "books_data.txt";  // File storing all the book data
            std::string name;
            int number = 0; // To count the number of books searched
            std::cout << "\nEnter Book's Name : ";
            std::cin.ignore();
            getline(std::cin, name);
            filei.open(fname.c_str());

            // Create a copy of the file `books_data.txt`
            std::ofstream out_file {"copy.txt"};
            std::string copy_line;
            while(getline(filei, copy_line)){
                out_file << copy_line << '\n';
                NUMBER_OF_LINES++;
            }
            filei.close();
            out_file.close();

            filei.open(fname.c_str());
            std::cout << "\n\n----------- CHOOSE THE BOOK YOU WANT TO DELETE ------------\n";
            std::ofstream temp("temp.txt");  //Temporary file
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
                    std::cout << "\n\nDo you want to delete this book? [Y/N] : ";
                    std::cin >> choice;
                    if ((choice == "Y") || (choice == "y")){
                        std::ifstream fin;
                        fin.open("copy.txt");
                        std::string del_line;

                        while (getline(fin, del_line))
                        {
                            if ((del_line != title) && (del_line != author) && (del_line != isbn) && (del_line != publication))
                            {
                                // std::cout << del_line << "\n";
                                temp << del_line << std::endl;
                            }
                        }
                        temp.close();
                        fin.close();
                        remove("copy.txt");
                        rename("temp.txt","copy.txt");
                    }
                    printf("\n -------------- BOOK SUCCESSFULLY DELETED --------------\n");
                }
            };
            // Get the last lines from `copy.txt` and keep it in `books_data.txt`
            filei.close();
            get_last_lines("books_data.txt");
            delete_last_line("books_data.txt");
            if (number == 0)
            {
                // Printing ASCII art
                printf("%s\n", NOTFOUND);
            }
        };
};


// User Database class
class User_database {
    public:
        // std::vector<std::string> user_list{}; // Array of Strings to store the list of users
        void display_all_users(){
            // delete_last_line("user_data.txt");
            std::ifstream filein("user_data.txt");

            printf("\n --------- USER LIST ---------\n");

            TextTable user_table( '-', '|', '+' );
            user_table.add("Username");
            user_table.add("Name");
            user_table.add("Role");
            user_table.endOfRow();

            std::string username, name, role;
            while (!filein.eof())
            {
                getline(filein, username);
                if (username == ""){
                    break;
                }
                getline(filein, name);
                getline(filein, role);

                user_table.add(username);
                user_table.add(name);
                user_table.add(role);
                user_table.endOfRow();
            }
            user_table.setAlignment( 2, TextTable::Alignment::RIGHT );
            std::cout << user_table;
        }

        // Function to check validity of username and password for adding new user
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

        void add_user()
        {
            // This function is to add new users
            std::string ans, psd, name, fname, bio, usern, pw, line, nusn, rol;
            std::ofstream fileo;
            std::ifstream filei;
            std::ofstream user_file;
            user_file.open("user_data.txt", std::ios::app);
            std::cout << "\nEnter the user's name: ";
            std::cin.ignore();
            getline(std::cin,name);
            std::cout<<"\nCreate a username: ";
            std::cin>>usn;
            std::cout<<"\nSpecify the role of the user: ";
            std::cin>>rol;
            // Convert to uppercase
            std::transform(rol.begin(), rol.end(), rol.begin(), ::toupper);

            tm=0;
            valid(usn, rol);
            if(tm>=3)
            {
                return;
            }

            std::cout<<"\nCreate a password: ";
            std::cin>>psd;
            fname=usn + rol +".txt";
            //cout<<fname;
            fileo.open(fname.c_str());
            fileo<<usn<<std::endl<<name<<std::endl<<psd<<std::endl<<rol<<std::endl;
            user_file<<usn<<std::endl<<name<<std::endl<<rol<<std::endl;
            std::cout<<"\nTHE USER IS SUCCESSFULLY REGISTERED AS A " << rol << " :)\n";
            
            // Adding bio for users
            std::cout<<"\nAdd bio and press enter if done: ";
            std::cin.ignore();
            getline(std::cin,bio);
            fileo<<bio<<std::endl;
            std::cout<<"\nThe user's bio is saved as: "<<bio<<std::endl;
            fileo.close();
            std::cout << "\n----------PROFILE IS SUCCESSFULLY CREATED----------\n";
        };

        void update_user()
        {
            // This function is to update the information about the users
        };

        void delete_user()
        {
            // This function is to delete any of the active users
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
                std::cout << "1. See Book List\n2. Search Book\n3. Issue Book\n4. Check Fine Generated\n5. Clear Fine Amount\n6. Logout\n";
                std::cin >> choice;

                Book_database books;
                if (choice == 1){
                    books.display_all_books();
                }
                else if (choice == 2){
                    books.search_books();
                }
                else if (choice == 6)
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
                std::cout << "1. See Book List\n2. Search Book\n3. Issue Book\n4. Check Fine Generated\n5. Clear Fine Amount\n6. Logout\n";
                std::cin >> choice;

                Book_database books;
                if (choice == 1){
                    books.display_all_books();
                }
                else if (choice == 2){
                    books.search_books();
                }
                else if (choice == 6)
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
                User_database users;

                if (choice == 1){
                    books.display_all_books();
                }
                if (choice == 2){
                    users.display_all_users();
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
                else if (choice == 6){
                    users.add_user();
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