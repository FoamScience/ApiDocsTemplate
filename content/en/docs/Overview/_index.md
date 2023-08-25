---
title: Overview
description: Here's where you finds out if this project is for you
weight: 1
---

{{< alert title="Note" >}}
If you write OpenFOAM code with C++17 and up; you may want to help supporting the
new constructs by PRing to [Hyde](https://github.com/adobe/hyde)!
{{< /alert >}}

This page is basically a recap of what would be a user-guide on how to use this website
to generate your own docs.

## What is this?

We rely on [Hugo](https://gohugo.io) static site generator to build HTML docs we get from
[Hyde](https://github.com/adobe/hyde). This allows us to host such websites for free on
multiple platforms (Github Pages being our target).

The promise is that you will only have to write your docs in Markdown syntax, and you get
automatic updates for your docs as your code changes.

{{< alert color="warning" >}}
We cannot supported full up-to-date states of the docs specifically because OpenFOAM
code does not respect this. If they mark methods with `[[deprecated]]`, this is supposed
to be reflected in the docs but it is not yet enforced in most OpenFOAM forks!
{{< /alert >}}

## Why do I want it?

Help your user know if your project will help them. Useful information can include:

* **What is it good for?**: What types of problems does your project solve? What are the benefits of using it?

* **What is it not good for?**: For example, point out situations that might intuitively seem suited for your project, but aren't for some reason. Also mention known limitations, scaling issues, or anything else that might let your users know if the project is not for them.

* **What is it *not yet* good for?**: Highlight any useful features that are coming soon.

## Where should I go next?

Give your users next steps from the Overview. For example:

* [Getting Started](/docs/getting-started/): Get started with $project
* [Examples](/docs/examples/): Check out some example code!

