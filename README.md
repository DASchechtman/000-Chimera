# Chimera Programming Langauge

Chimera the programming language aims to help developers create and maintain software by allowing them to build the smallest parts of the program in software, and combining them to form the full solution to whatever problem facing the developer. Please note that this language is still in development.

The main way Chimera aims to do this is to allow for as much of the program as possible to be a discrete part that can be built upon to make bigger and bigger parts. from something as simple as assignments "x = 1" to more complex structures and objects, functions, and programming paradigms

<h2 id="toc"> Table of Contents </h2>

1. [Installation](#install)
1. [Hello world](#hw)
1. [Data Types](#dt)
1. [Operations](#opers)
1. [Loops](#loops)
1. [If-Statement](#ifstmt)

<h2 id="install">Installation</h2>

[Table of Contents](#toc)

### Steps for Windows Only
1. Go to Start
1. Search "Command Prompt"
1. right click on the top result and select "Run as Administrator"
1. type ```wsl --install```. If you need more help installing wsl go [here](https://docs.microsoft.com/en-us/windows/wsl/install)
1. Restart your computer
1. Search for "Ubuntu" in the start menu and click the top result
1. Open it, create a user name and passowrd
1. type the folowing below and wait for it to finish
```  
sudo apt install make && sudo apt install g++  
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install flex bison
``` 


### Steps for Mac Only
1. will update later when I can figure out how to install on make, flex, and bison on mac

Now download the project to some place you can easily access it. For the sake of this
guide I will assume it's place in a folder on your desktop.

To download, scroll up till you see the "Code" button, and download this project by
whatever means you perfer.

Then place it in a folder on your desktop, I will refer to the folder as "PL" in this 
guide.

### In the terminal type the following command

for windows (in wsl) ```cd /mnt/c/Users/<your user folder>/Desktop/PL/Chimear-main/```\
for mac ```cd ~/Desktop/PL/Chimera-main/```

Then type ```make && make run``` in the terminal, wait for the program to compile, and move on to the "Hello World" section

<h2 id="hw">Hello World</h2>

[Table of Contents](#toc)

in the running terminal type
```
print|"Hello world"|
```

the output you'll see on the screen should be
```
hello world
```

There is more you can do then just print text onto the screen. For example you can store data in variables, and print those variables onto the screen

```
x: int = 10
print|x|
#Output: 10
```
see [Data Types](#dt) for more information on supported base types

You can also do operations on data and store the results in a variable
```
x: int = (mul 5 2)
print|x|
#Output: 10
```

You can also make union types that can hold multiple types of data
```
x: int | string = (add 1 1)
print|x|
#Output: 2

x = (add "hello " "world")
print|x|
#Output: hello world
```

To quit the program type 
```
exit||
```

<h2 id="dt">Data Types</h2>

[Table of Contents](#toc)

### Base Data types
1. int: holds a whole number (example 1, 77)
1. float: holds a decimal number (example 3.14)
1. double: holds a larger decimal number
1. char: holds a single letter
1. string: holds many letters
1. bool: holds a true or false value
1. list
1. map

a character is a single letter surrounded by single quotes, whereas a string is one or more letters surrounded by double quotes

**Note**: you can cast any base type into any other type other base type (maps and lists can be converted to any of the other types but you can't convert any other types to a list or map at this time). In the case of casting a string to a number, if the string represents a number it will be converted to that represented number. Otherwise a hash of the string will be returned
see [Operations](#opers) to learn how to cast

### Union types
a variable can be composed of one or more of the above base types. For example
```
int_or_float: int | float = 1
# do stuff
int_or_float = 3.12

# or

string_or_bool: string | bool = true
# do stuff
string_or_bool = "hello world"
```

If you want a variable to be composed of all the types, you can use the 'unknown' keyword

```
u: unknown = 0

# float
u = 1.1f

# double
u = 1.2

u = true
u = "hello world"
u = 'c'

```
Note that a variable composed of more then one type are still checked for it's current type
when an operaiton is performed
```
s_or_i: int | string = "hello world"

#ok
print|(add s_or_i " and mars")|

#ok
s_or_i = 0
print|(add s_or_i 2)|

#will crash the program
print|(add s_or_i "hello")|
```
### Reference types
You can make a reference to any variable as well.
A reference is basically giving a variable extra names
```
x: int = 10
y: int<ref> = x

# changes the value in x
y = (add y 1)

print|x y|
#Output: 11 11
```
Note: all the base types have a corrisponding reference type. If you use a reference, it's type has to match the variable it's referenceing (i.e. a string var can't be stored in an int ref)

Note: you cannot store a Union type into a reference of any kind

To reassign a ref
```
x: int = 10
y: int<ref> = x

z: int = 11
y = z<ref>

print|x y|
#Output 10 11
```

### Containers
#### ***List***

chimera supports two types of container type currently. A list and a map. A list can contain one or more peices of data

```
# init list
int_list: list = []
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

```
# Get item and set item example
int_list: list = [1 true 3 "hello" 5]

# Get item from list
print|int_list[0]|
#Output: 1

# list name, index, new val
$ 
note that the below ways is the only built in way of setting a value in a container currently. doing something like "int_list[0] = 77" won't workd

also this is a multiline comment
$

int_list.set|0 77|
print|int_list[0]|
#Output: 77
```

**Note** that operations can fail just like if you tried to access them vai a variable, and do an illegal operation

#### ***Map***
Maps associate one type of data with another. for example a string value can be associated with a int value

```
test_map: map = {}

test_map.put|"hello ten" 10|
test_map.put|"hello 20" 20|

print| test_map["hello ten"] test_map["hello 20"] |
#Output: 10 20
```

Note: much like lists maps can also contain any type of data as either the key or value at any time

```
# init map with values
test_map: map = {
    |"hello" -> "world"|
    |[1 2 3] -> "list"|
    |true -> 'c'|
}

#or

test_map_2: map = { |"hello" -> "world"| |[1 2 3] -> "list"| |true -> 'c'| }
```

#### ***Container Operations***
currently can 
1. add values to a container (to the end in a list, and as a key in a map)
1. get values using an index
1. setting values using the index and a new value




<h2 id="opers">Operations</h2>

[Table of Contents](#toc)

### Math operations
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
```
print|(add 1 3.2 1.2)|
#Output 5, not 5.4 because everything was casted to an int
#This bug will be fixed as time goes on
```

### Compare operators
1. (less exp1 exp2)
1. (greater exp1 exp2)
1. (less-equal exp1 exp2)
1. (greater-equal exp1 exp2)
1. (equal exp1 exp2)
1. (not-equal exp1 exp2)

Note: when comparing values of different types, the result will always be false\
Note: for bool types, every operator but 'equal' and 'not-equal' automatically returns false

### Bool operators
1. (and value value)
1. (or value value)
1. (not value)

### Misc operators
1. (cast exp [type])

<h2 id="loops">Loops</h2>

there are 2 types of loops supported. For loops and while loops

```
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

<h2 id="ifstmt">If Statements</h2>

supports branches in the code via if-statements
```
if <bool expressions> start

else-if <bool expresion> start
    # can have as many if-else statements as you like
else start

end
```

note that the else-if/else parts of the if statement are optional

