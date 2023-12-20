#include<iostream>
using namespace std;
class element {
public :
    bool t;//������ʾ�Ƿ����
    element* mate; //����
    int w;//��ʾ��������ڼ���ϲ���������
    char name;
    element**list; //ϲ���б�
    element() {
        w = -1;
        t = false;
        mate = NULL;
        list = NULL;
    }
    //���
    bool match (int n) {
        for (int i = w+1; i <= n - 1; i++) {
            //����û��飬��ֱ�ӽ�
            if (list[i]->t == false) {
                mate = list[i];
                list[i]->mate = this;
                mate->t = true;
                this->t = true;
                w++;
                return true;
            }
            else {
                //������ˣ���Ƚ�ϲ����
                if (list[i]->compare(*this, *(list[i]->mate), n)) {
                    list[i]->mate->t = false;
                    mate = list[i];
                    list[i]->mate = this;
                    this->t = true;
                    w++;
                    //��Ϊ�Ǹ��˱����ˣ������Ǹ����ֵ����ˣ����Ե����Ǹ��˵�match����
                    if (list[i]->mate->match(n)) {
                        return true;
                    };
                    return false;
                }
            }
            //��ƫ���б�������
            w++;
        }
        //��û�ɹ���˵��û������ƥ��
        return false;
    }
    //�������бȽ�һ�£���ϲ���ĸ���
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
    //��Ϊmalloc��������Ĺ��캯�������������ʼһ��
    for (int i = 0; i <= 2 * n - 1; i++) {
        p[i]->w = -1;
        p[i]->t = false;
        p[i]->mate = NULL;
        p[i]->list = NULL;
    }
    //��ʼÿ��Ԫ�ص�ƫ���б�
    for (int i = 0; i <= 2 * n - 1; i++) {
        p[i]->list = (element**)malloc(sizeof(element*) *  n);
        for (int j = 0; j <= n - 1; j++) {
            p[i]->list[j]= (element*)malloc(sizeof(element));
        }
    }
    
     //����ƫ���б�
    for (int i = 0; i <= 2*n - 1; i++) {
        cin >> input[i];
    }
   
    //�����ָ�ֵ��Ԫ������
    for (int i = 0; i <= 2*n - 1; i++) {
        p[i]->name = input[i][0];
    }
   
     //��ƫ���б�ֵ��ÿ��Ԫ�ص�list
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
        cout << "û��";
    }
}