---
title: Getting Started
description: What do I need to know to try things out?
categories: [Examples]
tags: [docs]
weight: 2
---

## Prerequisites

- [This fork of Hyde](https://github.com/FoamScience/hyde)
- An [Extended Hugo](https://github.com/gohugoio/hugo/releases) version
- [`jq`](https://jqlang.github.io/jq/download/)
- [`mdformat`](https://github.com/executablebooks/mdformat) with `mdformat-frontmatter`
- [`python-frontmatter`](https://pypi.org/project/python-frontmatter/)
- Your OpenFOAM libraries; with `compile_commands.json` files generated in each library directory.
  An [example source directory is here](https://github.com/FoamScience/ApiDocsTemplate/tree/main/code)
- Clone [this repository](https://github.com/FoamScience/ApiDocsTemplate) and `cd` into it.

## Generate API documentation

Do:
```bash
# These paths need to be absolute
./scripts/generate-docs.sh $PWD/code $PWD/content/en/api
```
That's all; you'll find  your API docs as markdown files in `content/en/api`.
You can add content to them manually. The next time you run this command (hopefully on next
commit), the manual content will not be overwritten but the front matter will be updated.

{{< alert color="warning" >}}
It might not be this easy for your own code. What this actually does is to try and partially compile your code
with [clang](https://clang.llvm.org/doxygen/group__CINDEX.html) to figure out the AST of your code.

For it to work, your code needs to compile with clang.
{{< /alert >}}

This repository provides example API documentation of the libraries in `code` folder.
You can access it through the main menu at the top right corner.

## Make sure the user guide is still up to date

The Markdown files in `content/en/docs` count as a user guide. On every commit, remember to check
if information there needs to be changed!

To make sure you understand the structure of the docs, we've setup two top level pages:
- Overview
- Getting Started

But the latter has a sub-page (Example Page) which you can reach from the left sidebar
or the navigation buttons at the bottom of the page.

## Write a blog entry

Did working on this commit make you learn something new? Write a blog entry about it at
`content/en/blog`!
