# Interpreted Language Example (Clang)

## Created using ChatGPT 3.5

This repository showcases an example of a simple interpreted language implemented in C using the Clang compiler. The purpose of this project is to provide a basic understanding of building an interpreter for a custom programming language.

## Features

* Language Basics: The interpreted language supports basic functionality for declaring and manipulating string variables.

* Strong Typing: The language enforces strong typing, allowing only string data type in this example.

* Print Function: The language includes a print function for displaying the value of variables.

* Interpretation: The interpreter reads and executes code written in the custom language.

## Usage

1. Clone the repository.
2. Compile the interpreter using Clang.
3. Create a text file with code written in the custom language.
4. Execute the interpreter with the text file as a command-line argument.

The interpreter will read and interpret the code, displaying the output.

### Apple Silicon compilation example

```bash
clang -arch arm64 -o interpreter main.c
```

### Example code to be interpreted

Create a `test.txt` file, and use the following example Code:

```
my_var = string("this is a string");
print(my_var);
```

### Example code execution

Example interpreter execution in UNIX-based terminals:

```bash
./interpreter test.txt
```

## Contributions

Contributions to this project are welcome! If you have any ideas for improvements, additional features, or bug fixes, feel free to submit a pull request.

## License

This project is licensed under the MIT License.

