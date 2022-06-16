#include <iostream>
#include <vector>

// 受け取った引数を足して返していくだけの関数
constexpr int inner(const int accum, int elem) noexcept(true)
{
    return accum + elem;
}

// inner関数を受け取れるようエイリアスを付けてあげる
using inner_f = int (*)(const int, const int);

// 型ができたので関数を引数として受け取れるようになった
int aggregate(const std::vector<int>& input, inner_f func)
{
    int result{0};

    for(const auto& e: input)
    {
        result = func(result, e);
    }

    return result;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    std::cout << aggregate(vec, inner) << std::endl; // 55

    return 0;
}