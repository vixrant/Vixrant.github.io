---
title: Multiprocessing for buffering the latest frames in a video stream
draft: true
date: 2020-12-28T12:29:03.014Z
feature_img: /uploads/frame-1-2.png
tags:
  - python
  - opencv
---
Have you ever wanted to implement a video-classification model which needs the buffer of 30 frames, yet you do not want the predict() function of your machine learning model to make your video-stream "choppy"?

When I implement a complex computation on a video in a single python process, I've noticed that my imshow() window reduces its framerate since the `model.predict()`function takes up a lot of time. It's fine if you aren't showing the image frames as and when they appear.

## Premise

However, in our bachelor's final year project, I want two computations to run in parallel - one is an estimation model for hand poses of in a video frame, and the other is a classification model that classifies a buffer of 30 hand-poses. The estimation model runs fast enough - at 15 frames per second on a Macbook Air 2017 with i5 5th generation CPU and no GPU. We use Mediapipe's solutions for this model, so Google overlords have optimised it really well for on-device inference.

The other model is our own - a spatio-temporal classification model that takes as input an array of 30 hand frames, each hand frame contains 21 hand points, each hand point is an X, Y, Z tuple (the input shape is 30x21x3). This model takes a lot of time for its classification. In the mean time, I do not want the estimation model to wait for the classification model. If it does, the entire project is gonna slow down.

## Option 1: Single Process

```
Algorithm SingleProcessImplementation():
1. Initialise an empty Buffer
2. Videoframe = Capture from webcam
3. Handframe = Run estimation model on Videoframe
4. Put Handframe in Buffer
5. Repeat steps 2-4 until Buffer size = 30
6. Results = Run classification model on Buffer
7. Show Handframe, Results
8. Clear Buffer
9. Goto step 2
```

This algorithm would work great! On a beefy computer where our model would take milliseconds to infer its results - which isn't the case here since I'm a broke undergraduate student with 5 year old laptop hardware. This can work, it'll give me the classification results. But I don't want to bear that lag in video stream.

## Option 2: Multi Process

I follow a producer-consumer system. Let me explain with this pseudocode:

```
Algorithm EstimationProcess(Buffer):
1. Videoframe = Capture from webcam
2. Handframe = Run estimation model on Videoframe
3. Lock Buffer
4. Put Handframe in Buffer
5. Unlock Buffer
6. Repeat steps 1-5

Algorithm ClassificationProcess(Buffer):
1. Wait till Buffer size = 30
2. Lock Buffer
3. Copy Buffer into Snapshot
4. Unlock Buffer
5. Results = Run classification model on Snapshot
6. Repeat steps 1-5

Algoritm MainProcess():
1. Initialise a Buffer and a lock for concurrency
2. Start EstimationProcess(Buffer)
3. Start ClassificationProcess(Buffer)
```

What's happening here?
(TODO)

## Python Code

