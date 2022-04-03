suro fizzbuzz|i: int|: int start
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

(var run_func:bool true)

repeat 16 with i start
    if run_func start
        (call fizzbuzz i)
    else start
        if (equal i 0) start
            print|"not calling func"|
        end
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
end