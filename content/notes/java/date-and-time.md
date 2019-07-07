---
title: Date and Time in Java
tags: [java]
---

## `Date` class

Java has a utility Date class ~ `java.util.Date`, and a text based approach ~ `java.text.StringDataFormat`. The Date class is difficult to use. It only stores times in seconds and that too from Unix Epoch Time - 1970-01-01T00:00:00Z, and it disrespects Timezones for the most part.

If you say: 
```java
Date d = new Date (2018, 9, 19);
```

You would expect it the Date object to represent 2018-Sep-19. But it actually refers to 3917-Oct-19. The year parameter is actually the delta between 1900 and the year you want, so 3918 = 2018 + 1900. Similarily, 9 here refers to October because January is 0.

Besides this un-intuitive constructor of Date class, Java doesn't provide any methods for you to operate on these objects. You can't ask the Date object what comes after 24 hours. You'd have to calculate that by adding 24\*60\*60 to the seconds of Date object by using `Date.getTime ()` method, then convert is using `TimeUnit.DAYS.convert ()` or any other TimeUnit function. You can checkout this stackoverflow question: [Calculating days between two dates with Java \[duplicate\]
](https://stackoverflow.com/questions/20165564/calculating-days-between-two-dates-with-java)

This is uber complicated and just not fun to use. 

## `LocalDate`, `LocalTime`, `LocalDateTime` class

Lucky for us, Java 8 introduced a new [LocalDate](https://docs.oracle.com/javase/8/docs/api/java/time/LocalDate.html) and LocalDateTime API. Took them long enough to implement something which was done by other languages ages ago.

LocalDate represents an immutable object with loads of predefined methods for our ease. It's a delight to finally just say `d.addDays ()` instead of writing redundant calculations or our own implementation of those calculations.

### Notes about LocalDate:

* LocalDate has private constructors. You cannot instantiate it. Instead, we have static methods which return the object we need.

`LocalDate d = LocalDate.of (2018, Month.SEPTEMBER, 19);`

* You can see from the above definition that 
    1. The syntax is much simpler.
    2. 2018 actually refers to 2018 istead of 3918.
    3. We have a `Month` enum with all the months we need.
    4. There are `LocalDate.ofEpochDay ()` as well as `LocalDate.ofYearDay ()` and `LocalDate.now ()` for more flexible usecases.

* We have brilliant predefined methods such as adding/ subtracting days, months, years, finding the difference in days, and so on.

* We have separate classes for Date, Time, and one class for both DateTime. The separated Date & Time classes have methods for interpolation.
