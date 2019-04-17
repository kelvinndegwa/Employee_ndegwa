#include <string>
#include <iostream>

using namespace std;

class CEmployee
{
private:
	char m_name[100];
	char m_id[100];
	//virtual float Pay() { return 0;};  // virtual function
	virtual float Pay() = 0; // pure virtual function
	virtual void getname(){};
	
;
public:
	CEmployee(char name[], char id[])
	{
		strcpy_s(m_name, name);
		strcpy_s(m_id, id);
	}
	CEmployee()
	{
		strcpy_s(m_name, "");
		strcpy_s(m_id, "");
	}
	char* getid() {
		return m_id;
	}
	
	
	void PrintCheck()
	{
		cout << m_name <<" "<<m_id << "  " << Pay() << endl;
	}
	void reportcheck() {
		//cout << m_name << " " << m_id << " " << typeid(*this).name() << endl;
		cout << m_name << " " << m_id << " " ;
		getname();
	}
};




class CFulltimeEmployee : public CEmployee
{
protected:
	static float m_benefitcost;
public:
	CFulltimeEmployee() {

	}

	CFulltimeEmployee(char name[], char id[]) : CEmployee(name, id)
	{
		m_benefitcost = 100;
	}
	
};
float CFulltimeEmployee::m_benefitcost = 100;

class CHourlyFTEmployee : public CFulltimeEmployee
{
private:
	float m_rate;
	float m_hours;
public:
	CHourlyFTEmployee()
	{
	}
	CHourlyFTEmployee(char name[], char id[],  float hours,float rate ) : CFulltimeEmployee(name, id)
	{
		m_rate = rate;
		m_hours = hours;
	}
	
	float Pay()
	{
		return m_rate * m_hours - m_benefitcost;
	}
	void getname() {
		cout <<m_hours<<" "<<m_rate<< "  CHourlyFTEmployee";
	}
	
	void UpdatePayData(float newhours, float newrate) {
		m_hours = newhours;
		m_rate = newrate;
	}
};
class  CSalariedFTEmployee :virtual public CFulltimeEmployee
{
private:
	float m_salary;
public:
	  CSalariedFTEmployee() {

	  }
	  CSalariedFTEmployee(char name[], char id[],float salary) : CFulltimeEmployee(name,id)
	  {
		  m_salary = salary;
	  }
	  float Pay() {
		  return m_salary / 12 - m_benefitcost;
	  }
	  void UpdatePayData(float newsalary) {
		  m_salary = newsalary;
	  }
	  void getname() {
		  cout <<m_salary<<" "<< " CSalariedFTEmployee";
	  }
	  float s() {
		  return m_salary;
	  }
};
class CCommissionedFTEmployee : virtual public CFulltimeEmployee
{
private:
	float  m_sales;
	float m_CommissionPercent;
	
public:
	CCommissionedFTEmployee() {
	}
	CCommissionedFTEmployee(char name[], char id[], float CommissionPercent,float sales): CFulltimeEmployee(name,id)
	{
		m_sales = sales;
		m_CommissionPercent = CommissionPercent;
	}
	float Pay() {
		return m_sales * m_CommissionPercent - m_benefitcost;
	}
	void UpdatePayData(float newCommissionPercent,float newsales) {
		m_CommissionPercent = newCommissionPercent;
		m_sales = newsales;
	}
	void getname() {
		cout <<m_sales<<" "<<m_CommissionPercent<< "  CCommissionedFTEmployee";
	}
	float r() {
		return m_sales;
	}
	float q() {
		return m_CommissionPercent;
	}
	
};
class  CSalariedCommissionedFTEmployee :public CSalariedFTEmployee,public CCommissionedFTEmployee{

public:
	CSalariedCommissionedFTEmployee() {
	}
	CSalariedCommissionedFTEmployee(char name[], char id[], float salary,float CommissionPercent, float sales) :CFulltimeEmployee(name,id), CCommissionedFTEmployee(name, id,CommissionPercent,sales),CSalariedFTEmployee(name,id,salary)
	{		
		
	}
	//int m = CCommissionedFTEmployee::Pay();

	float Pay() {
	return CCommissionedFTEmployee::Pay() + CSalariedFTEmployee::Pay()+m_benefitcost;
		
	}
	void getname() {
		cout <<CSalariedFTEmployee::s()<<"  "<<CCommissionedFTEmployee::q() << "  " <<CCommissionedFTEmployee::r()<< "  CSalariedCommissionedFTEmployee";
	}
	void UpdatePayData(float a,float b,float c) {
		CCommissionedFTEmployee::UpdatePayData(a,b);
		CSalariedFTEmployee::UpdatePayData(c);
	}
	
};
class CParttimeEmployee : public CEmployee
{
protected:
	static float m_benefitcost;
public:
	CParttimeEmployee()
	{

	}
	CParttimeEmployee(char name[], char id[]) : CEmployee(name, id)
	{
		m_benefitcost = 100;
	}
	void UpdatePayData() {

	}
	

};
float CParttimeEmployee::m_benefitcost = 100;

class CHourlyPTEmployee : public CParttimeEmployee {
private:
	float m_rate;
	float m_hours;
public:
	CHourlyPTEmployee() {

	}
	CHourlyPTEmployee(char name[], char id[], float hours, float rate) :CParttimeEmployee(name, id) {

		m_rate = rate;
		m_hours = hours;
	}
	float Pay() {
		return (m_hours * m_rate) ;
	}
	void getname() {
		cout <<m_rate<<" "<<m_hours<< "  CHourlyPTEmployee";
	}
	
	void UpdatePayData(float newhours,float newrate) {
		m_hours = newhours;
		m_rate = newrate;
	}
};