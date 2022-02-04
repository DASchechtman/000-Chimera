nums: list = [1 2 4]
trips: map = {}

repeat nums.size with i start
    trips.put|i (mul nums[i] 3)|
end

print|"Before:" nums|

repeat nums.size with i start
    nums.set|i trips[i]|
end

print|"After:" nums|
