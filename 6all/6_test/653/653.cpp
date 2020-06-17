(a)
    int calc(int &,int &)
    int calc(const int &,const int &)
(b)
    int calc(char *,char *)
    int calc(const char *,const char *)
(c)
    int calc (char *,char *)
    int calc (char *const,char *const)
解答

(a)
    第二句加入了底层const
    因此和第一句属于不一样的函数声明，可以重载，不存在二义性
(b)
    第二个也是加入了底层const
    因此和第一句属于不一样的函数声明，可以重载，不存在二义性

(c)
    第二句加入的是顶层const，顶层const的形参会被忽略
    无法区分两个函数，二义性！
