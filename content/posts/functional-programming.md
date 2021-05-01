---
title: Functional Programming in Java
date: 2018-09-01
categories:
- tutorial
tags: 
- java
- fp
---

Functional programming is my favourite aspect of some languages such as JavaScript. You can do the same work in a more expressive way. For example if we want to multiply all terms in an array by 2, there are two ways to go about it in JavaScript.

```javascript
var arr = [1, 2, 3, 4, 5];
for (let i in arr) {
    arr [i] *= 2;
}
```

The above method requires 3 lines of code and an extra variable to do the same work as:

```javascript
var arr = [1, 2, 3, 4, 5];
arr = arr.map (e => e * 2);
```

Java started taking functional programming seriously from Java 8.

## Syntax features

Functional programming was accelerated in Java with Java 8's Lambda expressions and :: operator.

### Lambda expressions

Say you have an interface with only one overridable function, such as an ActionListner:

```java
interface ActionListener {
    public void actionPerformed (Event e);
}
```

This is from the source-code of ActionListener. This is a functional interface. We can annotate it with `@FunctionalInterface`. The requirement is that the interface must have exactly one abstract method.

Now when we add this ActionListener to a button we do it as so:

```java
button.add (new ActionListener () {
    @Override
    public void actionPerformed (Event e) {
        Line1
        Line2
        ...
        LineN
    };
});
```

This is very verbose. To simplify it we can a Lambda expression as so:

```java
button.add ((Event e) -> {
    Line1
    Line2
    ...
    LineN
});
```

This saved us some writing. It's similar to saying "Hey, take this Event e and execute this block of statements for me!". Note that this only works when there is one overridable function in the interface.

The fantastic thing about Java's lambda expressions is that we don't even need to specify the datatypes of the arguments. And if there is one argument only, we can omit the brackets as well.

```java
button.add (e -> {
    Line1
    Line2
    ...
    LineN
});
```

Let's say you are calling a function `f (Event e)` when a button is clicked.

```java
button.add (new ActionListener () {
    @Override
    public void actionPerformed (Event e) {
        f (e);
    };
});
```

We can simplify the expression into: 

```java
button.add (e -> {
    f (e);
});
```

Since there is a single function call, we can simplify it further by omitting the curly brackets `{}`:

```java
button.add (e -> f (e));
```

Look at it! From 6 lines of code to 1 line! This is very much like JavaScript's arrow functions.

### Method References.

We have the above example:

```java
button.add (e -> f (e));
```

But let's say `f` is a static function. You can use the Method reference `::` operator to call the function directly with the required arguments:

```java
button.add (this::f);
```

Here since `f` is a static function in the same class, I'm using `this`. If it was in `StaticFunctionsContainer` class, we use `StaticFunctionsContainer::f`.

You can also reference the constructor of classes using the Method reference operator. Here are some important references:

```java
System::getProperty
System.out::println
"abc"::length
ArrayList::new
int[]::new
```

## Streams

Streams are Java objects which allow traditional functional-style syntax.

Think of it like a stream of water. A stream of water has continuous on-demand data. This allows for operations on-the-fly. But there's no storage of water, is there? Water comes, water goes. Compare this to a jar of water where all the water is collected in one place. It doesn't move, but it's stored safely. This is the difference between a Java Collection and a Java Stream as well.

You cannot create a reference to a stream. A stream has to originate from a 'source', for example, a Java Collection!

As an example, say I have a vector V of {1, 2, 3, 4, 5} and I need to map these to their 2*squares + 5:

```java
V.stream().map(e -> 2*e*e + 5);
```

Make use of these streams with the above lambda functions to get the best out of functional programming in Java.

-----

This is my favourite resource for learning more about streams: [JournalDev](https://www.journaldev.com/2774/java-8-stream#stream-overview).
