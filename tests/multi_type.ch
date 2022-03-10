# TEST FOR WHEN MULTI TYPES ARE USED PROPERLY

# STRING OR INT TEST
(= str:string "hello world")
(= i_num:int 21)
(= s_or_i: [string|int] i_num)

print|"string, int test\n"|
print|"should:" i_num "is:" s_or_i|

(= s_or_i str)
print|"should:" str "is:" s_or_i '\n'|

# FLOAT OR STRING TEST
(= flo:float 42f)
(= str2:string "hello test 2")
(= f_or_s: [float|string] flo)

print|"string, float test\n"|
print|"should:" flo "is:" f_or_s|

(= f_or_s str2)
print|"should:" str2 "is:" f_or_s '\n'|

# CHAR AND DOUBLE TEST
(= chr:char 'a')
(= dou:double 99d)
(= c_or_d: [char|double] dou)

print|"string, double test\n"|
print|"should:" dou "is:" c_or_d|

(= c_or_d chr)
print|"should:" chr "is:" c_or_d '\n'|

# CHAR AND STRING AND FLOAT TEST
(= flo2:float 8.42)
(= str3:string "hello test 3")
(= chr2:char 'h')
(= c_or_f_or_s: [char|string|float] flo2)

print|"string, char, float test\n"|
print|"should:" flo2 "is:" c_or_f_or_s|

(= c_or_f_or_s str3)
print|"should:" str3 "is:" c_or_f_or_s|

(= c_or_f_or_s ch2)
print|"should:" chr2 "is:" c_or_f_or_s '\n'|

print|"unknown test"|
#UNKNOWN TEST
(= i:int 9)
(= f:float 10f)
(= d:double 11)
(= c:char 'p')
(= s:string "hello unknown test")
(= b:bool false)
print|"done init"|

(= u:unknown i)
print|"unknown var test\n"|
print|"should:" i "is:" u|

(= u f)
print|"should:" f "is:" u|

(= u d)
print|"should:" d "is:" u|

(= u c)
print|"should:" c "is:" u|

print|"should:" b "is:" u|

(= u s)
print|"should:" s "is:" u '\n'|

#UNKNOWN ASSIGNMENT TESTS
print|"unknown ASSIGNMENT tests"|

(= u (add f 1))
print|"u + 1 =" u|

(= f u)
print|"f is now" f|

(= u 'd')
(= c u)
print|"new val of u:" u "c is set to u:" c|

#SHOULD CRASH
print|"should crash now"|
(= almost_unknown:[int|float|double|bool|char] "hello world")
print|almost_unknown|