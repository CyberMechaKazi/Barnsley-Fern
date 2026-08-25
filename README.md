# Barnsley Fern – OpenGL C++

A simple computer graphics project written in **C++** using **OpenGL** and **GLUT**. The program generates and displays a **Barnsley Fern fractal** by plotting thousands of points using mathematical transformations.

## 🌿 About the Project

The Barnsley Fern is a mathematical fractal that produces a shape similar to a natural fern.

This program starts with an initial point and repeatedly applies different affine transformations. A random number determines which transformation is selected during each iteration.

The program generates **200,000 points**, which together create the final fern shape.

## 🛠️ Technologies Used

* C++
* OpenGL
* GLUT (OpenGL Utility Toolkit)
* Computer Graphics
* Fractal Generation

## ✨ Features

* Generates a Barnsley Fern fractal
* Uses 200,000 points to create the fern
* Uses random probability to select transformation rules
* Displays the fern in green using OpenGL points
* Maintains the drawing's aspect ratio when the window is resized
* Supports keyboard input
* Press **Q** or **ESC** to close the program
* Includes GLUT header support for macOS and Windows/Linux

## 🧮 How It Works

The program uses four different affine transformation rules. Each rule has a different probability of being selected.

For every iteration, the program calculates a new point using:

```text
x' = a*x + c*y + e
y' = b*x + d*y + f
```

An **affine transformation** is a mathematical operation that can move, scale, rotate, or reshape points.

By repeating these transformations thousands of times, the individual points gradually form the shape of a fern.

## ▶️ Program Output

When the program runs, an OpenGL window opens and displays a **green Barnsley Fern fractal** made from many individual points.

## 📁 Project Structure

```text
Barnsley-Fern/
│
├── main.cpp
└── README.md
```

## 🎮 Controls

| Key   | Action           |
| ----- | ---------------- |
| `Q`   | Exit the program |
| `ESC` | Exit the program |

## 📚 Purpose

This project demonstrates basic concepts of:

* OpenGL graphics programming
* Fractal generation
* Random number generation
* Affine transformations
* GLUT window and keyboard handling
* C++ graphics programming

## 👤 Author

**Kazi Islam (Ash)**

Computer Science Student
