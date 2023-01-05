## 函数原型

```c++
void sort (RandomAccessIterator first, RandomAccessIterator last);
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

## 结构体与类

由于C语言是面向过程的，所以C中的结构体就不存在面向对象的任何特点：不能继承；不能封装；不能多态；不存在访问控制，只有作用域。

类描述看上去很像包含成员函数以及public和private可见性标签的结构声明，实际上，C++对结构进行了扩展，使之具有与类相同的特性。**它们之间的唯一区别是：结构的默认访问类型是public**，**而类的默认访问类型为private**。

在C++中除了类中可以有构造函数和析构函数外，结构体中也可以包含构造函数和析构函数，这是因为结构体和类基本雷同，唯一区别是，类中成员变量默认为私有，而结构体中则为公有。

注意，C++中的结构体是可以有析构函数和构造函数，而C则不允许。至于联合体，它是不可能有析构函数和构造函数的。本质上，它是一种内存覆盖技术的体现，也就是说，同一块内存在不同的时刻存储不同的值（可能是不同类型的）。

## C和C++中结构体的不同

C语言中的结构体不能为空，否则会报错

C语言中的结构体只涉及到数据结构，而不涉及到算法，也就是说在C中数据结构和算法是分离的。换句话说就是C语言中的结构体只能定义成员变量，但是不能定义成员函数。

在C++中既可以定义成员变量又可以定义成员函数， C++中的结构体和类体现了数据结构和算法的结合。

虽然C语言的结构体中不能定义成员函数，但是却可以定义函数指针，不过函数指针本质上不是函数而是指针，所以总的来说C语言中的结构体只是一个复杂数据类型 ，只能定义成员变量，不能定义成员函数，不能用于面向对象编程。

在 C 中，必须显式使用 struct 关键字来声明结构。 在 c + + 中，不需要在 struct 定义类型后使用关键字。

## 自定义排序规则

### 给简单变量排序

默认升序排序

```c++
bool cmp(const int &a, const int &b) {
    return a < b;
}
```

重写为降序

```c++
bool cmp(const int &a, const int &b) {
    return a > b;
}
```

### 给结构体排序

```c++
struct node {
    int x, y;
}q[N];
```

升序

```c++
bool cmp(node a, node b) {
    return a.x < b.x;
}
```

降序

```c++
bool cmp(node a, node b) {
    return a.x > b.x;
}
```

多条件

```c++
bool cmp(node a, node b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
```

### 给map排序

map按key排序

```

```

map按value排序

C++中如果使用`std::map`或者`std::multimap`可以对key排序，但不能对value排序。所以要把map转化数组即vector，再进行排序，当然vector里面放的也是`pair<int, int>`类型的数据，第一个int为元素，第二个int为出现频率。

题目：[前K个高频单词](https://leetcode.cn/problems/top-k-frequent-words/)

```c++
// 必须加static
static bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}
vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> m;
    vector<string> res;
    for (auto word : words) {
        m[word] ++ ;
    }
    vector<pair<string, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < k; i ++ ) {
        res.push_back(vec[i].first);
    }
    return res;
}
```

### 给pair排序

pair 默认对first升序，当first相同时对second升序

```c++
bool cmp(pair<int, int>a, pair<int, int>b)
{
    return a.first<b.first;//根据fisrt的值升序排序
    //return a.second<b.second;//根据second的值升序排序
}
```

