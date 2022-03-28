(= x:int (pow 10 9))

if (less x (pow 10 6)) start
  print|x '<' (pow 10 6)|
else-if (less x (pow 10 9)) start
  print|x '<' (pow 10 9)|
else start
  print|"x is" x|
end