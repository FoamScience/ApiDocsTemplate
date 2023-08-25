---
api_namespaces:
  - Foam
api_tags:
  - class
contributors:
  - __MISSING__
hyde:
  brief: __MISSING__
  declaration: "template <class Type>\nclass Foam::sampleBCFvPatchField;"
  defined_in_file: https://github.com/FoamScience/ApiDocsTemplate/blob/main/code/lib1/sampleBC/sampleBCFvPatchField.H
  dtor: unspecified
  fields:
    boolData_:
      annotation:
        - private
      description: __INLINED__
      inline:
        description:
          - '- Boolean for true/false, e.g. specify if flow rate is volumetric_'
      key: boolData_
      type: bool
    data_:
      annotation:
        - private
      description: __INLINED__
      inline:
        description:
          - '- Single valued Type quantity, e.g. reference pressure pRefValue_ Other
            options include vector, tensor'
      key: data_
      type: Type
    debug:
      description: __MISSING__
      key: debug
      type: int
    fieldData_:
      annotation:
        - private
      description: __INLINED__
      inline:
        description:
          - '- Field of Types, typically defined across patch faces e.g. total pressure
            p0_.  Other options include vectorField'
      key: fieldData_
      type: Field<Type>
    labelData_:
      annotation:
        - private
      description: __INLINED__
      inline:
        description:
          - '- Label, e.g. patch index, current time index'
      key: labelData_
      type: Foam::label
    scalarData_:
      annotation:
        - private
      description: __INLINED__
      inline:
        description:
          - '- Single valued scalar quantity, e.g. a coefficient'
      key: scalarData_
      type: Foam::scalar
    timeVsData_:
      annotation:
        - private
      description: __INLINED__
      inline:
        description:
          - '- Type specified as a function of time for time-varying BCs'
      key: timeVsData_
      type: autoPtr<Function1<Type>>
    typeName:
      description: __MISSING__
      key: typeName
      type: const ::Foam::word
    wordData_:
      annotation:
        - private
      description: __INLINED__
      inline:
        description:
          - '- Word entry, e.g. pName_ for name of the pressure field on database'
      key: wordData_
      type: Foam::word
  namespace:
    - Foam
  owner: __MISSING__
  tags:
    - class
layout: class
title: sampleBCFvPatchField<Type>
---
