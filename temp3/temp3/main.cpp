//
//  main.cpp
//  temp3
//
//  Created by HakuBill on 2020/10/12.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int in[15];
    int a[105];
    memset(a,0,sizeof(a));
    for(int i=1;i<=10;i++)
        cin>>in[i];
    for(int i=1;i<=10;i++)
        a[in[i]]++;
    for(int i=1;i<=100;i++)
        if(a[i])
            cout<<i<<endl;
    return 0;
}
