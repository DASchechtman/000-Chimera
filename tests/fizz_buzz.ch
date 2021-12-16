repeat 100 with i start
    fizz: int = 3
    buzz: int = 5
    fizz_cpy: float = i
    buzz_cpy: float = i

    while (greater-equal fizz_cpy fizz) with j start
        fizz_cpy = (sub fizz_cpy fizz)
    end

    while (greater-equal buzz_cpy buzz) with j start
        buzz_cpy = (sub buzz_cpy buzz)
    end

    output: string = ""

    if (equal fizz_cpy 0) start
        output = (add output "fizz")
        if (equal buzz_cpy 0) start
            output = (add output "buzz")
        end
    else-if (equal buzz_cpy 0) start
        if (equal fizz_cpy 0) start
            output = (add output "fizzbuzz")
        else start
            output = (add output "buzz")
        end
    else-if true start
        output = (cast i string)
    end

    print|output|
end

print|"program done"|