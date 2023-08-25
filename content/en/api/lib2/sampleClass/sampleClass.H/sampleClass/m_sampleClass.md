---
api_tags:
  - method
contributors:
  - elwardi
hyde:
  brief: __INLINED__
  defined_in_file: https://github.com/FoamScience/ApiDocsTemplate/blob/main/code/sampleClass/sampleClass.H
  inline:
    brief: _multiple descriptions_
    owner: elwardi
  is_ctor: true
  overloads:
    sampleClass(Foam::sampleClass &&):
      annotation:
        - defaulted
      arguments:
        - description: __OPTIONAL__
          name: unnamed-0
          type: Foam::sampleClass &&
          unnamed: true
      description: __INLINED__
      inline:
        description:
          - Default move construction
      key: sampleClass(Foam::sampleClass &&)
      signature_with_names: sampleClass(Foam::sampleClass &&)
    sampleClass(const Foam::sampleClass &):
      annotation:
        - deleted
      arguments:
        - description: __OPTIONAL__
          name: unnamed-0
          type: const Foam::sampleClass &
          unnamed: true
      description: __INLINED__
      inline:
        description:
          - Deleted default copy constructor
      key: sampleClass(const Foam::sampleClass &)
      signature_with_names: sampleClass(const Foam::sampleClass &)
    sampleClass(int):
      arguments:
        - description: __OPTIONAL__
          name: x
          type: int
      description: __INLINED__
      inline:
        description:
          - Construct from `x`
      key: sampleClass(int)
      signature_with_names: sampleClass(int x)
  owner: __INLINED__
  tags:
    - method
layout: method
title: sampleClass
---
