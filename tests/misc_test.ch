(= x:list [1 2 3 4 5])
print|x|

x.addTo|["hello" "world"]|

(= y:int (get x 3))
(= y (get x 2))
print|y|

(= y (add y 1))
(= z:int (add (get x 0) 1))
print|y x z|
