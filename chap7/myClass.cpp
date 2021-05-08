class ConstRef{
    public:
    ConstRef(int ii);

    private:
    int i;
    const int ci;
    int &ri;
};

/*
先使用默认初始化，然后再拷贝赋值，显然是有问题的。
*/
//ConstRef::ConstRef(int ii)
//{
//    i = ii;
//    ci = ii;
//    ri = ii;
//}

// 直接初始化，推荐
ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(ii){}

int main()
{
}
