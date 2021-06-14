class employee
{
	public:
		char name[20];
        float basic;
	    float da;
	    float it;
		void getdetails();
		void printdetails();
		virtual void printsalary()=0;
};
class parttimeemployee:public employee
{
	public:
		void printsalary();
};
class fulltimeemployee:public employee
{
	public:
		void printsalary();
};
class dailywages:public employee
{
	public:
		void printsalary();
};
