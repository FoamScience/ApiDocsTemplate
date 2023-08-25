---
title: APIDocs
---

{{< blocks/cover title="Welcome to APIDocs: Your template for documenting OpenFOAM libs" image_anchor="top" height="full" >}}
<a class="btn btn-lg btn-primary me-3 mb-4" href="/docs/">
  Learn More <i class="fas fa-arrow-alt-circle-right ms-2"></i>
</a>
<a class="btn btn-lg btn-secondary me-3 mb-4" href="https://github.com/google/docsy-example">
  Clone <i class="fab fa-github ms-2 "></i>
</a>
{{< blocks/link-down color="info" >}}
{{< /blocks/cover >}}


{{% blocks/lead color="primary" %}}
APIDocs provides a simple Hugo template for documentation static-websites tailored specifically
to document **OpenFOAM libraries**!

What promised is that running a single script will generate an **up-to-date** documentation
of the code. You can version the docs as you version the OpenFOAM code!


Here are the main dependencies (There are few more needed utilities like
[jq](https://github.com/jqlang/jq) and  [frontmatter](https://github.com/eyeseast/python-frontmatter)):
{{% /blocks/lead %}}


{{% blocks/section color="dark" type="row" %}}
{{% blocks/feature icon="fa-lightbulb" title="Hugo" url="https://gohugo.io/" %}}
We're using [Hugo](https://gohugo.io/) to build the documentation site from Markdown files
in a blink of an eye (Or faster?)!
{{% /blocks/feature %}}


{{% blocks/feature icon="fa-lightbulb" title="Bear" url="https://github.com/rizsotto/Bear" %}}
You libraries are built with [Bear](https://github.com/rizsotto/Bear) (as in `bear -- wmake libso`)
to generate compilation databases.
{{% /blocks/feature %}}

{{% blocks/feature icon="fab fa-github" title="Hyde" url="https://github.com/adobe/hyde" %}}
[Hyde](https://github.com/adobe/hyde) picks up those database and builds the documentation for you!
Consecutive builds do not touch your content.
{{% /blocks/feature %}}

{{% /blocks/section %}}
