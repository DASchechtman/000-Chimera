print|"starting"|
repeat 20 with iters start
$
    fizz: int = 3
    buzz: int = 5
    fizz_cpy: float = iters
    buzz_cpy: float = iters

    while (greater-equal fizz_cpy fizz) start
        fizz_cpy = (sub fizz_cpy fizz)
    end

    while (greater-equal buzz_cpy buzz) start
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
        output = (cast iters string)
    end

    print|output|
    $
    print|iters|
end

print|"program done"|