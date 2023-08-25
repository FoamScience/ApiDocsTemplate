---
date: 2023-08-18
title: Managing dependency software for `meshfreeFoam`
linkTitle: meshfreeFoam dependencies
description: >
  During the design phase of `meshfreeFoam`, It was obvious that I would need
  to rely on few c++ libraries. So, I came up with a workflow to manage those
  dependencies atomically and automatically, where I could get dependency updates
  effortlessly and still keep my customizations if any.
author: Mohammed Elwardi Fadeli ([@elwardi](https://www.linkedin.com/in/elwardi-fadeli))
tags:
  - meshfreeFoam
  - c++
  - dependency
  - git
---

Dependency management is always a hustle. For my PhD project, I would need to live through
this hell for around three years. Specifically, OpenFOAM libraries are dependencies for me
and that is a big for few reasons:

1. Which OpenFOAM fork to use? OpenFOAM forks from OpenCFD and Foundation are changing too
   quickly and Foam-Extend practically gets too little updates.
2. My customizations will not fit as changes upstream OpenFOAM maintainers would be intrerested
   merging; simply because they are mostly experimentation and maybe meshless-specific.
3. I only need a very small set of OpenFOAM libraries to start and I don't see a way to
   efficiently leverage the full set of libraries because most of them are optimized for FVM.

This practically applies to any library that is hard to merge my changes into and gets frequent
updates.

## Dependency management workflow

The workflow to manage my dependencies revolves around the following concepts:
- Have a central repository for all dependencies in case I change stuff in their code.
- Include that repo as a submodule/subtree in the main project.
- Customizing the dependency code should be as streamlined as possible, without losing the
  ability to pull changes from upstream repos.

### How to make OpenFOAM libs available as dependencies

There are scripts to automatize this process, but I will explain the
most important steps here:

We start by cloning the project, filtering the paths we need, then tagging the
state as `original` (You'll need [git-filter-repo](https://github.com/newren/git-filter-repo/) for this).
```bash
git clone https://develop.openfoam.com/Development/openfoam /tmp/openfoam-scratch
cd /tmp/openfoam-scratch
git filter-repo --path COPYING --path Allwmake --path bin --path etc --path src/Allwmake \
    --path src/OSspecific --path src/OpenFOAM --path src/Pstream/ \
    --path META-INFO/ --path wmake --force
```

Next, in the dependencies repo, add this as a subtree, and make a branch for `original` OpenFOAM
commits:
```bash
cd /path/to/dependencies
git subtree add --prefix meshfree-openfoam /tmp/openfoam-scrach master
git checkout -b original-openfoam
```

Switch back to master, and commit the custom changes we need:
```bash
git checkout master
git add -A
git commit -m "Update OpenFOAM compilation"
```

Updates from the original repo come in two forms:
- New change commits. These may cause conflicts with our changes, so rebasing will allow us
  to solve them.
- New libraries we want to add. These are also new commits, but we know they won't cause trouble
  since they only add files to `original`. We only have to remember to update `Allwmake` scripts
  to compile those new libraries.

Here is how to add `src/fileFormats` libraries from OpenFOAM:
```bash
# Create a new filtered repo with the new libs
rm -rf /tmp/openfoam-scratch
git clone https://develop.openfoam.com/Development/openfoam /tmp/openfoam-scratch
cd /tmp/openfoam-scratch
git filter-repo --path COPYING --path Allwmake --path bin --path etc --path src/Allwmake \
    --path src/OSspecific --path src/OpenFOAM --path src/Pstream/ \
    --path META-INFO/ --path wmake --path src/fileFormats --force
# Merge those commits into master
cd /path/to/dependencies
git checkout original-openfoam
git pull git subtree pull --prefix meshfree-openfoam/ /tmp/scratch master
git checkout master
# This merge has less chance of producing conflicts if you're just adding libs.
git merge original
```

This workflow maintains a healthy level of consistency and makes it easy to experiment
with dependency library modifications (e.g. Optimization for GPU, ..., etc) and even
changing compiler settings.
