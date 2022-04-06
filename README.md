# Chimera Programming Langauge

Chimera the programming language aims to help developers create and maintain software by allowing them to build the smallest parts of the program in software, and combining them to form the full solution to whatever problem facing the developer. Please note that this language is still in development.

This project is a means of learning how programming languages on the whole work and let me explore how certain features impact the experience of writing software

## Table of Contents

1. [Installation](#installation)
1. [Hello world](#hello-world)
1. [Data Types](#data-types)
1. [Operations](#operations)
1. [Loops](#loops)
1. [If-Statement](#if-statements)
1. [Keywords](#keywords)
1. [Functions](#functions)
1. [User Input](#user-input)

## Installation

[Table of Contents](#toc)

## Steps for Windows Only

1. Go to Start
1. Search "Command Prompt"
1. right click on the top result and select "Run as Administrator"
1. type ```wsl --install```. If you need more help installing wsl go [here](https://docs.microsoft.com/en-us/windows/wsl/install)
1. Restart your computer
1. Search for "Ubuntu" in the start menu and click the top result
1. Open it, create a user name and passowrd
1. type the folowing below and wait for it to finish

```bash  
sudo apt install make && sudo apt install g++  
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install flex bison
```

### **Steps for Mac Only**

1. will update later when I can figure out how to install on make, flex, and bison on mac

Now download the project to some place you can easily access it. For the sake of this
guide I will assume it's place in a folder on your desktop.

To download, scroll up on this page until you see the "Code" button, and download this project by
whatever means you perfer.

Then place it in a folder on your desktop, I will refer to the folder as "PL" in this
guide.

### **In the terminal type the following command**

for windows (in wsl) ```cd /mnt/c/Users/<your user folder>/Desktop/PL/Chimear-main/```\
for mac ```cd ~/Desktop/PL/Chimera-main/```

Then type ```make && make run``` in the terminal, wait for the program to compile, and move on to the "Hello World" section

## Hello World

[Table of Contents](#table-of-contents)

in the running terminal type

```text
print|"Hello world"|
```

the output you'll see on the screen should be

```text
hello world
```

There is more you can do then just print text onto the screen. For example you can store data in variables, and print those variables onto the screen

```text
(= x:int 10)
print|x|
#Output: 10
```

see [Data Types](#data-types) for more information on supported base types

You can also do operations on data and store the results in a variable

```text
(= x:int (mul 5 2))
print|x|
#Output: 10
```

You can also make union types that can hold multiple types of data

```text
(= x:[int|string] (add 1 1))
print|x|
#Output: 2

(= x (add "hello " "world"))
print|x|
#Output: hello world
```

To quit the program type

```text
exit||
```

## Data Types

[Table of Contents](#table-of-contents)

### **Base Data types**

1. int: holds a whole number (example 1, 77)
1. float: holds a decimal number (example 3.14)
1. double: holds a larger decimal number
1. char: holds a single letter
1. string: holds many letters
1. bool: holds a true or false value
1. list: holds an array of any datatype (lists hold duck typed data)
1. map (holds a set of key-value pairs, pairs are duck types for both the key and value)

a character is a single letter surrounded by single quotes, whereas a string is one or more letters surrounded by double quotes

**Note**: you can cast any base type into any other type other base type (maps and lists can be converted to any of the other types but you can't convert any other types to a list or map at this time). In the case of casting a string to a number, if the string represents a number it will be converted to that represented number. Otherwise a hash of the string will be returned
see [Operations](#operations) to learn how to cast

### **Union Types**

a variable can be composed of one or more of the above base types. For example

```text
(= int_or_float:[int|float] 1)
# do stuff
(= int_or_float 3.12)

# or

(= string_or_boo:[string|bool] true)
# do stuff
(= string_or_bool "hello world")
```

If you want a variable to be composed of all the types, you can use the 'unknown' keyword

```text
(= u:unknown 0)

# float
(= u 1.1f)

# double
(= u 1.2)

(= u true)
(= u "hello world")
(= u 'c')

```

Note that a variable composed of more then one type are still checked for it's current type
when an operaiton is performed

```text
(= s_or_i:[int|string] "hello world")

#ok
print|(add s_or_i " and mars")|

#ok
(= s_or_i 0)
print|(add s_or_i 2)|

#will crash the program
print|(add s_or_i "hello")|
```

### **Reference Types**

You can make a reference to any variable as well.
A reference is basically giving a variable extra names

```text
(= x:int 10)
(= y:{int ref} x)

# changes the value in x
(= y (add y 1))

print|x y|
#Output: 11 11
```

Note: all the base types have a corrisponding reference type. If you use a reference, it's type has to match the variable it's referenceing (i.e. a string var can't be stored in an int ref)

Note: you cannot store a Union type into a reference of any kind

To reassign a ref

```text
(= x:int 10)
(= y:int{int ref} x)

(= z:int 11)
(= y z{int ref})

print|x y|
#Output 10 11
```

### **implicit typing**

a variable doesn't need to have an explicit type given as long as you give a valid peice of data
```text
# will make a string var
(var str "hello world")

# will make an int type
(var i 50)

# will decide the type at assignment time
# could become a string, int, float, or double
(var user_data (get_input "enter data: "))
```

note that unlike in languages like python, you cannot reassign the value of a variable to be that of a different type. once you made a variable like this its type is locked in. (see [Union Types](#union-types)) for dynamic runtime typing

### **typeof**
you can get the type of the a value by doing the following
```text
print|(typeof 99)|
#output: int
```
note you can use anything that yields a value as an arguement of typeof

### **string operations**

there are a few operations that strings share with lists and maps

you can get the size of the string, and a character at some index
```text
(var str "hello world")

print|str.size| #output: 11

print|(get str 2)| #output: l

# note with indexing a string, if you enter a negative value it will wrap around to the end of the string, and if it's greater then the size of the string it will wrap around to the beginning
```

### Containers

#### **List**

chimera supports two types of container type currently. A list and a map. A list can contain one or more peices of data

```text
# init list
(= int_list:list [])

# add item to list
int_list.put|1|
int_list.put|2|
int_list.put|3|
int_list.put|4|
int_list.put|5|
print|int_list|

#Output: [1, 2, 3, 4, 5]
```

Note: unlike other types lists do not enforce any specific type that can be put into it. while all base types (like int, double, bool) can't be changed to another type. lists are ducktyped in that any data can be stored in them at any time

```text
# Get item and set item example
(= int_list:list [1 true 3 "hello" 5])

# Get item from list
print|(get int_list 0)|
#Output: 1

# list name, index, new val
$ 
note that the below ways is the only built in way of setting a value in a container currently. doing something like "int_list[0] = 77" won't workd

also this is a multiline comment
$

int_list.set|0 77|
print|(get int_list 0)|
#Output: 77
```

**Note** that operations can fail just like if you tried to access them vai a variable, and do an illegal operation

#### ***Map***

Maps associate one type of data with another. for example a string value can be associated with a int value

```text
(= test_map:map {})

test_map.put|"hello ten" 10|
test_map.put|"hello 20" 20|

print| (get test_map "hello ten") (get test_map "hello 20") |
#Output: 10 20
```

Note: much like lists maps can also contain any type of data as either the key or value at any time

```text
# init map with values
(= test_map: map {
    |"hello" -> "world"|
    |[1 2 3] -> "list"|
    |true -> 'c'|
})

#or

(= test_map_2: map { |"hello" -> "world"| |[1 2 3] -> "list"| |true -> 'c'| })
```

#### ***Container Operations***

currently can

1. add values to a container (to the end in a list, and as a key in a map)
1. get values using an index
1. setting values using the index and a new value

## Operations

[Table of Contents](#table-of-contents)

### Math Operations

1. (add [two or more numbers | strings]): adds all the arguments together (concatenate strings)
1. (sub [two or more numbers | strings]): subtracts all the arguments (removes a substring from another string if possible, does nothing otherwise)
1. (mul [two or more numbers]): multiplies all the arguments
1. (div [two or more numbers]): divides all the arguments
1. (pow base exp)
1. (pow two or more number): (pow 1 2 3) = (pow 1 (pow 2 3))
1. (mod exp1 exp2): gets the remainder 2 inputs exp1 % exp2
1. (inc exp): will increase the value of a number type by 1

Note: arguments are evaluated from left to right, and the left arguement has an operation performed on it using the right argument\
Note: every argument after the first will be casted to the type of the first argument. So

```text
print|(add 1 3.2 1.2)|
#Output 5, not 5.4 because everything was casted to an int
#This bug will be fixed as time goes on
```

### Compare Operators

1. (less exp1 exp2)
1. (greater exp1 exp2)
1. (less-equal exp1 exp2)
1. (greater-equal exp1 exp2)
1. (equal exp1 exp2)
1. (not-equal exp1 exp2)

Note: when comparing values of different types, the result will always be false\
Note: for bool types, every operator but 'equal' and 'not-equal' automatically returns false

### Bool Operators

1. (and value value)
1. (or value value)
1. (not value)

### Misc Operators

1. (cast exp [type])

## Loops

there are 2 types of loops supported. For loops and while loops

```text
# for loop (the 5 and i are arbitrary, you can choose any number and var name)
repeat 5 with i start
    # do stuff
end

# while loop
while <boolean expression> start
    # do stuff
end
```

each loop has it's own scope (place in code with it's own set of varibles not accessable in other parts of the code)

## If Statements

supports branches in the code via if-statements

```text
if <bool expressions> start

else-if <bool expresion> start
    # can have as many if-else statements as you like
else start

end
```

note that the else-if/else parts of the if statement are optional

## Functions

[Table of Contents](#table-of-contents)

The syntax for functions looks like below

```text
suro foo|<params>|: <ret type> start
    # code here
end

suro foo|<params>| start
    # code here
end

# a runnable example
suro bar|val: int|: int start
    print|"passed in val:" val|
    return 0
end

suro foo|string|: bool start
    return (greater arg0.size 0)
end
```
### **parameter naming**

the programmer can choose to name or omit any of the paramters names in the paramter list. if a name is omitted the interpreter will give that argument the name of "arg(n)" where n is the index of the parameter in the list starting at 0

```text
suro foo|int string can_do:bool| start
    print|arg0 arg1 can_do|
end

(call foo 0 "hello world" false)
# output: 0 hello world false
```


### **function types**

there are 3 different types of functions within Chimera (suro, furo, and func)

the main difference between the 3 types is how the parameters are passed in

1. suro: everything but consts and temp values are passed in by reference. const and temp vals are cloned in
1. furo: everything is copied over into the function
1. func: everything but lists and maps are copied into the function

suro example
```text
(var i:int 0)
(var l:list [])

suro foo|int list| start
    (= arg0 5)
    list.addTo|20|
end
(call foo i l)
print|i l| #output: 5 [20] (note the original value was changed)

```

furo example
```text
(var i:int 0)
(var l:list [])

furo foo|int list| start
    (= arg0 5)
    arg1.addTo|20|
end

(call foo i l)
print|i l| #output: 0 [] (note the original value wasn't changed)
```

func example
```text
(var i:int 0)
(var l:list [])

func foo|int list| start
    (= arg0 5)
    arg1.addTo|20|
end

(call foo i l)
print|i l| #output: 0 [20] (notice only the list has an altered value)

```

### **function return vals**
a function always has a return value. The default return value of a function is an int. in the case no return keyword is used, the function will return 0 (or equivalent value of whatever type declared by the programmer)

note: functions cannot yet return maps or lists, but that will come in a future update

```text
suro foo||: string start
    print|"hello world"|
end

(var ret (call foo))
print|ret (typeof ret)| #output: 0 string
#int 0 was casted to a string and returned
```

# User Input
[Table of Contents](#table-of-contents)

Chimera allows users to enter data while the program is running

```text
>>> (var data (get_input "enter data: "))
enter data: 50
>>> print|data}
50
```
get_input will return 4 different possible types (int, float, double, or string)

it will only return one of the first 3 if you enter text that represents a number. By default for such data it will return a double, but you can get get_input to return an int or float based on if you add an 'i' or 'f' to the very end of the input

```text
>>> (var ret (get_input "enter data: "))
enter data: 50i
>>> print|ret (typeof ret)|
50 int
>>> (var ret2 (get_input "enter data: "))
enter data: 50.345f
>>> print|ret2 (typeof ret2)|
50.345 float
>>> #note you can include or omit the d because by default get_input will return a double if the input is a valid number
>>> (var ret3 (get_input "enter data: "))
enter data: 50
>>> print|ret3 (typeof ret3)|
50 double
>>> print|(typeof (get_input "enter data: "))|
enter input: 50.tdfaai
string
```

## Keywords

[Table of Contents](#table-of-contents)

below is a list of keywords in the langauge

### **data types**

[Data Types](#data-types)

1. int
1. float
1. double
1. bool
1. char
1. string
1. list
1. map
1. unknown (used to make a variable hold any type of data)
1. ref (used to assign another name to an existing variable)

### **list**

1. [var name].addTo

### **map**

1. [var name].put

### **container operators**

[Containers](#container-operations)

1. [var name].set
1. [var name].size
1. (get [var name] index)

### **compare keywords**

[Compare Operators](#compare-operators)

1. < or less
1. \> or greater
1. <= less-equal
1. \>= or greater-equal
1. == or equal
1. != or not-equal

### **boolean operations**

[Boolean Operators](#bool-operators)

1. and or &&
1. or or ^^
1. not or !

### **math operators**

[Math Operators](#math-operations)

1. \+ or add
1. \- or sub
1. \* or mul
1. \\ or div
1. \^ or pow

### **scope**

1. start
1. end

### **if statements**

[If Statements](#if-statements)

1. if
1. else-if
1. else

### **for loop**

[Loops](#loops)

1. repeat
1. with

### **while loop**

[Loops](#loops)

1. while

### **function**

[Functions](#functions)

1. suro
1. furo
1. func
1. (call [func name] [params])

### **bool vals**

1. true
1. false

### **misc**

1. cast
