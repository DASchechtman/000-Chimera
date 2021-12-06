x: int = 10

start
    y: int = 11
    print|"inside scope" x y|
    x = 12
end

print|"outside scope" x|