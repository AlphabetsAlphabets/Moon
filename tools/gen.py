class Rule:
    def __init__(self, name, terminals):
        self.name = name
        self.terminals = terminals

    def __repr__(self):
        return f"{self.name} -> {' | '.join(self.terminals)}"

    def generate_enum(self):
        enum_name = f"{self.name}Type"
        enum_declaration = f"typedef enum {enum_name}"
        enum_variants = ", ".join(self.terminals)
        enum_final = enum_declaration + " {\n " + enum_variants + "\n} " + f"{enum_name};"

        return enum_final

    def generate_struct(self):
        enum_name = f"{self.name}Type"

        struct_declaration = f"typedef struct {self.name}\n"
        struct_value = "\tchar *value;\n"
        struct_type = f"\t{enum_name} type;\n"

        struct_fields = struct_value + struct_type

        struct_ends = f"{self.name};"
        struct_final = struct_declaration + "{\n " + struct_type + "\n} " + struct_ends

        return struct_final

def read_grammar_file():
    rules = []
    with open("../grammar.md") as f:
        for line in f.readlines():
            line = line.strip()
            rule = line.split(" -> ")
            name = rule[0]
            terminals = rule[1].split(" | ")
            rules.append(Rule(name, terminals))

    return rules

if __name__ == "__main__":
    rules = read_grammar_file()
    for rule in rules:
        print(rule.generate_enum() + "\n" + rule.generate_struct() + "\n")
