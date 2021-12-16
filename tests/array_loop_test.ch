x: int = 0
arr: list<int> = []

repeat 100 with i start
    arr.addTo|i|
end

repeat arr.size|| with i start
    print|arr[i]|
end
