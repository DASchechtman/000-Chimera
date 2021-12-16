print|"starting"|
#Expected output: [10, 20, 30, 40]
x: list<int> = []
x.addTo|10|
x.addTo|20|
x.addTo|30|
x.addTo|40|
print|"hello world"|
print|x|

#Expected output: [10, 60, 30, 40]
x.set|1 60|
print|x|

#Expected output: x[3] * 4 = 160
print|(add "x[3] * 4 =" (cast (mul x[3] 4) string))|

#Expected output: 10 60 30
ten: string = (add (cast x[0] string) " ")
sixty: string = (add (cast x[1] string) " ")
thirty: string = (cast x[2] string)
print|(add ten (add sixty thirty))|

#Expected output: [hello]
y: list<string> = []
b: list<string> = []
y.addTo|"hello"|
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
#y.addTo|"world" "and" true|
