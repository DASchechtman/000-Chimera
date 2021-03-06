# testing to make sure I can initialize data right
print|"setting var test"|
#int_val: int = 9
#flo_val: float = 8.342
#dou_val: double = 8.3339232
#str_val: string = "hello world"
#char_val: char = 'c'
#bol_val: bool = true

(= int_val:int 9)
(= flo_val:float 8.342)
(= dou_val:double 8.3339232)
(= str_val:string "hello world")
(= char_val:char 'c')
(= bol_val:bool true)

print|
    "passed. \n"
    "int val =" int_val '\n'
    "float val =" flo_val '\n'
    "double val =" dou_val '\n'
    "str val =" str_val '\n'
    "char val =" char_val '\n'
    "bool val =" bol_val '\n'
                                                              |

# testing to make sure I can reassign data/testing some opers
print|"reassign test"|

$
int_val = (* int_val 10)
flo_val = (^ flo_val 2)
dou_val = (+ dou_val 10)

str_val = (add
    (cast 'h' string)
    (cast 'e' string)
    (cast 'l' string)
    (cast 'l' string)
    (cast 'o' string)
    (cast ' ' string)
    (cast 'm' string)
    (cast 'a' string)
    (cast 'r' string)
    (cast 's' string)
     )
$

(= int_val (mul int_val 10))
(= flo_val (pow flo_val 2))
(= dou_val (add dou_val 10))
(= str_val (add
        (cast 'h' string)
        (cast 'e' string)
        (cast 'l' string)
        (cast 'l' string)
        (cast 'o' string)
        (cast ' ' string)
        (cast 'm' string)
        (cast 'a' string)
        (cast 'r' string)
        (cast 's' string)
))

$
str_val = (+ (cast 
                    'h' 
                    'e' 
                    'l' 
                    'l' 
                    'o'                                         
                    ' ' 
                    'm' 
                    'a' 
                    'r' 
                    's' 
            string
            ))
$

#char_val = (cast 97 char)
#bol_val = false
(= char_val (cast 97 char))
(= bol_val false)

print|
    "passed. " '\n'
    "int val =" int_val '\n'
    "float val =" flo_val '\n'
    "double val =" dou_val '\n' 
    "str val =" str_val '\n'
    "char val =" char_val '\n'
    "bool val =" bol_val '\n'
|

print| "should throw a parser error\n" |
#error: int = "hello"
(= error:int "hello")

print| "shouldn't reach this point cuz of the above error\n" |
#error2 = 99
(= error2 99)