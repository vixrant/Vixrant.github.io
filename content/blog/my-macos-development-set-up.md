+++
date = 2020-09-16T18:30:00Z
draft = true
feature_img = ""
series = "Development Environment"
tags = ["guide", "mac"]
title = "My MacOS development set-up"

+++
I recently decided to reinstall MacOS on my MacBook Air 2017 (yes, I know it's outdated). This is because my environment was getting too cluttered with files and binaries everywhere, so I thought of starting from scratch all over again.

Here's how I set-up my laptop for development, feel free to refer to this for set-up tips as well.

## 1. Xcode command-line tools

If you aren't a MacOS/ iOS developer you can make do without the hefty Xcode. I avoid Xcode IDE because my MacBook only has 128GB of SSD Storage (yes, it sucks). However the command-line tools come with a lot of goodies like git, clang, python3 and such.

I tried `xcode-select --install` but it didn't work. So I download the tools from Apple's developer centre.

## 2. Homebrew

The missing package manager for MacOS is a must for any developer. I stopped installing applications from .dmg files and I'd rather get the cask through brew.

[https://brew.sh](https://brew.sh "https://brew.sh")

From here on, 90% of my applications will be installed through Homebrew.

## 3. iTerm 2