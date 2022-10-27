#include <bits/stdc++.h>
#include <windows.h>
#include "nlohmann/json.hpp"
#include <iostream>
#include <io.h>
using json = nlohmann::json;
using namespace std;

char *main1 = "int main(){\x00", *main2 = "int main()\x00", *main3 = "signed main(){\x00", *main4 = "signed main()\x00";
string X0H3M6 = "Developed by X0H3M6";
string default_Json = "{\"last_Runtime\":{}}";

json user_Settings;
ifstream user_File, std_File, rand_File;
int create_File_cnt;

inline int read(int &x){
    char ch; bool flag = 0;
    for (ch = getchar(); !isdigit(ch); ch = getchar()){ if (ch == '-') flag = 1; }
    for (x = 0; isdigit(ch); x *= 10, x += ch - '0', ch = getchar());
    x = flag ? -x : x;
}
inline int mo(int a, int b){
    return a - a / b * b;
}

int strcheck(char *a, char *b, int len){
    int flag = 1;
    for (int i = 0; i < len; i++){
        if (a[i] != b[i]){ flag = 0; break; }
    }
    return flag;
}
int cppcheck(string x){
    int n = x.length();
    if (x[n - 1] == 'p' && x[n - 2] == 'p' && x[n - 3] == 'c' && x[n - 4] == '.'){ return 1; }
    return 0;
}
void check_Quotations(string &x){
    int n = x.length();
    if (x[n - 1] == '\"' && x[0] == '\"') x = x.substr(1, n - 2);
    return;
}

void clearcache(){
    if (access("cache", 0) == 0){ system("rmdir /s /q cache > nul 2> nul"); }
}
void cleartxt(){
    if (access("data.in", 0) == 0){ system("del data.in"); }
    if (access("std.out", 0) == 0){ system("del std.out"); }
    if (access("user.out", 0) == 0){ system("del user.out"); }
}

void createfile(string user, string std, string rand){
    printf("Files are creating\n");
    ofstream target_File;
    ifstream user_Input;

    user_Input.open(user.c_str(), ios::in);
    target_File.open("cache/user.cpp", ios::out);
    bool flag = 0;
    if (!user_Input.is_open()){
        cerr << "Unable to open the file to be checked, please check the file path or run the program as administrator.\n";
        flag = 1;
    }
    if (!target_File.is_open()){
        cerr << "Unable to open the file to be writed, please try again run the program as administrator.\n";
        flag = 1;
    }
    if (flag){
        clearcache();
        system("pause > nul");
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
            target_File << "    freopen(\"data.in\", \"r\", stdin);\n";
            target_File << "    freopen(\"user.out\", \"w\", stdout);\n";
        }
        if (strcheck(cache, main2, 11) || strcheck(cache, main4, 14)){
            user_Input.getline(cache, 1000);
            target_File << cache << endl;
            target_File << "    freopen(\"data.in\", \"r\", stdin);\n";
            target_File << "    freopen(\"user.out\", \"w\", stdout);\n";
        }
    }
    user_Input.close();
    target_File.close();
    
    user_Input.open(std.c_str(), ios::in);
    target_File.open("cache/std.cpp", ios::out);
    flag = 0;
    if (!user_Input.is_open()){
        cerr << "Unable to open the std file, please check the file path or run the program as administrator.\n";
        flag = 1;
    }
    if (!target_File.is_open()){
        cerr << "Unable to open the file to be writed, please try again or run the program as administrator.\n";
        flag = 1;
    }
    if (flag){
        clearcache();
        system("pause > nul");
        exit(-1);
    }
    user_Input.seekg(0);
    target_File.seekp(0);
    while(!user_Input.eof()){
        memset(cache, 0, 50);
        user_Input.getline(cache, 2000);
        target_File << cache << endl;
        if (strcheck(cache, main1, 12) || strcheck(cache, main3, 15)){
            target_File << "    freopen(\"data.in\", \"r\", stdin);\n";
            target_File << "    freopen(\"std.out\", \"w\", stdout);\n";
        }
        if (strcheck(cache, main2, 11) || strcheck(cache, main4, 14)){
            user_Input.getline(cache, 1000);
            target_File << cache << endl;
            target_File << "    freopen(\"data.in\", \"r\", stdin);\n";
            target_File << "    freopen(\"std.out\", \"w\", stdout);\n";
        }
    }
    user_Input.close();
    target_File.close();

    user_Input.open(rand.c_str(), ios::in);
    target_File.open("cache/rand.cpp", ios::out);
    flag = 0;
    if (!user_Input.is_open()){
        cerr << "Unable to open the randnumber file, please check the file path or run the program as administrator.\n";
        flag = 1;
    }
    if (!target_File.is_open()){
        cerr << "Unable to open the file to be writed, please try again or run the program as administrator.\n";
        flag = 1;
    }
    if (flag){
        clearcache();
        system("pause > nul");
        exit(-1);
    }
    user_Input.seekg(0);
    target_File.seekp(0);
    while(!user_Input.eof()){
        memset(cache, 0, 50);
        user_Input.getline(cache, 1000);
        target_File << cache << endl;
        if (strcheck(cache, main1, 11) || strcheck(cache, main3, 14)){
            target_File << "    freopen(\"data.in\", \"w\", stdout);\n";
        }
        if (strcheck(cache, main2, 11) || strcheck(cache, main4, 14)){
            user_Input.getline(cache, 1000);
            target_File << cache << endl;
            target_File << "    freopen(\"data.in\", \"w\", stdout);\n";
        }
    }
    user_Input.close();
    target_File.close();
}

void compilefile(){
    bool flag = 0;
    printf("Compiling....0%%");
    
    system("g++ -w -std=c++14 -O2 cache/user.cpp -o cache/user.exe 2> nul");
    if (access("cache/user.exe", 0) != 0){
        cerr << "Unable to create the user file, please check if there is a compilation error.\n"; 
        flag = 1;
    }
    printf("\b\b%d%%", rand() % 10 + 31);
    
    system("g++ -w -std=c++14 -O2 cache/std.cpp -o cache/std.exe 2> nul");
    if (access("cache/std.exe", 0) != 0){
        cerr << "Unable to create the std file, please check if there is a compilation error.\n"; 
        flag = 1;
    }
    printf("\b\b\b%d%%", rand() % 10 + 65);
    
    system("g++ -w -std=c++14 -O2 cache/rand.cpp -o cache/rand.exe 2> nul");
    if (access("cache/rand.exe", 0) != 0){
        cerr << "Unable to create the rand file, please check if there is a compilation error.\n"; 
        flag = 1;
    }
    printf("\b\b\b100%%\n");

    if (flag){system("pause > nul"); clearcache(); exit(-1); }
    printf("Successfully compiled files, Checking has started, press esc to stop.\n");
}

void find_Problem(){
    cout << "The data that caused the program to error are in the runtime directory.\n";
    clearcache();
    system("pause > nul");
    exit(0);
}

void regular_Exit(int x, int maxt, int mint, int sumt){
    printf("%d sets of datas have been checked\n", x);
    printf("maximum time use: %dms\n", maxt);
    printf("minimum time use: %dms\n", mint);
    printf("average time use: %.2lfms\n", (double)sumt / (double)x);
    printf("Maybe you can try a larger data range.\n");
    clearcache(); cleartxt();
    system("pause > nul");
    exit(0);
}

void Program_Init(){
    system("mode con cols=130 lines=35");
    struct timeb t;
    ftime(&t);
    srand(t.time * 1000 + t.millitm);

    clearcache(); cleartxt();
    system("md cache");
    if (access("cache", 0) != 0){
        printf("Unable to create temporary floder, please try again or run the program as administrator.\n");
        system("pause > nul");
        exit(0);
    }

    // Import user settings, create if they don't exist
    if (access("config.json", 0) != 0){
        ofstream json_File;
        json_File.open("config.json", ios_base::out);
        user_Settings = json::parse(default_Json);
        json_File << setw(4) << user_Settings;
        json_File.close();
    } else {
        ifstream json_File;
        json_File.open("config.json", ios::in);
        json_File.peek();
        if (!json_File.eof()){ json_File >> user_Settings; }
        else{ user_Settings = json::parse(default_Json); }
        json_File.close();
    }
}

bool check_File_Exist(string s){
    if (access(s.c_str(), 0) == 0){ return 1; }
    else { return 0;}
}

bool check_Last_Settings(){
    if (user_Settings.contains("last_Runtime")){
        if (user_Settings["last_Runtime"].contains("user_Last_File") &&
            user_Settings["last_Runtime"].contains("std_Last_File") &&
            user_Settings["last_Runtime"].contains("rand_Last_File")){
                return 1;
        }
    }
    return 0;
}

int main()
{
    Program_Init();

    printf("OIcodeChecker v1.4\n");

    printf("Drag and drop the program to be checked. (.cpp format and no Chinese characters)(Enter \"last\" to use the last checked files)\n");
    
    string user_Input, std_Input, rand_Input;
    
    INPUT_USER:
    getline(cin, user_Input);
    check_Quotations(user_Input);
    if (user_Input == "last"){
        if (check_Last_Settings() ){
            user_Input = user_Settings["last_Runtime"]["user_Last_File"];
            std_Input = user_Settings["last_Runtime"]["std_Last_File"];
            rand_Input = user_Settings["last_Runtime"]["rand_Last_File"];
            if (!check_File_Exist(user_Input) || !check_File_Exist(std_Input) || !check_File_Exist(rand_Input)){
                printf("Last files not found, please drag and drop the program to be checked.\n");
                goto INPUT_USER;
            }
            goto START_CREATING_FILE;
        }
        else{
            printf("Last files not found, please drag and drop the program to be checked.\n");
            goto INPUT_USER;
        }
    }
    user_File.open(user_Input);
    if (!user_File || !cppcheck(user_Input)){
        printf("This is not a valid .cpp file, please try again!\n");
        user_File.close();
        goto INPUT_USER;
    }
    user_Settings["last_Runtime"]["user_Last_File"] = user_Input;

    printf("Drag and drop the std program. (.cpp format and no Chinese characters)\n");
    INPUT_STD:
    getline(cin, std_Input);
    check_Quotations(std_Input);
    std_File.open(std_Input);
    if (!std_File || !cppcheck(std_Input)){
        printf("This is not a valid .cpp file, please try again!\n");
        std_File.close();
        goto INPUT_STD;
    }
    user_Settings["last_Runtime"]["std_Last_File"] = std_Input;

    printf("Drag and drop the random data generator. (.cpp format and no Chinese characters)\n");
    INPUT_RAND:
    getline(cin, rand_Input);
    check_Quotations(rand_Input);
    rand_File.open(rand_Input);
    if (!rand_File || !cppcheck(rand_Input)){
        printf("This is not a valid .cpp file, please try again!\n");
        rand_File.close();
        goto INPUT_RAND;
    }
    user_Settings["last_Runtime"]["rand_Last_File"] = rand_Input;


    START_CREATING_FILE:
    ofstream json_File;
    json_File.open("config.json", ios::out);
    json_File.seekp(0);
    json_File << setw(4) << user_Settings;
    json_File.close();

    createfile(user_Input, std_Input, rand_Input);

    compilefile();

    int cnt = 0, sum_Timeuse = 0, max_Timeuse = 0, min_Timeuse = 0x7fffffff;
    while(1){
        ++cnt;
        int flag = 0, user_St = 0, user_Ed = 0, user_Timeuse = 0;

        int randret = system("cache\\rand.exe");
        if (randret != 0){
            cout << "random data generator runtime error!\n"; flag = 1;
        }

        int stdret = system("cache\\std.exe");
        if (stdret != 0){
            cout << "Std runtime error!\n"; flag = 1;
        }

        user_St = clock() * 1000;
        int userret = system("cache\\user.exe");
        user_Ed = clock() * 1000;
        if (userret != 0){
            cout << "User's program runtime error!\n"; flag = 1;
        }
        user_Timeuse = (user_Ed - user_St) / CLOCKS_PER_SEC;
        max_Timeuse = max(max_Timeuse, user_Timeuse);
        min_Timeuse = min(min_Timeuse, user_Timeuse);
        sum_Timeuse += user_Timeuse;

        if (flag == 0) if (system("fc std.out user.out > nul")){
            printf("Wrong Answer on the %d", cnt);
            if (mo(cnt, 10) == 1){
                printf("st "); 
            } else if (mo(cnt, 10) == 2){
                printf("nd ");
            } else if (mo(cnt, 10) == 3){
                printf("rd ");
            } else { printf("th "); }
            printf("set of data\n");
            flag = 1;
        }
        if (flag){ find_Problem(); }
        if (cnt == 1000){ regular_Exit(cnt, max_Timeuse, min_Timeuse, sum_Timeuse); }

        if (GetAsyncKeyState(VK_ESCAPE)){ regular_Exit(cnt, max_Timeuse, min_Timeuse, sum_Timeuse); };
        if (mo(cnt, 20) == 0){ printf("%d sets of datas have been checked\n", cnt); }
    }
}