# BiblioCatalog
BiblioCatalog is meant to be a simple portable library. As it is right now, it's only a simple program using a csv file for the moment.

## Goal 
First i'll work towards a fully operational app for linux shell. Once it's done, i'll try to go for a windows app using QT, and an android one using Google Studio. Then I want to be able to link all of them.

## Description of the actual code 
### Linux/Windows console app
For Linux, just run BiblioCatalog, it will asks you what you want to do. Go forward. It will create a csv file into the directory which will stock your books.

To create a Windows.exe console app, launch an app like Visual. Create a solution and put the .h/.cpp into it. 
Change every system("clear") by system("cls"). Compile. 
