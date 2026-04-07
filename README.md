# 🚀 C++ Modules (00 - 09)

> *A comprehensive dive into Object-Oriented Programming, moving from C to C++98. Built as part of the 42 Network / 1337 curriculum.*

## 💡 About The Series

The C++ modules are a series of progressively difficult exercises designed to teach the fundamentals of Object-Oriented Programming (OOP) and the C++98 standard. 

Unlike the pure C projects of the early 42 curriculum, these modules introduce a completely new paradigm: objects, classes, encapsulation, inheritance, and polymorphism. A core requirement across all these modules is strict adherence to the **Orthodox Canonical Class Form** (requiring a default constructor, copy constructor, copy assignment operator, and destructor for almost every class).

> **Note on Portfolio Consolidation:** These modules were completed sequentially as part of my core C++ training. I am grouping them into this single repository to showcase my progression from basic syntax to advanced template programming and standard library integration.

## 📚 Curriculum Breakdown

Here is a summary of the concepts mastered in each module:

### **CPP 00: Basics & Encapsulation**
* **Concepts:** Namespaces, classes, member functions, standard I/O streams (`std::cin`, `std::cout`), initialization lists, `static` variables, `const` member functions.
* **Focus:** Transitioning from procedural C to basic OOP.

### **CPP 01: Memory & References**
* **Concepts:** Memory allocation (`new` and `delete`), references vs. pointers, pointers to members, array allocations, and switch statements.
* **Focus:** Safe memory management in C++ and understanding the subtle but crucial differences between pointers and references.

### **CPP 02: Polymorphism & Overloading**
* **Concepts:** Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Class Form.
* **Focus:** Creating a custom `Fixed` point number class, manipulating bits, and defining how standard operators (`+`, `-`, `*`, `/`, `<<`) interact with custom objects.

### **CPP 03: Inheritance**
* **Concepts:** Inheritance, `protected` attributes, and constructor/destructor calling chains.
* **Focus:** Building a hierarchy of classes (e.g., `ClapTrap`, `ScavTrap`) that inherit properties and methods from parent classes to avoid code duplication.

### **CPP 04: Subtype Polymorphism & Interfaces**
* **Concepts:** Subtype polymorphism, `virtual` functions, abstract classes, and deep copies.
* **Focus:** Understanding how base class pointers can execute derived class methods, and building highly modular code using pure virtual functions (Interfaces).

### **CPP 05: Exceptions**
* **Concepts:** Exception handling (`try`, `catch`, `throw`), custom exception classes.
* **Focus:** Moving away from C-style error codes (returning `-1` or `NULL`) and embracing C++ exception throwing for robust error management.

### **CPP 06: C++ Casts**
* **Concepts:** Type conversion using `static_cast`, `dynamic_cast`, `reinterpret_cast`, and `const_cast`.
* **Focus:** Understanding the strict type safety of C++ and knowing exactly when and how to safely convert between different data types and object hierarchies.

### **CPP 07: Templates**
* **Concepts:** Function templates and Class templates.
* **Focus:** Writing generic, type-independent code that allows the compiler to generate specific implementations on the fly.

### **CPP 08: Templated Containers, Iterators, Algorithms**
* **Concepts:** The Standard Template Library (STL).
* **Focus:** Utilizing standard containers (like `std::vector`, `std::list`), mastering iterators to traverse them, and applying standard algorithms (like `std::find`, `std::sort`).

### **CPP 09: Advanced STL & Algorithmic Efficiency**
* **Concepts:** Advanced use of STL containers to solve complex data problems.
* **Focus:** Applying the right data structures to build things like a Reverse Polish Notation (RPN) calculator and implementing highly optimized sorting algorithms (like the Ford-Johnson merge-insert sort).

## 🚀 Compilation & Usage

Each module is contained in its own directory and sub-directories (one for each specific exercise). 

### Prerequisites
* A C++ compiler (e.g., `c++`, `g++`, or `clang++`)
* `make`

### Standard Compilation
Navigate to the specific exercise directory and run `make`. All projects are strictly compiled with the C++98 standard:

```bash
cd cpp00/ex01
make
./phonebook
