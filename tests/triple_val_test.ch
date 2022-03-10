#nums: list = [1 2 4]
#trips: map = {}

(= nums:list [1 2 4])
(= trips: map {})

repeat nums.size with i start
    trips.put|i (mul (get nums i) 3)|
end

print|"Before:" nums|

repeat nums.size with i start
    nums.set|i (get trips i)|
end

print|"After:" nums|
