print|"starting"|
#Expected output: [10, 20, 30, 40]
(= x:list [])
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
print|(add "x[3] * 4 =" (cast (mul (get x 3) 4) string))|

#Expected output: 10 60 30
(= ten:string (add (cast (get x 0) string) " "))
(= sixty:string (add (cast (get x 2) string) " "))
(= thirty:string (cast (get x 2) string))
print|(add ten sixty thirty)|

(= y:list [])
(= b:list [])

y.addTo|"hello"|
print|y|

(= z:list y)
print|z|

(= b y)
print|b|
