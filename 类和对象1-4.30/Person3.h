#pragma  once
class Person3
{
public:  // public: ����Ϊpublic�ĳ�Ա�������ⶼ�ǿ��Է��ʣ�����ɼ�
	//��Ա����
	int getAge();

	void print();

	void driveCar();
private:  //����Ϊprivate�ĳ�Ա�����ⲻ�ܷ��ʣ����ⲻ�ɼ�

	//��Ա������ ����
	int age;
	char* name;
	char* gender;
protected:  //����Ϊprotected�ĳ�Ա�����ⲻ�ܷ��ʣ����ⲻ�ɼ�
	int number;
};