suro fizzbuzz|i: int|: int start
    
end

repeat 16 with i start
    (var output:[string | int] "")

    if (equal (mod i 3) 0) start
        (= output (add output "fizz"))
    end

    if (equal (mod i 5) 0) start
        (= output (add output "buzz"))
    end

    if (equal output "") start
        (= output i)
    end

    print|output|
end