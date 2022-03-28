repeat 5 with j start
    repeat 5000000 with i start
        #output: int | string = ""
        (var output: [int|string] "")

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
end