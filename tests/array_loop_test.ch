x: int = 0
arr: list<int> = []

while (less x 20) start
    arr.addTo|(add x 2)|
    x = (add x 1)
end

x = 0

while (less x arr.size||) start
    if (less arr[x] 10) start
        print|"less then 10"|
    end
    print|arr[x]|
    x = (add x 1)
end