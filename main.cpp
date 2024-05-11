#include <iostream>
#include <cstring>

using namespace std;

class BasePoint
{
    double X;
    double Y;
public:
    BasePoint() :X(0), Y(0) {};
    BasePoint(double _X, double _Y) :X(_X), Y(_Y) {};
    ~BasePoint() {};

    virtual void printinfo(){
        cout << "(" << X << " , " << Y << ")\n";
    }

};

class Elipse : public BasePoint
{
    double a;
    double b;
public:
    Elipse() : BasePoint(0, 0), a(1), b(1) {};
    Elipse(double x, double y, double a, double b) : BasePoint(x, y), a(a), b(b) {};
    ~Elipse() {};
    double S() {
        double S = 3.14 * a * b;
        return S;
    }
    double P() {
        double P = 4 * (3.14*a*b + (a - b) *(a - b)) / (a + b);
        return P;
    }

};

class Circle : public BasePoint
{
    double R;
public:
    Circle() : BasePoint(0, 0), R(1) {};
    Circle(double x, double y, double r) : BasePoint(x,y), R(r) {};
    ~Circle() {};
    double S() {
        double S = 3.14 * R * R;
        return S;
    }
    double C() {
        double C = 2 * 3.14 * R;
        return C;
    }
};

void firstTask(){
    Elipse elipse(1, 2, 3, 4);
    Circle circle(0, 0, 5);

    cout << "Elipse centre:\n";
    elipse.printinfo();
    cout << "Circle centre:\n";
    circle.printinfo();

    cout << "Elipse S: " << elipse.S() << endl;
    cout << "Elipse P: " << elipse.P() << endl;

    cout << "Circle S: " << circle.S() << endl;
    cout << "Circle C: " << circle.C() << endl;
}


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void insertHelper(Node* node, int value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(value);
            }
            else {
                insertHelper(node->left, value);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new Node(value);
            }
            else {
                insertHelper(node->right, value);
            }
        }
    }


    void LeftRight(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            LeftRight(root->left);
            LeftRight(root->right);
        }
    }

    void RightLeft(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            RightLeft(root->right);
            RightLeft(root->left);
        }
    }
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
        }
        else {
            insertHelper(root, value);
        }
    }

    void LeftRight() {
        cout << "Your tree: ";
        LeftRight(root);
        cout << endl;
    }

    void RightLeft() {
        cout << "Your tree: ";
        RightLeft(root);
        cout << endl;
    }
};

void secondTask(){
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(1);
    tree.insert(10);

    tree.LeftRight();
    tree.RightLeft();
}

class MyString {
protected:
    char* str;

public:
    MyString() {
        str = new char[1];
        str[0] = '\0';
    }

    MyString(const char* s) {
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    MyString(const MyString& other) {
        int len = strlen(other.str);
        str = new char[len + 1];
        strcpy(str,  other.str);
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            int len = strlen(other.str);
            str = new char[len + 1];
            strcpy(str,  other.str);
        }
        return *this;
    }

    ~MyString() {
        delete[] str;
    }

    friend ostream& operator<<(ostream& out, const MyString& s) {
        out << s.str;
        return out;
    }

    friend istream& operator>>(istream& in, MyString& s) {
        char temp[1000];
        in >> temp;
        int len = strlen(temp);
        delete[] s.str;
        s.str = new char[len + 1];
        strcpy(s.str,  temp);
        return in;
    }
};

class DigitString : public MyString {
public:
    DigitString() : MyString() {}

    DigitString(const char* s) : MyString(s) {}

    DigitString(const DigitString& other) : MyString(other) {}

    DigitString& operator=(const DigitString& other) {
        MyString::operator=(other);
        return *this;
    }
};

void thirdTask(){
    MyString s1("Hello");
    cout << "s1: " << s1 << endl;

    MyString s2;
    cin >> s2;
    cout << "s2: " << s2 << endl;

    MyString s3 = s1;
    cout << "s3: " << s3 << endl;

    s3 = "World";
    cout << "s3: " << s3 << endl;

    DigitString ds1("12345");
    cout << "ds1: " << ds1 << endl;

    DigitString ds2;
    cin >> ds2;
    cout << "ds2: " << ds2 << endl;

    DigitString ds3 = ds1;
    cout << "ds3: " << ds3 << endl;

    ds3 = "67890";
    cout << "ds3: " << ds3 << endl;
}

int main(){
//    firstTask();
//    secondTask();
    thirdTask();
    return 0;
}
