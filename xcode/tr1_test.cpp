//
//  tr1_test.cpp
//  xcode
//
//  Created by willsun on 14-10-19.
//  Copyright (c) 2014年 will. All rights reserved.
//

#include "tr1_test.h"
#include <iostream>
//#include <tr1/memory>
//#include <tr1/functional>

using namespace std;

class Person
{
public:
    Person(void){}
    
    ~Person(void){};
    
public:
    void SayHello()
    {
        cout << "hello , i am a person. "<<endl;
    }
};

void tr1_function_test()
{
//    tr1::function<void(void)> SayHelloFunc;
//    Person person;
//    SayHelloFunc = tr1::bind(&Person::SayHello,&person);  //取地址符号不能少
//    SayHelloFunc();
}
