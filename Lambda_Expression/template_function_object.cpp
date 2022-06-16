#include <iostream>
#include <vector>

// テンプレートを渡すことでどうにでもできるようにする
template<typename TFunc>
int aggregate(const std::vector<int>& input, TFunc func)
{
    int result{0};

    for(const auto& e: input)
    {
        result = func(result, e); // この時点ではTFunc型のfunc関数なだけで何も分からない
    }

    return result;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    struct
    {
        int operator()(int accum, int elem)
        {
            return accum + elem;
        }
    } sum;

    // 関数オブジェクトを渡すと、宣言時の引数と戻り値を見て良い感じにテンプレートが展開される？
    std::cout << aggregate(vec, sum) << std::endl;

    return 0;
}