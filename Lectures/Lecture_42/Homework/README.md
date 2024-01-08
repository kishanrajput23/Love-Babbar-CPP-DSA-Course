# Homework

**Q.1** Why below code printing size is equal to 12 instead of 9?
```cpp
#include<iostream>
using namespace std;

class Hero {

    public:
    int health;
    char level;
    int l;
};

int main() {

    Hero h1;

    cout<<"size : "<<sizeof(h1)<<endl;

    return 0;
}
```

**Ans:** The size of a class or structure in C++ is affected by a concept called "padding" or "alignment." The compiler may add extra bytes to align the members of a class or structure in memory, which can result in a size larger than the sum of the sizes of its members.

In Hero class:

```cpp
class Hero {
public:
    int health;
    char level;
    int l;
};
```

`int health` takes 4 bytes (on many systems).

`char level` typically takes 1 byte.

`int l` also takes 4 bytes.

The total size would be 9 bytes if there was no padding for alignment.

However, many compilers add padding between members for alignment purposes. In your case, it seems like there's 3 bytes of padding added after the `char level`, making the total size 12 bytes.

If you want to minimize padding, you can use compiler-specific pragmas or attributes to control it. For example, with GCC, you might use `__attribute__((packed))`:

```cpp
class Hero {
public:
    int health;
    char level;
    int l;
} __attribute__((packed));
```

Keep in mind that packing might affect the performance due to unaligned access issues, so it should be used judiciously.

**Q.2** What is greedy alignment?

**Ans:** Greedy alignment refers to the practice of arranging the members of a structure or class in such a way that padding is minimized. By placing members with larger alignment requirements before those with smaller alignment requirements, you can potentially reduce the amount of padding required.

In languages like C++, where memory layout has a significant impact on performance due to cache lines and memory access patterns, arranging members to minimize padding can lead to better memory utilization and potentially improved runtime efficiency.

**Q.3** What is padding?

**Ans:** Padding is introduced in memory allocation to ensure proper alignment of data within structures. CPUs have specific memory alignment requirements for different types of data. 

When you have a structure containing different data types, the compiler might insert "padding bytes" between members to align them according to the CPU's requirements.


**Q.4** What is const Keyword?

The `const` keyword in C++ signifies that something cannot be modified. When applied to variables, it means the variable's value can't be changed. For pointers, it can mean that the pointer can't change what it points to or that the data it points to can't be changed, depending on its placement.

   ```cpp
   const int x = 10; // x cannot be modified
   ```

**Using `const` in Object Creation and Member Data**:

- **Object Creation**: When you declare an object as `const`, it means you can't modify any of its data members (unless they are declared as `mutable`).

```cpp
    const MyClass obj; // obj's members cannot be modified
```

- **Member Data Types**: When a class data member is declared as `const`, it means that member cannot be modified after the object is constructed.

```cpp
    class MyClass {
    private:
        const int x; // x must be initialized in the constructor and cannot be modified afterwards
};
```

**`const` Functions**:

A member function that is declared `const` promises not to modify any non-mutable member variables of the object for which it's called. This allows you to call the function on a `const` object. 

```cpp
    class MyClass {
    public:
        int value = 0;
      
        int getValue() const { // A const member function
            return value;
        }
      
        void setValue(int v) { // Non-const member function
            value = v;
        }
};

    const MyClass obj;
    int x = obj.getValue(); // OK to call
    
    // obj.setValue(5); // Error, because setValue is not a const function
   ```

**Q.5** What is Initialization List?

Initialization lists are used in C++ to directly initialize data members of a class. They are particularly useful for initializing `const` members, member objects without a default constructor, and reference members.

```cpp
    class MyClass {
    private:
        const int x;
        int &y; // Reference to an integer

    public:
        MyClass(int value, int &ref) : x(value), y(ref) { 
          // x and y are initialized using an initialization list
        }
};

    int main() {
        int externalInt = 5;
        MyClass obj(10, externalInt);
    }
```

In the above `MyClass`, the `x` member is a `const` integer and must be initialized using an initialization list in the constructor. The `y` member is a reference and also must be initialized using the initialization list.

# Self Study

- [OOPS in C++](https://www.codingninjas.com/studio/guided-paths/oops-in-c)