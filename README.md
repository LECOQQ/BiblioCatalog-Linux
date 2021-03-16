# BiblioCatalog
BiblioCatalog is meant to be a simple portable library. As it is right now, it's only a simple program using a csv file.

## Goal 
This is a repository supposed to host the Linux version of BiblioCatalog.

## Description of the actual code 
### Linux bin file
For Linux, just run BiblioCatalog, it will asks you what you want to do. Go forward. It will create a csv file into the directory which will stock your books.

### Windows .exe
To create a Windows.exe console app, launch an app like Visual. Create a solution and put the .h/.cpp into it. 
Change every system("clear") by system("cls"). You can remove the <cstring> include. Compile. 
