// This one I'm not too sure yet but I won't implement this until far in the future anyways so this can stay for now.

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
