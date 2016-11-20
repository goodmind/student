#include <iostream>
#include <locale.h>

using namespace std;

getMyChances(int sleeped,int worked){
	if(worked == 0){
		if(sleeped>0){
			cout<<"Еблан, тебя ни на одной паре еще не было, пиздуй в вуз"<<endl<<"Ну так что делать?"<<endl;
		}
		else {
			cout<<"Ты первый день в вузе, хули ты ноешь"<<endl<<"Ну так что делатЬ?"<<endl;
		}
	}
	else {
		float percent = float(sleeped)/float(sleeped+worked);
		cout<<"Процент проёба: "<<percent<<endl;
		if(percent>0.5){		
			cout<<"Мнение куратора: Пиздец будет, лучше сходи"<<endl<<endl<<"Ну так что делать?"<<endl<<endl;
		}
		else {
			cout<<"Мнение куратора: Да похуй, пока все ок"<<endl<<endl<<"Ну так что делать?"<<endl<<endl;
		}
	}
}

void whatToDo(int day,int sleeped,int worked);

attestate(int sleeped,int worked){
	float percent = float(sleeped)/float(sleeped+worked);
	if(percent > 0.5){
		cout<<"Тебя отчислили, долбоеб."<<endl<<endl<<"Хотите поступить снова? (1/0)"<<endl<<endl;
		int variant;
		while(variant != 1 && variant != 0){
			cin>>variant;
		}
		if(variant == 1){
			whatToDo(1,0,0);
		}
		else cout<<endl	<<"Ну и пиздуй в армию, ебанутый"<<endl;
		return false;
	}
	else {
		cout<<"Ты прошел аттестацию, красава!"<<endl<<endl;
		return true;
	}
}

void whatToDo(int day,int sleeped,int worked){
	int variant=0;
	cout<<"День "<<day<<". Что делать?"<<endl<<"1. Сходить на пары"<<endl<<"2. Ходить по квартире"<<endl<<"3. Какие у меня шансы?"<<endl<<endl;
	while(variant != 1 && variant != 2){
		cin>>variant;
		if(variant == 3){
			getMyChances(sleeped,worked);
		}
	}
	if(variant == 1){
		worked++;
		cout<<endl<<"Ты сходил на пары"<<endl;
	}
	else {
		sleeped++;
		cout<<endl<<"Ты походил по квартире"<<endl;
	}
	day++;
	cout<<endl;
	if(day%10 == 0){
		if(attestate(sleeped,worked)){
			whatToDo(day,sleeped,worked);
		}
	}
	else whatToDo(day,sleeped,worked);
}

main(){
  setlocale(LC_ALL, "Russian");
	whatToDo(1,0,0);
}
