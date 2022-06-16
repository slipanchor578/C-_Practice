#include <stdio.h>

int Sum(int[], size_t);

int main(void)
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};

    // 普通に実行
    printf("%d\n", Sum(array, 10));

    // Sum関数を受け取れる関数ポインタを作成
    int (*sum_Ptr)(int[], size_t) = Sum;

    // 関数ポインタver
    printf("%d\n", (*sum_Ptr)(array, 10));

    // typedef を使うと見やすくなる
    typedef int (*sum_Ptr_def)(int[], size_t);

    sum_Ptr_def sum_Ptr2 = Sum;

    // typedefした関数ポインタver
    printf("%d\n", sum_Ptr2(array, 10));

    return 0;    
}

int Sum(int array[], size_t size)
{
    int result = 0;

    size_t count = 0;

    while(count < size)
    {
        result += *(array + count);
        count++;
    }

    return result;
}