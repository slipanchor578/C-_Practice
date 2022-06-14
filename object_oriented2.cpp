#include <iostream>
#include <string>

using Person = struct
{
    std::string name;
    double height;
    double weight;
};

double calculate_bmi(Person* person)
{
    double bmi{(person->weight / (person->height * person->height)) * 10000};

    return bmi;
}

void check_bmi(Person* person)
{
    double bmi{calculate_bmi(person)};

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
}

int main()
{
    Person person;

    std::cout << "あなたの名前を入力してください" << std::endl;

    std::cin >> person.name;

    std::cout << "あなたの身長を入力してください (cm)" << std::endl;

    std::cin >> person.height;

    std::cout << "あなたの体重を入力してください (kg)" << std::endl;

    std::cin >> person.weight;

    std::cout << person.name << "さんのBMIは" << calculate_bmi(&person) << "です" << std::endl;

    check_bmi(&person);

    return 0;
}

/*
    各データを構造体で一元的に管理し、値の操作は関数を通して実行するようにしたver
    「name」「height」「weight」と変数が散らばっていた時より、オブジェクトでまとめている方がコードが見やすく
    管理のスコープが狭くなり考えることが少なくて済む
    bmiの計算式を毎回書いていると間違える可能性があるので、関数でまとめてあげることでミスを無くすことができる
    使う側も、何も考えず関数を使えばbmiを取得できる方が利便性がある
*/