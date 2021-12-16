x: int = 1
if (equal x 1) start

    print|"in 1st if"|
    if (equal x 0) start
        print|"in 2nd if"|
    end

    while (less x 101) start
        remainder: int = x
        div_by: int = 2
        
        while (greater-equal remainder div_by) start
            remainder = (sub remainder div_by)
        end

        if (equal remainder 0) start
            print|"even"|
        else start
            print|"odd"|
        end

        x = (add x 1)
    end

    print|"done with 1st loop"|
end

if false start
    print|"won't run"|
else-if false start
    print|"also won't run"|
end