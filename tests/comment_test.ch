

print| "before comment" |
 
$
    int x = 0;
    for(size_t i = 0; i < x; i++) {
        cout << "hello world\n";
    } $ hello: string = "hello world"

print|"after comment" hello|

$
    # nested comment
    print|"shouldn't run"|
$
