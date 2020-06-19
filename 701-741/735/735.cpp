#include<string>
#include<sstream>
using namespace std;

typedef string  Type;
Type InitVal();
class Exercise
{
    public:
        typedef  double Type;
        Type SetVal(Type);
        Type InitVal();
    private:
        int ival_;
};
double Exercise::SetVal(double parm)
{
ival_=parm+InitVal();
return ival_; 
//return (stringstream()<<ival_).str();
}
