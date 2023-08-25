---
api_namespaces:
  - Foam
api_tags:
  - function
contributors:
  - elwardi
  - another
hyde:
  brief: __INLINED__
  defined_in_file: https://github.com/FoamScience/ApiDocsTemplate/blob/main/code/functions.C
  inline:
    brief: Substract two sampleClass objects; delegates to `x` members
    owner:
      - elwardi,another
  namespace:
    - Foam
  overloads:
    Foam::sampleClass operator-(Foam::sampleClass &, Foam::sampleClass &):
      arguments:
        - description: __OPTIONAL__
          name: a
          type: Foam::sampleClass &
        - description: __OPTIONAL__
          name: b
          type: Foam::sampleClass &
      description: __OPTIONAL__
      inline:
        brief: Substract two sampleClass objects; delegates to `x` members
        owner: elwardi,another
      key: Foam::sampleClass operator-(Foam::sampleClass &, Foam::sampleClass &)
      return: __OPTIONAL__
      signature_with_names: Foam::sampleClass operator-(Foam::sampleClass & a, Foam::sampleClass
        & b)
  owner: __INLINED__
  tags:
    - function
layout: function
title: operator-
---
