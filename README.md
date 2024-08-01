> [!WARNING]
> This repository was deprecated in favor of:
> [OpenFOAMDocsWebpages](https://github.com/FoamScience/OpenFOAMDocsWebpages)

# Template for OpenFOAM API docs using Hugo/Docsy and Hyde

This is a simple Hugo template for generating a static website using
the Docsy theme. Documentation is generated as Markdown files using Hyde
and can be changed manually while keeping the changes between consecutive docs builds.

## The recommended workflow

### Install prerequisites

- Get a recent [**extended** Hugo release](https://github.com/gohugoio/hugo/releases)
- Build [**This fork of Hyde**](https://github.com/FoamScience/hyde) and install `hyde`
  binary somewhere on your `PATH`.
- Install [**Bear**](https://github.com/rizsotto/Bear)
- Install [`jq`](https://jqlang.github.io/jq/download/) and the following Python dependencies:
  ```bash
  pip install python-frontmatter gitpython mdformat-gfm mdformat-frontmatter mdformat-footnote
  ```

### Generate the documentation

First, use this repository as a template, clone it and:

```bash
# This will generate docs for all libraries in `code` and put the results
# in `content/en/api`. Code folder can be (and better be) outside the website tree
# Note: These need to be absolute paths
./scripts/generate-docs.sh $PWD/code $PWD/content/en/api
```

The code folder has to contain at least one library with a `compile_commands.json`.
you can generate such a JSON file with `bear -- wmake libso` inside the library's folder.

You can wiki-like contents to `content/en/docs` and have a blog section at `content/en/blog`.

Go `hugo server` and open `http://localhost:1313/` in your browser to see the results.
For production runs, make sure to change the settings in `hugo.toml` to reflect your needs.
