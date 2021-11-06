hello_int: int | string = 99
cpy: int = hello_int
hello_ref: int-ref = cpy

hello_ref = (+ hello_ref 2)

print| hello_int hello_ref cpy |

hello_int = "string now,"

y: string = (cast hello_ref string)

print| hello_int hello_ref y |