#include <iostream>
#include <string>

int main()
{
    std::string name;

    double height;
    
    double weight;

    std::cout << "あなたの名前を入力してください" << std::endl;

    std::cin >> name;

    std::cout << "あなたの身長を入力してください (cm)" << std::endl;

    std::cin >> height;

    std::cout << "あなたの体重を入力してください (kg)" << std::endl;

    std::cin >> weight;

    double bmi{(weight / (height * height)) * 10000};

    std::cout << name << "さんのBMIは" << bmi << "です。" << std::endl;

    if(bmi < 18.5)
    {
        std::cout << "肥満度は痩せ気味です" << std::endl;
    }
    else if((bmi >= 18.5) && (bmi < 25))
    {
        std::cout << "肥満度は普通です" << std::endl;
    }
    else
    {
        std::cout << "肥満度は太り気味です" << std::endl;
    }

    return 0;
}

/*
    何も考えずに逐次的に書いたver
    コードが見にくいし、複数人のデータを管理する時に「name3」等変数に付けていくと間違える可能性がある
    bmiの計算を毎回書いていると、どこかでヒューマンエラーが発生して間違えた計算が行われてしまうと予測できる
*/