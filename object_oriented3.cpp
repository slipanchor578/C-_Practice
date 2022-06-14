#include <iostream>
#include <string>

class Person
{
    private:
        std::string name;
        double height;
        double weight;

    public:
        Person(const std::string& name, const double& height, const double& weight) : name(name), height(height), weight(weight){}

        const std::string& get_name() const noexcept(true) {return name;}

        double calculate_bmi() const
        {
            double bmi{(weight / (height * height)) * 10000};

            return bmi;
        }

        void check_bmi() const
        {
            double bmi{calculate_bmi()};

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
};

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

    Person person{name, height, weight};

    std::cout << person.get_name() << "さんのBMIは" << person.calculate_bmi() << "です" << std::endl;

    person.check_bmi();

    return 0;
}

/*
    C++のクラスを使って更にオブジェクト指向を目指したver
    各メンバ変数をprivateで管理し、コンストラクタ呼び出し時にのみ値をセットさせることで
    あとからデータを変更できないようにしている。これで管理しやすくなる

    get_name関数はそのままだとnameの参照を返すので
    person.get_name() = "XXX";
    のように改変できてしまう。nameメンバ自体はprivateにしているので外部からのアクセスはできないが
    メンバー関数からはアクセスできてしまう。なので読み取り専用にするために戻り値にconstをつける
    こうなるとreadonlyなnameを返すだけなので、nameは変更されないことが保証されるため
    constを付けてconstメンバ関数にすれば良い。例外も出さないのでnoexceptを付ける

    calculate_bmi関数もcheck_bmi関数もメンバの読み取りだけで改変はしないためconstメンバ関数にできる

    できるだけコードの利用者がデータを後から改変できないイミュータブルな状態を目指してコードを書いてあげると
    管理が楽になるし、問題が起きた時の損失の範囲を制限することができる。コンパイルの最適化にも繋がる

*/