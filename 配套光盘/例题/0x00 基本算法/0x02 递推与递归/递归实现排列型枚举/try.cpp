#include <vector>
#include <iostream>
void calc(std::vector<char>& choosen, std::vector<int>& cur) {
    if (cur.size() == choosen.size()) {
        for (int c : cur) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < choosen.size(); ++i) {
        if (choosen[i] == 0) {
            choosen[i] = 1;
            cur.push_back(i + 1);
            calc(choosen, cur);
            choosen[i] = 0;
            cur.pop_back();
        }
    }

}
#define ENUM_VAL(Name) # Name
int main() {
    #define EnumMember(Name) Name,
#define EnumString(Name) # Name,
#define EnumDef(EnumName) \
    enum EnumName { EnumName(EnumMember) }; \
    const char *EnumName ## _names[] = { EnumName(EnumString) };


// ... Sample usage:

#define Foo(X) X(First) X(Second) X(Third)
EnumDef(Foo);

Foo my_foo = Second;
printf("my_foo is %s.\n", Foo_names[(int)my_foo]);
    int n;
    std::cin >> n;
    std::vector<char> choosen(n, 0);
    std::vector<int> cur;
    calc(choosen, cur);
}
