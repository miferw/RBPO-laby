
#include "ReadPersonAge.h"
#include "ReadPersonName.h"
#include "ReadPersonHeight.h"
#include "ReadPersonWeight.h"
#include "ReadPersonSalary.h"
#include "ReadPersonData1.h"
#include "ReadPersonData2.h"
#include "WritePersonData.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
    unsigned short age;
    //extern - âíåøíèå ïåðåìåííûå äîñòóïíû âåçäå, ãäå îïèñàíû, à íå òîëüêî òàì, ãäå îïðåäåëåíû
    extern string name;
    extern unsigned short height, weight;
    extern double salary;
   
    ReadPersonData(name, age, height, weight, salary);
    WritePersonData(name, age, height, weight, salary);

    return 0;
}
