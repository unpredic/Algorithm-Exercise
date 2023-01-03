// 根据输入的秒数，转换成相应的时，分，秒数据输出过程为：
// 定义变量h, m, s来存储转换结果
// 定义seconds变量，接收用户输入
// 得到小时数：h=seconds/3600;
// 去除小时数：seconds%=3600; 
// 得到分钟数：m=seconds/60;
// 得到秒数：s=seconds%60 ;
// 输出结果

#include <iostream>

using namespace std;

int get_seconds(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

int get_time() {
    string line;
    getline(cin, line);
    if (line.back() != ')') line += " (+0)";
    int h1, m1, s1, h2, m2, s2, d;
    sscanf(line.c_str(), "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
    // 为什么第二个时间不会小于第一个时间 ?
    return get_seconds(h2, m2, s2) - get_seconds(h1, m1, s1) + d * 24 * 3600;
}

int main() {
    int n;
    scanf("%d", &n);
    string line;
    getline(cin, line); // 忽略掉n后面的回车
    
    while (n -- ) {
        int time = (get_time() + get_time()) / 2;
        int hour = time / 3600, minute = time % 3600 / 60, second = time % 60;
        printf("%02d:%02d:%02d\n", hour, minute, second);
    }
    
    return 0;
}



14945

14945
04:09:05

25839

61839
12:10:39

37325

66125
14:22:05