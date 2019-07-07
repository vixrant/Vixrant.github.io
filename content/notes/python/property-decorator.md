---
title: '@property decorator in Python'
tags: ['python', 'fp']
---

You may remember this from Java:

```java
class Main {
    private int x = 5;

    public void setX(int x) {
        this.x = x;
    }

    public int getX() {
        return this.x;
    }
}
```

While effective in allowing you to control how a field of a class is set in Java or C++, this doesn't work in Python. It's not very 'pythonic' to *call* getters and setters in python.

```python
class Main:
    def __init__(self):
        self.x = 5

    def set_x(self, x):
        self.x = x
    
    def get_x(self):
        return self.x
```

Why would you call `main.get_x()` or `main.set_x()` in Python when you know that you can easily access perform `main.x = main.x + 5`? There's no control over it.

Except maybe you can call `get_x()` and `set_x()` when you're trying to access `main.x` directly? That's possible in python with the `property` class and attribute.

-----

[Guide](https://www.programiz.com/python-programming/property)

[Docs](https://docs.python.org/3/library/functions.html?highlight=property#property)
