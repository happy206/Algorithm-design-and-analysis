#include<iostream>
using namespace std;
class element {
public :
    bool t;//用来表示是否配对
    element* mate; //伴侣
    int w;//表示这个人他第几个喜欢的配对了
    char name;
    element**list; //喜好列表
    element() {
        w = -1;
        t = false;
        mate = NULL;
        list = NULL;
    }
    //配对
    bool match (int n) {
        for (int i = w+1; i <= n - 1; i++) {
            //那人没结婚，则直接结
            if (list[i]->t == false) {
                mate = list[i];
                list[i]->mate = this;
                mate->t = true;
                this->t = true;
                w++;
                return true;
            }
            else {
                //如果结了，则比较喜欢度
                if (list[i]->compare(*this, *(list[i]->mate), n)) {
                    list[i]->mate->t = false;
                    mate = list[i];
                    list[i]->mate = this;
                    this->t = true;
                    w++;
                    //因为那个人被撬了，所以那个人又单身了，所以调用那个人的match函数
                    if (list[i]->mate->match(n)) {
                        return true;
                    };
                    return false;
                }
            }
            //按偏好列表往下走
            w++;
        }
        //都没成功，说明没有完美匹配
        return false;
    }
    //两个人中比较一下，更喜欢哪个人
    bool compare(element a, element b,int n) {
        bool x = true;
        for (int i = 0; i <= n - 1; i++) {
            if (list[i]->name == a.name) {
                x = true;
                return x;
            }
            if (list[i]->name == b.name) {
                x = false;
                return x;
            }
        }
    }
};
int main() {
    int n;
    cin >> n;
    char ** input=NULL;
    input = (char**)malloc(sizeof(char*) * 2*n);
    for (int i = 0; i <= 2*n - 1; i++) {
        input[i] = (char*)malloc(sizeof(char) * (2 * n + 2));
    }
    element** p = (element**)malloc(sizeof(element*) * 2*n);
    for (int i = 0; i <= 2 * n - 1; i++) {
        p[i] = (element*)malloc(sizeof(element));
    }
    //因为malloc不调用类的构造函数，所以在这初始一下
    for (int i = 0; i <= 2 * n - 1; i++) {
        p[i]->w = -1;
        p[i]->t = false;
        p[i]->mate = NULL;
        p[i]->list = NULL;
    }
    //初始每个元素的偏好列表
    for (int i = 0; i <= 2 * n - 1; i++) {
        p[i]->list = (element**)malloc(sizeof(element*) *  n);
        for (int j = 0; j <= n - 1; j++) {
            p[i]->list[j]= (element*)malloc(sizeof(element));
        }
    }
    
     //输入偏好列表
    for (int i = 0; i <= 2*n - 1; i++) {
        cin >> input[i];
    }
   
    //将名字赋值给元素数组
    for (int i = 0; i <= 2*n - 1; i++) {
        p[i]->name = input[i][0];
    }
   
     //将偏好列表赋值给每个元素的list
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 2,k=0; j <= 2 * n + 1; j=j+2,k++) {

            for (int h = n; h <= 2*n - 1; h++) {

                if (p[h]->name == input[i][j]) {
                    p[i]->list[k] = p[h];
                }
            }
        }
    }
    for (int i = n; i <= 2*n - 1; i++) {
        for (int j = 2, k = 0; j <= 2 * n + 1; j=j+2, k++) {

            for (int h = 0; h <=  n - 1; h++) {

                if (p[h]->name == input[i][j]) {
                    p[i]->list[k] = p[h];
                }
            }
        }
    }

    bool success = true;
    for (int i = 0; i <= n - 1; i++) {
        if (p[i]->t) {
            continue;
        }
        if (p[i]->match(n)) { }
        else {
            success = false;
            break;
        }
    }
    if (success) {
        for (int i = 0; i <= n - 1; i++) {
                cout << "(" << p[i]->name << ","  <<p[i]->mate->name<<")" << endl;
        }
    }
    else {
        cout << "没有";
    }
}