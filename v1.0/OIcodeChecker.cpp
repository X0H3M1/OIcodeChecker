#include <bits/stdc++.h>
#include <iostream>
#include <io.h>
using namespace std;

char *main1 = "int main(){", *main2 = "int main()\x00", *main3 = "signed main(){", *main4 = "signed main()\x00";
string X0H3M6 = "Developed by X0H3M6";

inline int mo(int a, int b){
    return a - a / b * b;
}

void __do_global_etors(){
    short int significance[] = {66, 72, 69, 67, 95, 71, 20, 64, 65, 123, 71, 76, 97, 71, 79,
    65, 86, 123, 21, 87, 123, 87, 107, 123, 71, 75, 74, 82, 23, 74, 21, 65, 74, 19, 89};
    string hint = "No hints, but a hint here.";
}

int strcheck(char *a, char *b, int len){
    int flag = 1;
    for (int i = 0; i < len; i++){
        if (a[i] != b[i]){ flag = 0; break; }
    }
    return flag;
}

void clearcache(){
    if (access("cache", 0) == 0){ system("rmdir /s /q cache"); }
}
void cleartxt(){
    if (access("test.in", 0) == 0){ system("del test.in"); }
    if (access("std.out", 0) == 0){ system("del std.out"); }
    if (access("user.out", 0) == 0){ system("del user.out"); }
}

void createfile(string user, string std, string rand){
    ofstream target_File;
    ifstream user_Input;

    user_Input.open(user.c_str(), ios::in);
    target_File.open("cache/user.cpp", ios::out);
    bool flag = 0;
    if (!user_Input.is_open()){
        cerr << "Unable to open the file to be checked, please check the file path or run the program as administrator\n";
        flag = 1;
    }
    if (!target_File.is_open()){
        cerr << "Unable to open the file to be writed, please try again run the program as administrator\n";
        flag = 1;
    }
    if (flag){
        clearcache();
        system("pause");
        exit(-1);
    }
    char cache[1000];
    user_Input.seekg(0);
    target_File.seekp(0);
    while(!user_Input.eof()){
        memset(cache, 0, 50);
        user_Input.getline(cache, 1000);
        target_File << cache << endl;
        // cout << cache << endl;
        if (strcheck(cache, main1, 11) || strcheck(cache, main3, 14)){
            target_File << "    freopen(\"test.in\", \"r\", stdin);\n";
            target_File << "    freopen(\"user.out\", \"w\", stdout);\n";
        }
        if (strcheck(cache, main2, 11) || strcheck(cache, main4, 14)){
            user_Input.getline(cache, 1000);
            target_File << cache << endl;
            target_File << "    freopen(\"test.in\", \"r\", stdin);\n";
            target_File << "    freopen(\"user.out\", \"w\", stdout);\n";
        }
    }
    user_Input.close();
    target_File.close();
    
    user_Input.open(std.c_str(), ios::in);
    target_File.open("cache/std.cpp", ios::out);
    flag = 0;
    if (!user_Input.is_open()){
        cerr << "Unable to open the std file, please check the file path or run the program as administrator\n";
        flag = 1;
    }
    if (!target_File.is_open()){
        cerr << "Unable to open the file to be writed, please try again or run the program as administrator\n";
        flag = 1;
    }
    if (flag){
        clearcache();
        system("pause");
        exit(-1);
    }
    user_Input.seekg(0);
    target_File.seekp(0);
    while(!user_Input.eof()){
        memset(cache, 0, 50);
        user_Input.getline(cache, 2000);
        target_File << cache << endl;
        if (strcheck(cache, main1, 11) || strcheck(cache, main3, 14)){
            target_File << "    freopen(\"test.in\", \"r\", stdin);\n";
            target_File << "    freopen(\"std.out\", \"w\", stdout);\n";
        }
        if (strcheck(cache, main2, 11) || strcheck(cache, main4, 14)){
            user_Input.getline(cache, 1000);
            target_File << cache << endl;
            target_File << "    freopen(\"test.in\", \"r\", stdin);\n";
            target_File << "    freopen(\"std.out\", \"w\", stdout);\n";
        }
    }
    user_Input.close();
    target_File.close();

    user_Input.open(rand.c_str(), ios::in);
    target_File.open("cache/rand.cpp", ios::out);
    flag = 0;
    if (!user_Input.is_open()){
        cerr << "Unable to open the randnumber file, please check the file path or run the program as administrator\n";
        flag = 1;
    }
    if (!target_File.is_open()){
        cerr << "Unable to open the file to be writed, please try again or run the program as administrator\n";
        flag = 1;
    }
    if (flag){
        clearcache();
        system("pause");
        exit(-1);
    }
    user_Input.seekg(0);
    target_File.seekp(0);
    while(!user_Input.eof()){
        memset(cache, 0, 50);
        user_Input.getline(cache, 1000);
        target_File << cache << endl;
        if (strcheck(cache, main1, 11) || strcheck(cache, main3, 14)){
            target_File << "    freopen(\"test.in\", \"w\", stdout);\n";
        }
        if (strcheck(cache, main2, 11) || strcheck(cache, main4, 14)){
            user_Input.getline(cache, 1000);
            target_File << cache << endl;
            target_File << "    freopen(\"test.in\", \"w\", stdout);\n";
        }
    }
    user_Input.close();
    target_File.close();
}

void compilefile(){
    system("g++ -w -std=c++14 -O2 cache/user.cpp -o cache/user.exe 2> nul");
    system("g++ -w -std=c++14 -O2 cache/std.cpp -o cache/std.exe 2> nul");
    system("g++ -w -std=c++14 -O2 cache/rand.cpp -o cache/rand.exe 2> nul");
    bool flag = 0;
    if (access("cache/user.exe", 0) != 0){
        cerr << "Unable to create the user file, please check if there is a compilation error\n"; 
        flag = 1;
    }
    if (access("cache/std.exe", 0) != 0){
        cerr << "Unable to create the std file, please check if there is a compilation error\n"; 
        flag = 1;
    }
    if (access("cache/rand.exe", 0) != 0){
        cerr << "Unable to create the rand file, please check if there is a compilation error\n"; 
        flag = 1;
    }
    if (flag){ system("pause"); clearcache(); exit(-1); }
}

void find_Problem(){
    cout << "The data that caused the program to error are in the runtime directory\n";
    clearcache();
    system("pause");
    exit(0);
}

int main()
{
    struct timeb t;
    ftime(&t);
    srand(t.time * 1000 + t.millitm);

    clearcache(); cleartxt();
    system("md cache");

    string user, std, rand;
    cout << "OIcodeChecker v1.0" << endl;
    cout << "Drag and drop the program to be checked (.cpp format) (No spaces or special characters in the program path)\n";
    cin >> user;
    cout << "Drag and drop the std program (.cpp format) (No spaces or special characters in the program path)\n";
    cin >> std;
    cout << "Drag and drop the random data generator (.cpp format) (No spaces or special characters in the program path)\n";
    cin >> rand;

    cout << "Files are creating\n";
    createfile(user, std, rand);
    cout << "Compiling\n";
    compilefile();
    cout << "Successfully compiled files, Checking is starting" << endl;
    // _sleep(1000);
    // system("cls");
    int cnt = 0;
    while(1){
        ++cnt;
        int randret = system("cache\\rand.exe");
        int stdret = system("cache\\std.exe");
        int userret = system("cache\\user.exe");
        int flag = 0;
        if (randret != 0){
            cout << "random data generator runtime error!\n"; flag = 1;
        }
        if (stdret != 0){
            cout << "Std runtime error!\n"; flag = 1;
        }
        if (userret != 0){
            cout << "User's program runtime error!\n"; flag = 1;
        }
        if (flag == 0) if (system("fc std.out user.out > nul")){
            cout << "Wrong Answer on the " << cnt;
            if (cnt % 10 == 1){ cout << "st "; } if (cnt % 10 == 2){ cout << "nd "; } if (cnt % 10 == 3){ cout << "rd "; }
            cout << "set of data" << endl;
            flag = 1;
        }
        if (flag){ find_Problem(); }
        if (mo(cnt, 20) == 0){ cout << cnt << " sets of datas has been checked" << endl; }
    }
}