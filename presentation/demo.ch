# this is a comment

$
this
is
a
multiline
comment
$

# can store variables of type int, float, double, char, string, bool

# can also create new scopes
start
    print|"creating variables"|
    i: int = 0
    f: float = 0f
    d: double = 0d
    c: char = 'c'
    s: string = "hello professor"
    b: bool = true

    print| i f d c s b |

    # can make reference types as well
    print|"creating a ref"|
    ir: int<ref> = i
    ir = 99
    print|i ir|

    # rebind ref
    print|"rebinding a ref"|
    x: int = 7
    ir = x<ref>
    x = 8
    print|ir x|
end

# can also create lists and maps
print|"creating list"|
array: list<int> = []

print|"creating map"|
hash: map<int -> string> = {}

repeat 25 with i start
    array.addTo|i|
    hash.put|i (cast i string)|
end

# x: string = 8 Error

# can get items via index from both
repeat array.size|| with i start
    print|"hash item =" hash[array[i]]|
end


test: int | string = 10
print|test|

test = "hello world"
print|test|

test2: int | string | double | bool | char | float = 'c'
test3: unknown = 8d

test4: int | string | bool = true

print|test2 test3 test4|

test4 = 88
print|test4|
