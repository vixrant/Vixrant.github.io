+++
date = 2020-09-11T18:30:00Z
draft = true
feature_img = "/uploads/screenshot-2020-09-12-at-11-38-30-am.png"
series = ""
tags = ["compiler", "cpp", "emacs"]
title = "My Emacs set-up for C++ and LLVM"

+++
Recently I decided to learn Emacs because of its extreme customisability and scriptability. After a some learning I've finally gotten the hang of it for the most part. The packages system is a little more complex than VSCode but it's definitely worth it in the end.

One issue I had with VSCode and Vim was C++ development. It just wasn't satisfying enough. With emacs, I decided to set-up a perfect C++ experience by learning a variety of tools including CMake and LSP. This blog post should serve as a concise report of my findings. Feel free to refer to it for setting up for development environment.

## Emacs set-up

* Doom-emacs because
  * Easy set-up
  * Fast start-up time and performance
  * Close to vanilla emacs
  * Good evil mode settings
  * Easy module development compared to spacemacs
* LSP module
* cc module with +lsp flag