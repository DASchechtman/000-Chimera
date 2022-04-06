(var x :int (pow 10 9))

suro IfTest|x: int| start
  if (less x (pow 10 6)) start
    print|x '<' (pow 10 6)|
  else-if (less x (pow 10 9)) start
    print|x '<' (pow 10 9)|
  else start
    if (equal x (pow 10 9)) start
        print|"EQUAL!!!"|
    else start
        print|"x is" x|
    end
  end
end

(call IfTest x)
(= x (pow 10 5))
(call IfTest x)
(= x (pow 10 7))
(call IfTest x)
(= x (pow 10 10))
(call IfTest x)