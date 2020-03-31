#include <iostream>
#include <fstream>
using namespace std;
int main(int ac, char *av[]) {
   char *name,*name1;
   if (ac > 1) {
      name = av[1];
      name1 = av[2];
      }
   else {
       cout<<"Не заданы имена файлов\n";
        return 1;
   }
   int secmin,secall,min,hour;
   int sec1,min1,hour1;
   int minusec,itog;
   ifstream f(name);
   f>>hour1;
  // cout<<hour1<<'\n';
   f.seekg(3,ios::beg);
   f>>min1;
  // cout<<min1<<'\n';
   f.seekg(6,ios::beg);
   f>>sec1;
 //  cout<<sec1<<'\n';
   hour=hour1*60*60;
   min=min1*60;                       //Подсчет времени в секундах!!!
   secall=sec1+min+hour;
   cout<<secall<<'\n';

   cout<<"ВВедите колличество вычитаемых секунд"<<'\n';                   //РАБОТА СО ВРЕМЕНЕМ!!!
   cin>>minusec;
   itog=secall-minusec;
   if(secall < minusec){
       cout<<"Вы ввели число больше имеющегося"<<'\n';
    return 1;
   }
   cout<<itog<<'\n';
   if(itog / 60 >= 1){
       min1=itog / 60;
     //  secmin=itog%60;
       sec1=itog-(min1 * 60);
   } else {
     min1=0; 
     }
   if(min / 60 >=1){
       hour1=min1 / 60;
       min1=min1-(hour1 * 60);
   } else{
     hour1=0;
   }
    cout<<hour1<<"."<<min1<<"."<<sec1<<'\n';


        ofstream f1(name1);
        f1<<hour1<<"."<<min1<<"."<<sec1;
}

