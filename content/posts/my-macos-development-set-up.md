---
title: My MacOS development set-up checklist
date: 2020-09-16T18:30:00.000Z
series: ""
categories:
  - tutorial
tags:
  - mac
---

![Stock image of Macbook Air](/uploads/goran-ivos-t8lmin09-mo-unsplash.jpg)

I recently decided to reinstall MacOS on my MacBook Air 2017 (yes, I know it's outdated) after the service centre was able to revive the motherboard which died unexpectedly. The purpose of the reinstall was to micromanage my development environment which was filled with unexpected soft-links, aliases, and binary files in random places.

Looking at my old Catalina installation retrospectively, I realised that my development set-up required only 10 applications. With better management I could easily save space on my frail laptop. Below, I present these essential applications with the MacOS solutions for each of them.

# The Checklist

1. Basic tools like git and cc
2. Package manager
3. Terminal emulator
4. Shell program
5. A good font for the shell
6. Dot files management
7. Web browser
8. Privacy and keys
9. The best text editor
10. The popular text editor

# MacOS Solutions

## 1. Xcode command-line tools

If you aren't a MacOS/ iOS developer you can make do without the hefty Xcode. I avoid Xcode IDE because my MacBook only has 128GB of SSD Storage (yes, it sucks). However the command-line tools come with a lot of goodies like git, clang, python3 and such.

I tried `xcode-select --install` but it didn't work. So I download the tools from Apple's developer centre.

[https://developer.apple.com/download/more/](https://developer.apple.com/download/more/ "https\://developer.apple.com/download/more/")

## 2. Homebrew

The missing package manager for MacOS is a must for any developer. I stopped installing applications from .dmg files and I'd rather get the cask through brew.

[https://brew.sh](https://brew.sh "https\://brew.sh")

I also install [homebrew-rmtree](https://github.com/beeftornado/homebrew-rmtree) for good measures. I hate orphan packages.

From here on, 90% of my applications will be installed through Homebrew.

## 3. iTerm2

> If a developer is afraid of the terminal, is he really a developer?

I spend most of my time in the terminal. I have so many configurations and rules that I impose upon myself that I can make an entire blog post about it. For now, let me tell you about iTerm 2:

* It's pretty
* It's fast
* Windowing system is amazing
* Profiles are amazing
* Keymaps for Option+Backspace, Option+← are amazing
* It's amazing

You can find my iterm2 profile [here](https://gist.github.com/vixrant/1ead9e02bb4cb915fd31c06daa3cc804 "iterm2 profile").

```sh
brew cask install iterm2
```

## 4. Oh my ZSH!

The name is very accurate. ZSH is far better than Bash for daily use. Oh-my-zsh will do all the set-up for you, so you can focus on setting the right colour theme and such.

[https://github.com/ohmyzsh/ohmyzsh](https://github.com/ohmyzsh/ohmyzsh "https\://github.com/ohmyzsh/ohmyzsh")

Some additional plugins to install:

* [zsh-autosuggestion](https://github.com/zsh-users/zsh-autosuggestions) - for Fish-like suggestions
* [zsh-syntax-highlighting](https://github.com/zsh-users/zsh-syntax-highlighting/blob/master/INSTALL.md) - for prettier commands
* [zsh-completions](https://github.com/zsh-users/zsh-completions "zsh-completions") - for extra completion scripts
* z - for jumping around your SSD
* colorize - for prettier terminal
* colored-man-pages - for readable man pages
* git - for better git integration in terminal

## 5. Fira Code

A good terminal and a good shell, together with a good font. Aesthetics matter a lot when I'm coding. Fira Code is simple, with good ligatures support for easier reading. This is definitely a subjective taste so you can install anything else.

```sh
brew tap homebrew/cask-fonts
brew cask install font-fira-code
```

## 6. YADM

> Yet Another Dotfiles Manager

However, I've never had a Dotfiles manager before. YADM is my first and only choice for a Dotfiles manager. It's a wrapper over Git so it's extremely hackable. I don't need to learn any new commands, I just do `yadm add -u -a , yadm commit -m "Text"`, `yadm push`. It's simple and intuitive for any git user.

```sh
brew install yadm
```

## 7. Firefox

For the most part, I use Safari because of its simpler and faster UI. However for web development and a better extensions support, I choose Firefox over Chrome because of the following reasons:

* It's open source
* It's not Chrome
* Battery and RAM impact is lower
* It's not Chrome
* It syncs well with Firefox on my android phone
* It's not Chrome
* It's most probably more private than Chrome
* It's not Chrome
* Competition should exist between browsers
* You get the idea

Admittedly, Mozilla has introduced lots of improvements in Firefox and as time passes, it's becoming more pleasurable to use Firefox. Adding to this, when I logged into my Firefox account, I was impressed by how well Mozilla has handled syncing of configuration. It works like Magic.

```sh
brew cask install firefox
```

## 8. GPG

I use GPG for signing my commits in git. It's pretty straightforward. You can read the entire guide [here](https://dev.to/wes/how2-using-gpg-on-macos-without-gpgtools-428f).

```sh
brew install gnupg pinentry-mac
```

## 9. Vim

> The best editor

My journey has been from

Sublime -> Atom -> Vim -> VSCode + Vim -> VSCode + Emacs -> Emacs -> Vim

Sublime was great but not as feature-rich as I wanted it to be. Atom was too heavy for my poor laptop. VSCode was an amazing balance between features of Atom and performance of Sublime, but later as I added more plugins, it got much heavier.

I decided to learn Emacs and configure it using Doom. At first, it was amazing. But with the feature-creep and confusing controls (I used Evil bindings), it was a headache to configure. In the end, I settled for a minimal configuration of Macvim.

And my laptop loves it as much as I do. I get 3-4 hours more battery life. It's much faster than Emacs and VSCode. I use it primarily for C++, Go, and Python. I'm yet to use Vim for web development.

For autocompletion, I avoid YouCompleteMe. It's archaic, too heavy and difficult to set-up. Instead, I use the fancy LSP server, same as VSCode. I've set-up Coc.nvim to do this, and most of my projects are easy to configure. For C++, clangd can be set up using CMake. For python, I do no configuration at all. It just works.

```sh
brew cask install macvim
```

I've also configured the terminal version to work in vi-compatible mode (no GUI) for quick edits.

```
alias vim="mvim -v"
```

A more detailed explaination of my Vim configuration will be the subject for a future blogpost.

## 10. VSCode

> The popular editor

Again, I do not like hefty IDEs on my feeble laptop. So I try to configure text editors as much as possible.

`brew cask install visual-studio-code`

A few extensions that I use are PlatformIO for embedded development and simple-ghc for simplistic Haskell development. Some standard extensions like

## Conclusion

The checklist presented in this article is what I absolutely need on any new laptop to start coding productively. Your requirements may vary depending on how comfortable you are with other tools. My set-up is so lightweight in nature that my 128GB laptop works pretty well for the kind of development I do. If you have any questions you can drop me an email or contact me on twitter @vixrant.

Furthermore, I am currently writing two more articles: one on my set-up for different programming languages, and one for my emacs configuration. Look forward to that!