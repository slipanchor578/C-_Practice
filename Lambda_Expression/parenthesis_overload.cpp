#include <iostream>
#include <vector>

int aggregate(const std::vector<int>& input)
{
    int result{0};

    // 構造体sumの「()」演算子に対してオーバーロードをしている
    // 引数も取れるし戻り値も返せる。関数オブジェクトと化した
    struct
    {
        int operator()(int accum, int elem)
        {
            return accum + elem;
        }
    } sum;

    for(const auto& e: input)
    {
        // ()演算子のオーバーロードでまるで関数のように動く
        result = sum(result, e);
    }

    return result;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    std::cout << aggregate(vec) << std::endl; // 55

    return 0;
}