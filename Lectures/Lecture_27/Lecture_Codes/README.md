# Predict The Output

**Q.1:**
```
int first = 8;
int second = 18;
int *ptr = &second;
*ptr = 9;
cout  << first << " " << second << endl;    
```
Ans : 8 9

**Q.2:**
```
int first = 6;
int *p = &first;
int *q = p;
(*q)++;
cout << first  << endl;
```
Ans : 7

**Q.3:**
```
int first = 8;
int *p = &first;
cout << (*p)++ << " ";
cout << first << endl;
```
Ans  : 8 9

**Q.4:**
```
int *p = 0;
int first = 110;
*p = first;
cout << *p << endl;
```
Ans : Segmantation Fault Error

**Q.5:**
```
int first = 8;
int second = 11;
int *third = &second; 
first = *third;
*third = *third + 2;
cout  << first << "  " << second << endl;
```
Ans : 11 13

**Q.6:**
```
float f = 12.5;
float p = 21.5;
float* ptr = &f;
(*ptr)++;
*ptr = p;
cout << *ptr << " " << f << " " << p << endl;
 ```   
Ans : 21.5 21.5 21.5

**Q.7:**
```
int arr[5];
int *ptr;
cout << sizeof(arr) << " " << sizeof(ptr) << endl;
```
Ans : 20 8

**Q.8:**
```
int arr[] = {11, 21, 13, 14};
cout << *(arr) << " " << *(arr+1) << endl;
```
Ans : 11 21

**Q.9:**
```
int arr[6] = {11, 12, 31};
cout << arr << " " << &arr << endl;
```
Ans : 0x16d283450 0x16d283450  (Random addresses will be printed)

**Q.10:**
```
int arr[6] = {11, 21, 13};
cout << (arr + 1) << endl;
```
Ans : 0x16d283450  (Random address will be printed)

**Q.11:**
```
int arr[6] = {11, 21, 31};
int *p = arr;
cout << p[2] << endl;
```
Ans : 31

**Q.12:**
```
int arr[] = {11, 12, 13, 14, 15};
cout << *(arr) << " " << *(arr + 3);
```
Ans : 11 14

**Q.13:**
```
int arr[] = {11, 21, 31, 41};
int *ptr = arr++;
cout << *ptr << endl;
```
Ans : Error

**Q.14:**
```
char ch = 'a';
char* ptr = &ch;
ch++;
cout << *ptr << endl;
```
Ans : b

**Q.15:**
```
char arr[] = "abcde";
char *p = &arr[0];
cout << p << endl;
```
Ans :  abcde

**Q.16:**
```
char arr[] = "abcde";
char *p = &arr[0];
p++;
cout << p << endl;   
```
Ans : bcde

**Q.17:**
```
char str[]= "babbar";
char *p = str;
cout << str[0] << " " << p[0] << endl;
```
Ans : b b

**Q.18:**
```
void update(int *p) {
    *p = (*p)  *  2;
}

int main() {
    int i = 10;
    update(&i);
    cout << i << endl;
}
```
Ans : 20

**Q.19:**
```
void fun(int arr[]) {
    cout << arr[0] << " ";
}

int main() {
    int arr[] = {11, 12, 13, 14};
    fun(arr + 1);
    cout << arr[0] << endl;
}
```
Ans : 12 11

**Q.20:**
```
void square(int *p){
    int a = 70;
    p = &a;
    *p = (*p) * (*p);
}

int main(){
    int a = 70;
    square(&a);
    cout << a << endl;
}
```
Ans : 70

**Q.21:**
```
int first = 10;
int *p = &first;
int **q = &p;
int second = 20;
*q = &second;
(*p)++;
cout << first << " " << second << endl;
```
Ans : 10 21

**Q.22:**
```
int first = 110;
int *p = &first;
int **q = &p;
int second = (**q)++ + 9;
cout << first << " " << second << endl; 
```
Ans : 111 119

**Q.23:**
```
int first = 100;
int *p = &first;
int **q = &p;
int second = ++(**q);
int *r = *q;
++(*r);
cout << first << " " << second << endl; 
```
Ans : 102 101

**Q.24:**
```
void increment(int **p){
    ++(**p);
}

int main(){
    int num = 110;
    int *ptr = &num;
    increment(&ptr);
    cout << num << endl;
}  
```
Ans : 111

**Q.25:**
```
int main() {
    int arr[] = {41, 52, 36, 74};
    int *p = (arr + 1);
    cout << *arr + 8;
    return 0;
}
```
Ans : 49

**Q.26:**
```
int main() { 
    char *p;
    char str[] = "pqrstuv";
    p = str;
    p += 3;
    cout << p;
    return 0;
}
```
Ans : stuv

**Q.27:**
```
int main() {
    char arr[20];
    int i;
    for(i = 0; i < 10; i++) {
        *(arr + i) = 65 + i;
    }
    *(arr + i) = '\0';
    cout << arr;
    return 0;
}
```
Ans : ABCDEFGHIJ

**Q.28:**
```
int main() {
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    cout<<*ptr2<<" ";
    cout<< ptr2 - ptr1;
    return 0;
}
```
Ans : 90.5 3

**Q.29:**
```
int main() {
    char st[] = "ABCD";
    for(int i = 0; st[i] != ‘\0’; i++) {
    cout << st[i] << *(st)+i << *(i+st) << i[st];
    }
    return 0;
}
```
Ans : A65AAB66BBC67CCD68DD

**Q.30:**
```
void Q(int z) {
    z += z;
    cout<<z << " ";
}

void P(int *y) {
    int x = *y + 2;
    Q(x);
    *y = x - 1; 
    cout<<x << " ";
}

int main() {
    int x = 5;
    P(&x);
    cout<<x;
    return 0;
}
```
Ans : 14 7 6

**Q.31:**
```
int main() {
    int ***r, **q, *p, i=8;
    p = &i;
    (*p)++;
    q = &p;
    (**q)++;
    r = &q;
    cout<<*p << " " <<**q << " "<<***r;
    return 0;
}
```
Ans : 10 10 10

**Q.32:**
```
int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}

int main() {
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    cout << f(c, b, a);
    return 0;
}
```
Ans : 19
