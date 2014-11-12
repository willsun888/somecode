//
//  boost_test.cpp
//  xcode
//
//  Created by willsun on 14-10-19.
//  Copyright (c) 2014年 will. All rights reserved.
//

#include <vector>

#include "boost_test.h"
#include "boost/algorithm/string.hpp"

using namespace std;

void boost_string_test()
{
    string str = "aa,bb,cc";
    vector<string> vec;
    boost::split(vec, str, boost::is_any_of(","));
    for(size_t i = 0; i < vec.size(); i++)
    {
        cout<<"<"<<vec[i]<<">"<<endl;
    }
}

int main()
{
    boost_string_test();
}
