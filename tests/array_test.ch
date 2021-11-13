
#Expected output: [10, 20, 30, 40]
x: list<int> = []
(put x 10 20 30 40)
print|x|

#Expected output: [10, 60, 30, 40]
(set x 1 60)
print|x|

#Expected output: x[3] * 4 = 160
print|"x[3] * 4 =" (mul x[3] 4)|

#Expected output: 10 60 30
print|x[0] x[1] x[2]|

#Expected output: [hello]
y: list<string> = []
b: list<string> = []
(put y "hello" "sun")
print|y|

z: list<string> = y
print|z|

b = y
print|b|



#Expected output: should crash
#(put y "world" "and" 'c')
#(put y "world" "and" 1)
#(put y "world" "and" 1f)
#(put y "world" "and" 1d)
#(put y "world" "and" "mars")
(put y "world" "and" true)