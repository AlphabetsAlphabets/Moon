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
