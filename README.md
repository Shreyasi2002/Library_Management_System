# Library Management System

The mentioned application allows three types of users to register and login -
1. Professor
2. Student
3. Librarian

```
     ____________________________________________________
    |____________________________________________________|
    | __     __   ____   ___ ||  ____    ____     _  __  |
    ||  |__ |--|_| || |_|   |||_|**|*|__|+|+||___| ||  | |
    ||==|^^||--| |=||=| |=*=||| |~~|~|  |=|=|| | |~||==| |
    ||  |##||  | | || | |JRO|||-|  | |==|+|+||-|-|~||__| |
    ||__|__||__|_|_||_|_|___|||_|__|_|__|_|_||_|_|_||__|_|
    ||_______________________||__________________________|
    | _____________________  ||      __   __  _  __    _ |
    ||=|=|=|=|=|=|=|=|=|=|=| __..\/ |  |_|  ||#||==|  / /|
    || | | | | | | | | | | |/\ \  \|++|=|  || ||==| / / |
    ||_|_|_|_|_|_|_|_|_|_|_/_/\_.___\__|_|__||_||__|/_/__|
    |____________________ /\~()/()~//\ __________________|
    | __   __    _  _     \_  (_ .  _/ _    ___     _____|
    ||~~|_|..|__| || |_ _   \ //\\ /  |=|__|~|~|___| | | |
    ||--|+|^^|==|1||2| | |__/\ __ /\__| |==|x|x|+|+|=|=|=|
    ||__|_|__|__|_||_|_| /  \ \  / /  \_|__|_|_|_|_|_|_|_|
    |_________________ _/    \/\/\/    \_ _______________|
    | _____   _   __  |/      \../      \|  __   __   ___|
    ||_____|_| |_|##|_||   |   \/ __|   ||_|==|_|++|_|-|||
    ||______||=|#|--| |\   \   o    /   /| |  |~|  | | |||
    ||______||_|_|__|_|_\   \  o   /   /_|_|__|_|__|_|_|||
    |_________ __________\___\____/___/___________ ______|
    |__    _  /    ________     ______           /| _ _ _|
    |\ \  |=|/   //    /| //   /  /  / |        / ||%|%|%|
    | \/\ |*/  .//____//.//   /__/__/ (_)      /  ||=|=|=|
  __|  \/\|/   /(____|/ //                    /  /||~|~|~|__
    |___\_/   /________//   ________         /  / ||_|_|_|
    |___ /   (|________/   |\_______\       /  /| |______|
        /                  \|________)     /  / | |

-----------------------WELCOME TO IIT KANPUR LIBRARY-----------------------
Choose your role :
1.Professor (Press 1 to select this role)
2.Student (Press 2 to select this role)
3.Librarian (Press 3 to select to role)
Press any other key and Enter to exit the application...
```

After this we will be shown login and register options (which includes validation) - 
```
-----------------------Welcome to our Library Management System!-----------------------

Choose one option:
1. SignIn (Press 1 to select this)
2. Register (Press 2 to select this)
Press Any key and Enter to exit
```

Let's register as a Student / Professor. The users can also add a bio in their profile section (while creating their account) :
```
Enter your name: Shreyasi Mandal

Create a username: shreyasi

Create a password: abcd

YOU ARE SUCCESSFULLY REGISTERED AS A PROFESSOR :)

Add your bio and press enter when you are done: This is the bio section

Your bio is saved as: This is the bio section

----------YOU CAN NOW LOGIN WITH YOUR USERNAME AND PASSWORD----------
```
Now lets see how to login and profile section -
```
Enter your username: shreyasi

Enter your password: abcd

You are successfully logged in:)

 __      __       .__                                
/  \    /  \ ____ |  |   ____  ____   _____   ____   
\   \/\/   // __ \|  | _/ ___\/  _ \ /     \_/ __ \  
 \        /\  ___/|  |_\  \__(  <_> )  Y Y  \  ___/  
  \__/\  /  \___  >____/\___  >____/|__|_|  /\___  > 
       \/       \/          \/            \/     \/  


YOUR PROFILE SAYS:
Username: shreyasi
Name: Shreyasi Mandal
Role: Professor
Bio: This is the bio section


------------PROFESSOR MENU------------

1. See Book List
2. List Books in Possession
3. Search Book
4. Issue Book
5. Check Fine Generated
6. Clear Fine Amount
7. Logout
```
As we can see from above, the profile of the user (including role) is shown once the user logs in, and the menu of the professor is visible.

**I was only able to implement 1. See Book List, 3. Search Book, and 7. Logout options...**

The books data is stored in `books_data.txt`

The book list is shown as follows -
```
            /;
           / |'-,.
          /  '    `"---,.__
         /  '    ,'     ,  '"--,"|
        /  '    ,     ,'     ,"::|
       /  '   ,'    ,      ,"::::|
      /  '   ,    ,'     ,"::::::L
     /  '  ,'   ,'     ,"::::::::L
    /  '  ,    ,     ,":::::::::J
    k-,._    ,'   _.":::::::::::J
     \.  `"----'"".J::::::::::::|
      \.    .-,    .L:::::::::::|
       \.  (       .J:::::::::::!
        \.  `--     .L:::::::::/
         \.   .-.   .|::::::::/
          \. (   )  .J:::::::/
           \. `-'    .L:::::/
            \.  L    .|::::/
             \. !__  .J:::/
              \.  __  .L:/
               \. L_) .|/
                `-,__,-'


---------- 1 ----------
Title : Casting light on the dark side of brain imaging
Authors : Raz, Amir & Thibault, Robert T.
ISBN : 9780128161791
Publisher : London Academic Press 2019

---------- 2 ----------
Title : An Introduction to Statistical Learning: with Applications in R
Authors : Gareth James & Daniela Witten
ISBN : 9780120161594
Publisher : McGraw Hills

---------- 3 ----------
Title : Data Mining and Analysis: Fundamental Concepts and Algorithms
Authors : Mohammed J. Zaki, Wagner Meira Jr
ISBN : 9780521766333
Publisher : Cambridge University Press

---------- 4 ----------
Title : demo
Authors : demo
ISBN : 123456789
Publisher : demo
```
We can search the books using the **title** of the book as seen as follows -
```

         _.-----._
       .'.-'''''-.'._
      //`.: :'    `\\\
     ;; '           ;;'.__.===============,
     ||             ||  __                 )
     ;;             ;;.'  '==============='
      \\           ///
       ':.._____..:'~
         `'-----'`


Enter Book's Name : Dat 


----------- SEARCH RESULTS ------------

---------- 1 ----------
Title : Data Mining and Analysis: Fundamental Concepts and Algorithms
Authors : Mohammed J. Zaki, Wagner Meira Jr
ISBN : 9780521766333
Publisher : Cambridge University Press
```
```

         _.-----._
       .'.-'''''-.'._
      //`.: :'    `\\\
     ;; '           ;;'.__.===============,
     ||             ||  __                 )
     ;;             ;;.'  '==============='
      \\           ///
       ':.._____..:'~
         `'-----'`


Enter Book's Name : JK


----------- SEARCH RESULTS ------------

███╗░░██╗░█████╗░████████╗██╗░░██╗██╗███╗░░██╗░██████╗░  ███████╗░█████╗░██╗░░░██╗███╗░░██╗██████╗░
████╗░██║██╔══██╗╚══██╔══╝██║░░██║██║████╗░██║██╔════╝░  ██╔════╝██╔══██╗██║░░░██║████╗░██║██╔══██╗
██╔██╗██║██║░░██║░░░██║░░░███████║██║██╔██╗██║██║░░██╗░  █████╗░░██║░░██║██║░░░██║██╔██╗██║██║░░██║
██║╚████║██║░░██║░░░██║░░░██╔══██║██║██║╚████║██║░░╚██╗  ██╔══╝░░██║░░██║██║░░░██║██║╚████║██║░░██║
██║░╚███║╚█████╔╝░░░██║░░░██║░░██║██║██║░╚███║╚██████╔╝  ██║░░░░░╚█████╔╝╚██████╔╝██║░╚███║██████╔╝
╚═╝░░╚══╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝╚═╝░░╚══╝░╚═════╝░  ╚═╝░░░░░░╚════╝░░╚═════╝░╚═╝░░╚══╝╚═════╝░

```

The **Student** view is also the same as **Professor**

Now, lets look at the **Librarian** view -
```

------------LIBRARIAN MENU------------

1. See Book List
2. See User List
3. Add Book
4. Update Existing Book
5. Delete Book
6. Add User
7. Update Existing User
8. Delete User
9. Logout
```
Here, **I have implemented 1. See Book List, 3. Add Book, 4. Update Existing Book, 5. Delete Book**
