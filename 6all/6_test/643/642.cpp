(a)
    inline bool eq(const BigInt &,const BigIne &){/**/}
(b)void putValues(int *arr, int size);


解答：
    （b）在头文件里，因为头文件里面只能放声明
    （a）内联函数的必须放在头文件里，要带上函数实现
