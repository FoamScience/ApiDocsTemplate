---
title: About APIDocs
linkTitle: About
menu: {main: {weight: 10}}
---

{{% blocks/cover title="About APIDocs" image_anchor="bottom" height="auto" %}}
{{% /blocks/cover %}}

{{% blocks/lead %}}

APIDocs is a sample site using the [Docsy](https://github.com/google/docsy)
Hugo theme and [Hyde](https://github.com/adobe/hyde) to generate stunning
and actually useful documentation pages which stay up-to-date with minimal effort.

It's for the lazy lots of us who write OpenFOAM code frequently and want to document it
in a way that's actually decent to look at and browse. Reading source code files is still
better though...

Three sections are natively supported; though there is nothing holding you back of adding more:

{{% /blocks/lead %}}

{{% blocks/section %}}

# API docs for the lazy
{.text-center}

As an alternative to the more boring Doxygen (but more feature rich), Hyde can generate API docs
as Markdown files; and consecutive docs builds do not change the content you add in the markdown file.
{.text-center}

Up to C++14 syntax is supported. Inline comments are still considered as documentation but it's not
recommended to fully rely on them. It's always to keep important notes about the classes in dedicated
markdown files (naturally with Latex support).
{.text-center}

{{% /blocks/section %}}

{{% blocks/section %}}

# Wiki-like docs
{.text-center}

The same Markdown system is used also to generate pages for things like "Getting-Started" or
a "FAQ" from your markdown input.
{.text-center}

{{% /blocks/section %}}

{{% blocks/section %}}

# A Blog
{.text-center}

I usually like to keep track of how my projects evolve over time, and a DevLog is the best. By
exposing this information to the world, someone is bound to benefit from it at some point!
{.text-center}

{{% /blocks/section %}}
