#include <iostream>
#include <vector>

// ローカル関数が作れるようになり、計算のためにしか使わない関数をグローバル空間に作らなくて済むようになった
int aggregate(const std::vector<int>& input)
{
    int result{0};

    // 構造体に関数を持たせる
    struct
    {
        constexpr int inner(int accum, int elem) noexcept
        {
            return accum + elem;
        }
    } func_obj;

    // 実装を内部で隠蔽できる
    for(const auto& e: input)
    {
        result = func_obj.inner(result, e);
    }

    return result;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    // コンテナしか渡さなくて済むようになりすっきり
    std::cout << aggregate(vec) << std::endl; // 55

    return 0;
}