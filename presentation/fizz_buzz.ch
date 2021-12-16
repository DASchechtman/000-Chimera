print|"fizz buzz starting"|

repeat 100 with i start
    fizz: int = 3
    buzz: int = 5
    fizz_cpy: float = i
    buzz_cpy: float = i

    # haven't implemenented the module function yet. also haven't implemenented
    # the ability to create my own functions yet. So the following two loops acts as
    # an  impromptu module function to get the remainder of a number divided by another
    while (greater-equal fizz_cpy fizz) start
        fizz_cpy = (sub fizz_cpy fizz)
    end
    # fizz_cpy % 3
    while (greater-equal buzz_cpy buzz) start
        buzz_cpy = (sub buzz_cpy buzz)
    end

    output: string | int = ""

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
        output = i
    end

    print|output|
end

print|"program done"|
