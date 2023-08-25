---
title:  <Missing>
---

This means the documentation software could not infer the contributor from the header and
source files. This is fine for external libraries (e.g. OpenFOAM functions) but we shouldn't
have many of our own entities here!

Comment your classes and functions with the following to assign two contributors:
```cpp
/// @hyde-owner contributor1
/// @hyde-owner contributor2
class Test;
```

Otherwise please use git to fetch commit authors for the file:
```bash
git shortlog -n -s -- path/to/file
```

Here is a full list of all code entities which have no contributor assigned:
