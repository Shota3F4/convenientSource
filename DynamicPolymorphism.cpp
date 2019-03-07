#include<iostream>
#include<list>

using namespace std;


//規定クラス
class BasicClass{
public:
    BasicClass(int num);
    ~BasicClass() {}
    //仮想関数
    virtual void Print();
    virtual void Move();
    inline int getMyNumber() { return MyNumber; }
	
private:
    int MyNumber;
};

BasicClass::BasicClass(int num)
:MyNumber(num)
{}

//仮想関数もちゃんと定義できる
void BasicClass::Print() {
	cout<<"基底クラスです"<<getMyNumber()<<endl;
}

void BasicClass::Move() {
	cout<<"規定クラスの動きを定義しています"<<endl;
}



//継承クラス(Print(),Move()は規定クラスのものを再定義したような形)
class InheritClass : public BasicClass
{
public:
	InheritClass(int num);
	~InheritClass() {}
	void Print();
	void Move();
};

InheritClass::InheritClass(int num)
	:BasicClass(num)
{}

//ここで再定義
void InheritClass::Print() {
	cout<<"継承クラスです"<<getMyNumber()<<endl;
}

void InheritClass::Move() {
	cout<<"継承クラスの動きを定義しています"<<endl;
}



int main(){
	//basicClass(規定クラス)のポインタ型の双方向リストを生成
	std::list<BasicClass*> classlist; 
	
    //基底クラス、規定クラス、継承クラスの順に挿入
	classlist.push_back(new BasicClass(100));
	classlist.push_back(new BasicClass(150));
	classlist.push_back(new InheritClass(45));

//まあ単純に全部見てる
	for (std::list <BasicClass*>::iterator itr = classlist.begin(); itr != classlist.end(); ++itr) {
		(*itr)->Move();
		(*itr)->Print();

	}
	return 0;
}