---
api_tags:
  - method
contributors:
  - elwardi
hyde:
  brief: __INLINED__
  defined_in_file: https://github.com/FoamScience/ApiDocsTemplate/blob/main/code/lib2/sampleClass/sampleClass.H
  inline:
    brief: _multiple descriptions_
    owner: elwardi
  overloads:
    Foam::sampleClass & operator=(Foam::sampleClass &&):
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
          - Default move assignment
      key: Foam::sampleClass & operator=(Foam::sampleClass &&)
      return: __OPTIONAL__
      signature_with_names: Foam::sampleClass & operator=(Foam::sampleClass &&)
    Foam::sampleClass & operator=(const Foam::sampleClass &):
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
          - Deleted default copyassignment
      key: Foam::sampleClass & operator=(const Foam::sampleClass &)
      return: __OPTIONAL__
      signature_with_names: Foam::sampleClass & operator=(const Foam::sampleClass
        &)
  owner: __INLINED__
  tags:
    - method
layout: method
title: operator=
---
