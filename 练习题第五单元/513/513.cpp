






(a)
    unsigned aCnt=0,eCnt=0,iouCnt=0;
    char ch =next_text();
switch(ch)
{
    case 'a':aCnt++;
    case 'e':eCnt++;
    default:iouCnt++;
}
修改：

unsigned aCnt=0,eCnt=0,iouCnt=0;
char ch =next_text();
switch(ch)
{
    case 'a':aCnt++;break;
    case 'e':eCnt++;break;
    default:iouCnt++;
}

(b)
    unsigned index=some_value();
     switch(index)
{
    case 1:int ix=get_value();
           ivec[ix]=index;break;
    case 2:ix =ivec.size()-1;
           ivec[ix]=index;

}
修改：    
    unsigned index=some_value();
     switch(index)
{
    case 1:int ix=get_value();
           ivec[ix]=index;break;
    case 2:ix =ivec.size()-1;
           ivec[ix]=index;


}

(c)

    unsigned evenCnt=0,oddCnt=0;
    int digit=get_num()%10
    switch (digit)

