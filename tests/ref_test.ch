# TEST ALL TYPES OF REF
(= i1:int 1)
(= f1:float 2)
(= d1:double 3)
(= c1:char 'g')
(= b1:bool true)
(= s1:string "hello world")

(= ir1:{int ref} i1)
(= fr1:{float ref} f1)
(= dr1:{double ref} d1)
(= cr1:{char ref} c1)
(= br1:{bool ref} b1)
(= sr1:{string ref} s1)

print|"testing refs\n"|

(= ir1 (add ir1 2))
print|"int:" i1 "int ref:" ir1|

(= fr1 (add fr1 3))
print|"float:" f1 "float ref:" fr1|

(= dr1 (add dr1 5))
print|"double:" d1 "double ref:" dr1|

(= cr1 (add cr1 4))
print|"char:" c1 "char ref:" cr1|

(= br1 false)
print|"bool:" b1 "bool ref:" br1|

(= sr1 (add sr1 " and mars"))
print|"string:" s1 "<----> string ref:" sr1|

(= s2:string "hello moon")
(= sr1 {ref s2})
print|sr1|

(= sr1 "hello sun")
print|sr1 s2 s1|

print|"should crash"|
(= new_data:int 99)
(= sr1 {ref new_data})