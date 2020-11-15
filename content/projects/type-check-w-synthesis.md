---
title: Program Synthesis for Runtime Checking of Javascript

---
Typescript and Flow are great for adding static type checking to Javascript, but they require a major refractoring of the codebase. Further, they don't check types at runtime! We end up writing a lot of boilerplate code to assert that an object has the required properties or not. Instead, I aim to reduce the efforts of writing tons of if-else statements, without a massive refactoring of the project, using program synthesis of runtime type checking. This would transform Javascript to a strictly typed language wherever that level of safety is required.