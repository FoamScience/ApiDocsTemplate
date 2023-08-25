---
title:  <Optional>
---

This means the documentation software could not infer the contributor from the header and
source files. This is **not** fine as we strive to document everything.

Comment your classes and functions with the following to assign a contributor:
```cpp
/// @hyde-owner contributor1
class Test;
```

Otherwise please use git to fetch commit authors for the file and blame for the
specific set of lines:
```bash
git shortlog -n -s -- path/to/file
```
