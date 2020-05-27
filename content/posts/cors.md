---
title: Cross-Origin Resource Sharing (CORS)
date: 2018-09-01
tags: 
- backend
- wip
- javascript
- django
---

This is really important because during a hackathon, I was running an ExpressJS server as one process and a React application as another process. Now since my ExpressJS server was used for REST API, I wasn't able to get any HTTP response back since CORS was denied!

## Enable CORS in ExpressJS:

Always add this middleware to your ExpressJS application,

```javascript
const cors = require('cors');
app.use(cors());
```

## Enable CORS in Django

Install CORS Middleware in your Django project: https://github.com/zestedesavoir/django-cors-middleware

or search how to enable CORS in the backend framework that you're using.

-----
Read up more about CORS on [MDN](https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS).
