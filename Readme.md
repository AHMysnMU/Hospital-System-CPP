# Hospital Management System

A simple console-based **Hospital Management System** written in **C++**.

This project was created to practice fundamental C++ concepts such as functions, arrays, loops, conditions, input validation, and basic data management.

## Features

* Login system with limited attempts
* Change password
* Add patients
* View a specific patient
* Edit patient information
* Delete patients
* List all patients in a formatted table
* Prevent duplicate patient IDs
* Validate gender input
* Maximum capacity of 100 patients

## Patient Information

Each patient stores the following information:

* ID
* Name
* Age
* Gender
* Disease
* Phone Number

## Default Login

```text
Username: admin
Password: 123
```

The password can be changed after logging in.

## Technologies Used

* C++
* Standard C++ Libraries
* Console / Terminal

## Important Note

This version is designed to run on **Windows** because it uses:

```cpp
system("cls");
```

to clear the console screen.

`cls` is a Windows command and does not work on macOS or Linux.

For macOS/Linux, it can be replaced with:

```cpp
system("clear");
```

## Purpose

This project is mainly for learning and practicing C++ programming concepts. It uses arrays and procedural programming rather than databases or advanced data structures, making it suitable as a beginner-level console application.
