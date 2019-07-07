---
title: Java Persistency API Notes
tags: [java]
---

1. `@Column` should only be used to define special properties to a field because all fields are by default columns in an Entity, unless specified as `transient`.

2. Bootstrapping can be done via JPA EntityManager or Hibernate SessionFactory. Read through: [waitingforcode.com](http://www.waitingforcode.com/hibernate/difference-between-sessionfactory-and-entitymanagerfactory/read) 

3. Refer to this video: [JPA: Beyond the Copy Paste](https://www.youtube.com/watch?v=yJVhbO75tzw)

4. `@JoinColumn` can be used with `@OneToMany` in order to avoid Join tables.

