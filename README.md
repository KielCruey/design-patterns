# Design Patterns
When attending my local C++ club, I asked around what good books to help with Objected Oriented Programming (OOP). People have mentioned the Gang of Four's book "[Design Patterns](https://www.amazon.com/Design-Patterns-Object-Oriented-Addison-Wesley-Professional-ebook/dp/B000SEIBB8)" to help with better more flexible and craftsmanship like code. Conveniently, I purchased the book a few years ago and it's been sitting on my shelf. Now is the time to actually learn the material now. So here we go!

## Structure
During the learning process, I will try to link some supplemental resources to help with the content of this book. Having a different points of view or more concise coding examples in a modern syntax clear up the evolution of the C++ language. Additionally, I will personally code some examples of the given design pattern to help me with my own personal understanding.

## Goals
The goal is to have the code:
* comment important thoughts and structures
* compile and create a build system (CMake)
* document code (Doxygen, Graphviz)
* unit test the code including mocking, faking, and subbing if needed with the GoogleTest Framework
* testing documentation
* static analysis (CppCheck)
* dynamic analysis (Valgrind)
* create a CI/CD loop (Github Actions)
* containerize the code on a Linux platform (Docker)

# CI/CD Notes
## CppCheck
### Generating Report(s)
Use the following commands to run CppCheck:
``` chell
cppcheck --enable=all <file-1> <file-2> ... // certain files
cppcheck --enable=all *.cpp *.hpp *.inl // all files in repo
```
This creates a report by hand.

However for creating a text report via .txt file, replace <file name> with whatever file you want it:
``` shell
cppcheck --suppress=missingIncludeSystem --suppress=toomanyconfigs --error-exitcode=1 --enable=all --output-file=cppcheck-report.txt .
```
after running the following command the output of cppcheck will be 1 if there are warnings given or 0 if there aren't any errors. Run the following to see what the output is:
``` shell
echo $? // prints out exit status
```

used this [repo](https://github.com/marketplace/actions/cppcheck-action) for yaml file.

## Doxygen
[Doxygen Documentation](https://www.doxygen.nl/manual/index.html)

### Configuring Doxygen
In order to create a LaTex, XML, or PDF file, you must create a configuration file. To do so, use the following command:
``` bash 
$ doxygen -g // no name on config file will default to "Doxyfile"
$ doxygen -g <config-file>
```
### Generating Report(s)

``` bash
$ doxygen <config-file>
```

Once the documentation is created, look into the `doxygen/html` directory and open `index.html` in your favorite web browser. This will provide you a viewable and dynamic website-like documentation.

## CMake
Use the following commands to configure and build CMake artifacts:
``` bash
$ cmake -G "MinGW Makefiles" -B build -S . # config/generation stage
$ cmake --build build # build stage
```

# Design Pattern Resources
## Behavior Patterns
### Chain of Responsibility
[Article](https://en.wikipedia.org/wiki/Chain-of-responsibility_pattern)
[Article 2](https://en.wikipedia.org/wiki/Chain-of-responsibility_pattern)

### Command
[Article](https://www.bogotobogo.com/DesignPatterns/command.php)
[Article #2](https://refactoring.guru/design-patterns/command)

### Memento
[Article](https://refactoring.guru/design-patterns/memento)

### State
[Article](https://refactoring.guru/design-patterns/state)

### Template Method
[Article](https://refactoring.guru/design-patterns/template-method)

## Creational Patterns
### Abstract Factory
[Article](https://refactoring.guru/design-patterns/abstract-factory/cpp/example)
[Article #2](https://refactoring.guru/design-patterns/abstract-factory)

### Builder
[Article](https://hackernoon.com/c-type-casting-for-c-developers-0c823y9k)

### Factory Method
[Article](https://refactoring.guru/design-patterns/factory-method/cpp/example)
[Article #2](https://www.modernescpp.com/index.php/factory-method/)

### Prototype
[Article](https://refactoring.guru/design-patterns/prototype)

### Singleton
[Article](https://refactoring.guru/design-patterns/singleton)

## Structural Patterns
### Adapter
[Article](https://refactoring.guru/design-patterns/adapter)

### Bridge
[Article](https://refactoring.guru/design-patterns/bridge)

### Facade
[Article](https://medium.com/@andreaspoyias/design-patterns-a-quick-guide-to-facade-pattern-16e3d2f1bfb6)

### Composite
[Article](https://refactoring.guru/design-patterns/composite)

### Decorator
[Article](https://refactoring.guru/design-patterns/decorator)

### Facade 
[Article](https://refactoring.guru/design-patterns/facade)

### Proxy
[Article](https://cppcodetips.wordpress.com/2017/03/31/proxy-design-pattern-explained-with-c-sample/)

### Vistor
[Article](https://www.scaler.com/topics/design-patterns/visitor-design-pattern/)

[Article 2](https://www.modernescpp.com/index.php/the-visitor-pattern/)

## General Resource
Another good [Design Pattern Book](https://www.cs.up.ac.za/cs/lmarshall/TDP/TDP.html)

[Design Pattern Wiki](https://en.wikipedia.org/wiki/Software_design_pattern#Concurrency_patterns)