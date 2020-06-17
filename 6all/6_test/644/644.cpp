





bool isShorter(const string &s1,const string &s2)
{
    return s1.size(),s2.size();
}
inline bool isShorter(const string &s1,const string &s2)
{
    return s1.size(),s2.size();
}
//内联函数就是普通房函数前面+上inline
//内联函数会根据复杂度 有编译器自己决定是原地展开，还是当成 普通函数
