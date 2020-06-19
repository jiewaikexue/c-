//struct X
//{
//    X (int i, int j):base(i),rem(base%j){}
//    int rem,base;
//};
struct X
{
    X (int i, int j):base(i),rem(base%j){}
    int base,rem;
};
//变量的初始化顺序和 列表初始化的顺序无关，之和声明顺序有关。
