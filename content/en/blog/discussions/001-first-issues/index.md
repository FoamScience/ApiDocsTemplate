---
date: 2023-08-18
title: The very first issues I ran into with this documentation project
linkTitle: First Issues
description: >
  While planning on how to best document my PhD projects, this is my vision
  for the best approach focusing on easy-to-update docs and decent-looking
  web pages.
author: Mohammed Elwardi Fadeli ([@elwardi](https://www.linkedin.com/in/elwardi-fadeli))
tags:
  - documentation
  - c++
  - hyde
---

There are basically three main issues:

## Documenting C++20 (specifically: concepts)

At the time of writing, Hyde doesn't support the C++ concepts yet, which I plan to use
extensively. The code still compiles (because `clang` can compile it) but
Hyde ignores `require` statements. Its reaction to `concept` declarations isn't tested.

The current behavior is that `require` does not show up in the declaration:
```cpp
template <std::regular T>
class myClass;
```
simply appears in the API docs as:
```cpp
template <class T>
class myClass;
```
which is a lot more generic and may not give a precise idea on what's going on.
It's flat out wrong.

{{% alert color="success" %}}
At the time of writing, I can live with this though.
{{% /alert %}}

## The OpenFOAM fork needs to compile with clang

Basically, any dependency code you rely on, as well as your own libraries, need
to compile with clang. Foam-Extend, for example, doesn't, since `clang` thinks
some calls to operators between `tmp` objects are unambiguous.

Also, even with the forks which mostly compile with `clang`, they frequently
use `[[deprecated]]` to make the compiler mark functions and methods as deprecated. But,
they do not maintain the inline docs to match the deprecated docs.

`Hyde` actually sets compiler deprecation warnings as errors by default. We have to
skip this step, and as a result we lose the automatic synchronization between code
and API docs.

## Linking to actual source files

Personally I don't like to link API docs to actual source files. It's the job of
your IDE to show where stuff are, and to show you the documentation too.

Hyde can generate source file relationships if we add `-hyde-src-root` to the call
but this clutters the left sidebar with unwanted content.

It's generally accepted that each class is written in its own file. Again, we can live
without this feature too.

## Recap

The whole system can crumble very easily. And it might not even be your fault, so you
couldn't fix it! But while it works, it works marvelously well! Plus, it's an opportunity
for me to learn new things (Compiler AST, for example?).
