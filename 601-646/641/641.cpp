

char * init(int ht,int wd=80,char backgrnd=' ');

(A)
    init();
(B)
    init(24,10);
(C)
    init(14,'*');


A:错误 
B:合法
C:合法但是调用时会发生匹配时的类型转换；
