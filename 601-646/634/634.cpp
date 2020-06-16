//原来的函数


int factorial(int val)
{
    if(val>1)
        return factorial(val-1)*val;
    return 1;
}
//改写之后
int factorial2(int val)
{
    if(val!=1)
        return factorial(val-1)*val;
    return 1;
}

你传个负数咋办啊？对不对
