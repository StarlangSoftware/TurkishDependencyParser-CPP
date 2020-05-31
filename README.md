# TurkishDependencyParser

This tool is used for Dependency Parsing of Turkish sentences: it breaks down sentences into components and links each component to another in terms of its function, eventually connecting all words together into the root node.

For Developers
============
You can also see either [Java](https://github.com/starlangsoftware/TurkishDependencyParser), [Python](https://github.com/starlangsoftware/TurkishDependencyParser-Py), or [C#](https://github.com/starlangsoftware/TurkishDependencyParser-CS) repository.

## Requirements

* [C++ Compiler](#cpp)
* [Git](#git)


### CPP
To check if you have compatible C++ Compiler installed,
* Open CLion IDE 
* Preferences >Build,Execution,Deployment > Toolchain  

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called TurkishDependencyParser-CPP will be created. Or you can use below link for exploring the code:

	git clone https://github.com/starlangsoftware/TurkishDependencyParser-CPP.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu. After compilation process, user can run TestDependencyParser.cpp .
