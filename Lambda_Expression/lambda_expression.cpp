#include <iostream>
#include <vector>

template<typename TFunc>
int aggregate(const std::vector<int>& input, TFunc func)
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

    /*
    // もはや関数オブジェクトを渡す前に作っておくことすら必要ない
    struct
    {
        int operator()(int accum, int elem)
        {
            return accum + elem;
        }
    } sum;*/

    // 直接ラムダ式で処理を書く   
    std::cout << aggregate(vec, [](int accum, int elem)
    {
        return accum + elem;
    }) << std::endl;

    // 見にくいのが嫌なら、普通に書いて保持できる
    auto sum = [](int accum, int elem) -> int
    {
        return accum + elem;
    };

    std::cout << aggregate(vec, sum) << std::endl; // 55

    return 0;
}

/*
    [](int accum, int elem)
    {
        return accum + elem;
    }

    ラムダ式は関数オブジェクトの糖衣構文になっている
*/