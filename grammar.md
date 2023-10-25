# The grammar for the Moon programming language
## Identifiers
- `let` variable declaration
- `let: x` type declaration
- `struct` 
- `if`
- `while`
- `for`
- `func` function declaration
- `print`
- `return`

## Variable declaration
```moon
let y = 20;
let z = "Hi";
let x = 0.5;

// Declaring a type is optional
let a: Vec[int] = [1, 2, 3];
let b: Dict[str -> int] = {"a": 1, "b": 2};
let c: Tuple[int: 2] = (1, 2);

// Tuples should declare how many of each element it will contain
// However, it is completely optional.
let c2: Tuple[str, int, int] = ("1", 2, 3)
let c3: Tuple[str, int: 2] = ("1", 2, 3)
let a2: Vec[Tuple[int: 2]] = [(1, 2), (3, 4)];

// indexing
a[0]; // 1
c[1]; // 2
```

## Functions
```moon
// Function arguments and return must have a type
func foo(var1: int) -> int {
    return var1;
}

func boo(var1: int) -> None {
    print(var1);
}

print(foo(1));
```

## Flow control
All conditionals must be within a bracket.
```moon
if (x <= 2 && y > 50) {
    print("Yay");
} elif (x == 50) {
    print("Another");
} else {
    print("Something else");
}
```

A `while` and `for` loop aren't that much different.

```moon
while (x >= 5) {
    // do something
}

// Conditionals in brackets include the simplest of things such as:
while (True) {
    // do something
}

for number in [1, 2, 3] {
    print(number);
}
```

## Structs
This one I'm not too sure yet but I won't implement this until far in the future anyways so this can stay for now.
```moon
// Defining a struct
struct Person {
    name: str,
    age: int,
    height: float,
}

@define
Person {
    func say_hello(self) -> str {
        print(f"Hi, I'm {self.name}");
    }
}

let person = Person {
    name: "John",
    age: 20,
    height: 1.8
};
```
