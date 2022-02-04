x: list = [1 2 3 4]
print|x.size|
x.addTo|["hello" "world" ]|
print|x[(sub x.size 1)].size|
print|x[(sub x.size 1)][0]|
print|x|
y: int = x[4]
y: int = x[2]
print|y|
y = (add y 1)
z:int = (add x[0] 1)
print|y x|