# Line Editor - Help

## Introduction

Line Editor is a command-line text editor written in C.

It allows users to insert, delete, replace, display, save and load lines of text.

## Commands

### insert

Inserts a new line at the given position.

Example:

Enter command: insert
Enter position: 2
Enter text: Hello

### delete

Deletes a line from the document.

Example:

Enter command: delete
Enter position: 2

### replace

Replaces an existing line with new text.

Example:

Enter command: replace
Enter position: 1
Enter new text: New text

### display

Displays all lines in the document.

Example:

Enter command: display

### save

Saves the current document into document.txt.

Example:

Enter command: save

### load

Loads the saved document from document.txt.

Example:

Enter command: load

### help

Displays the available commands.

Example:

Enter command: help

### exit

Closes the Line Editor.

Example:

Enter command: exit

## Compile

gcc main.c -o line_editor

## Run

./line_editor

## Invalid Position

If an invalid line position is entered, the editor displays:

Invalid position.

## Save File

The save command creates:

document.txt

The load command reads the contents of this file.